/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-09-03 06:20:30 -0700
 * @LastEditTime: 2019-09-03 06:20:31 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "interface.h"
#include "callbacks.h"
/**
 * @Author: 王可欣
 * @Description: 接收信息的线程
 * @Param: 
 * @Return: 
 */
void recv_thread() {
	// int numbytes;
	// while(1) {
	// 	printf("recv serverfd = %d\n", serverfd);
	// 	memset(buffer, 0, BUFFER_SIZE);
	// 	numbytes = recv(serverfd, buffer, BUFFER_SIZE, 0);
	// 	printf("recv over, serverfd = %d, numbytes = %d\n", serverfd);
	// 	if(numbytes == 0){
	// 		printf("server offline.\n");
	// 		exit(1);
	// 	}
	// 	if(numbytes == -1){
	// 		perror("error receiving message\n");
	// 		exit(1);
	// 	}
	// 	printf("recv judge over, serverfd = %d\n", serverfd);
	// 	//buffer[numbytes] = '\0';
    //     	printf("received message from server: \"%s\"\n", buffer);
	// 	printf("before handle message, serverfd = %d\n", serverfd);
	// 	//gdk_threads_enter();
    //     handle_message(buffer);
	// 	//gdk_threads_leave(); 
	// }
}