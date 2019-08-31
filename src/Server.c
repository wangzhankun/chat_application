/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
 * @Date: 2019-08-30 21:22:06 +0800
 * @LastEditTime: 2019-08-31 23:22:43 +0800
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"

#define PORT 8000
#define TEST
#define UDP
// #define TCP
#define SOCKET_PROTOCOL 0

#ifdef UDP
#define SOCKET_TYPE SOCK_DGRAM
#endif

#ifdef TCP
#define SOCKET_TYPE SOCK_STREAM
#endif

socketfd createSocket(int domain, int type, int protocol)
{
    socketfd skf = socket(AF_INET, SOCK_STREAM, 0);
    if(skf == -1)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(1);
    }
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
void createListen(socketfd *skf, int num)
{
    int res = listen(*skf, num);
    if (res == -1) //执行失败
    {
        perror("listen");
        exit(1);
    }
}


void acceptConnection(socketfd* cli_skf, socketfd* ser_sfk, struct sockaddr* addr, socklen_t* len_addr)
{
    //判断是否连接如果可以连接返回新建的
    *cli_skf = accept(*ser_sfk, addr, len_addr);
    if(*cli_skf == -1)
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
 

 void writeBack(socketfd *cli_skf)
 {
     if(!fork())
     {
         int res = send(*cli_skf, "Hello, you are connected!\n", 26, 0);
         if(res == -1)
         {
              printf("write back error: %s(errno: %d)", strerror(errno), errno);
              exit(0);
         }
     }
 }



#ifdef TEST

int main(int argc, char *argv[])
{
    char buff[1024];
    struct sockaddr_in addr;

    initialzeSocketaddr(&addr, NULL, PORT);

    socketfd server_socket, client_socket;

    server_socket = createSocket(AF_INET, SOCK_STREAM, 0);
    /*
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }
//*/
    bindSocketWithPort(&server_socket, (struct sockaddr *)&addr, sizeof(addr));

    // printf("%d\n", listen(server_socket, 5));
    createListen(&server_socket, 5);

    acceptConnection(&client_socket, &server_socket, (struct sockaddr*)NULL, NULL);

    receiveMSG(&client_socket, buff, 100, 0);

    printf("%s\n",buff);
    writeBack(&client_socket);

    close(client_socket);

    close(server_socket);
    // printf("hello world\n");

    return 0;
}

#endif