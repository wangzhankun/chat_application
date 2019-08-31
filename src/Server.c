/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
 * @Date: 2019-08-30 21:22:06 +0800
 * @LastEditTime: 2019-08-31 14:30:01 +0800
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"


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


/**
 * @Author: 王占坤
 * @Description: 
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void initialzeSocketaddr(struct sockaddr* addr)
{
    
}



/**
 * @Author: 王占坤
 * @Description: 创建socket句柄
 * @Param: 
 *      int domain   socket的网络类型
 *      int type    选择tcp或者udp模式
 *      int protocol   一般设置为0即可
 * @Return: socketfd  创建的socket句柄
 * @Throw: 
 */
socketfd createSocket(int domain, int type, int protocol)
{
    socketfd skf_socketfd = socket(domain, type, protocol);
    if(skf_socketfd == -1)//执行失败
    {
        perror("socket");
        exit(1);
    }
    else
        return skf_socketfd;
}

/**
 * @Author: 王占坤
 * @Description: 将socket绑定至指定端口
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void bindSocketWithPort(socketfd skf_socketfd, const struct sockaddr* addr_sockaddr, int addrlen)
{
    int res = bind(skf_socketfd, addr_sockaddr, addrlen);
    if(res != 0)//失败
    {
        perror("bind");
        exit(1);
    }
}



#ifdef TEST

int main(int argc, char *argv[])
{
    struct sockaddr_in addr_server_sockaddr;

    initialzeSocketaddr(addr_server_sockaddr);

    socketfd server_socket_server_socketfd, client_socket_server_socketfd;
    
    server_socket_server_socketfd = createSocket(AF_INET, SOCKET_TYPE, SOCKET_PROTOCOL);
    // printf("hello world\n");
    
    bindSocketWithPort(server_socket_server_socketfd, (struct sockaddr*)&addr_server_sockaddr, sizeof(addr_server_sockaddr));

}

#endif