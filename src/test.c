/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 20:20:01 +0800
 * @LastEditTime: 2019-08-31 23:19:21 +0800
 * @LastEditors: 
 * @Description: 
 */
/* File Name: server.c */
#include "head.h"

#define DEFAULT_PORT 8000
#define MAXLINE 4096

socketfd createSocket()
{
    socketfd skf = socket(AF_INET, SOCK_STREAM, 0);
    return skf;
}

/**
 * @Author: 王占坤
 * @Description: 初始化地址
 * @Param: struct sockaddr_in* addr  待初始化的地址
 * @Param：in_addr_t ip_addr, ip地址,NULL代表自动获取ip
 * @Param: int port， 端口号
 * @Return: void
 * @Throw: 
 */
void initialzeSocketaddr(struct sockaddr_in *addr, char *ip_addr, int port)
{
    memset(addr, 0, sizeof(addr));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    if (ip_addr == NULL)
        addr->sin_addr.s_addr = htonl(INADDR_ANY);
    else
        addr->sin_addr.s_addr = htonl("ip_addr");
}

/**
 * @Author: 王占坤
 * @Description: 将socket绑定至指定端口
 * @Param: socketfd* skf_socketfd 待被绑定地址的socket句柄
 * @Param：const struct sockaddr* addr_sockaddr被绑定的地址
 * @Param：int addrlen 地址长度
 * @Return: void
 * @Throw: 
 */
void bindSocketWithPort(socketfd *skf_socketfd, struct sockaddr *addr_sockaddr, int addrlen)
{
    int res = bind(*skf_socketfd, addr_sockaddr, addrlen);
    if (res == -1) //失败
    {
        perror("bind");
        exit(1);
    }
}

/**
 * @Author: 王占坤
 * @Description: 对需要进行监听的socket开启监听
 * @Param: socketfd& skf, 需要进行监听的socket
 * @Param：int num, 最大监听数量
 * @Return: void
 * @Throw: 
 */
void createListenList(socketfd *skf, int num)
{
    int res = listen(*skf, num);
    if (res == -1) //执行失败
    {
        perror("listen");
        exit(1);
    }
}

void acceptConnection(socketfd *cli_skf, socketfd *ser_sfk, struct sockaddr *addr, socklen_t* len_addr)
{
    //判断是否连接如果可以连接返回新建的
    *cli_skf = accept(*ser_sfk, addr, len_addr);
    if (*cli_skf == -1)
    {
        printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
        exit(1);
    }
}

void receiveMSG(socketfd *client_socket, char *buff, size_t max_words, int flag)
{
    int num_of_reading_words = recv(*client_socket, buff, max_words, flag);
    if(num_of_reading_words == -1)//失败
    {
        printf("receive message error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }
    buff[num_of_reading_words] = 0;
}

int main(int argc, char **argv)
{
    int socket_fd, connect_fd;
    struct sockaddr_in servaddr;
    char buff[4096];
    int n;
    socket_fd = createSocket();
    //初始化Socket
    /*
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }
    //*/

    initialzeSocketaddr(&servaddr, NULL, DEFAULT_PORT);

    bindSocketWithPort(&socket_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    createListenList(&socket_fd, 10);

    printf("======waiting for client's request======\n");
    while (1)
    {
        acceptConnection(&connect_fd, &socket_fd, (struct sockaddr *)NULL, NULL);
        /*
        //阻塞直到有客户端连接，不然多浪费CPU资源。
        if ((connect_fd = accept(socket_fd, (struct sockaddr *)NULL, NULL)) == -1)
        {
            printf("accept socket error: %s(errno: %d)", strerror(errno), errno);
            continue;
        }
        //*/
        //接受客户端传过来的数据
        receiveMSG(&connect_fd, buff, MAXLINE, 0);
        // n = recv(connect_fd, buff, MAXLINE, 0);


        //向客户端发送回应数据
        if (!fork())
        { /*紫禁城*/
            if (send(connect_fd, "Hello,you are connected!\n", 26, 0) == -1)
                perror("send error");
            close(connect_fd);
            exit(0);
        }

        
        printf("recv msg from client: %s\n", buff);
        close(connect_fd);
    }
    close(socket_fd);
}