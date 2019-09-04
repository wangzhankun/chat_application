/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-09-03 06:20:30 -0700
 * @LastEditTime: 2019-09-03 07:42:10 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "interface.h"
#include "callbacks.h"

/**
 * @Author: 王可欣
 * @Description: 判断是否链接
 * @Param: 
 * @Return: 
 */
gboolean do_connect(void) //连接多人聊天服务器
{
    // GtkTextIter iter;
    // gint slen;
    // sd = socket(AF_INET, SOCK_STREAM, 0); //创建
    // if (sd < 0)
    // {
    //     gtk_text_buffer_get_end_iter(buffer, &iter);
    //     gtk_text_buffer_insert(buffer, &iter, "打开套接字时出错!\n", -1);
    //     return FALSE;
    // }
    // s_in.sin_family = AF_INET;
    // s_in.sin_port = OURPORT;
    // slen = sizeof(s_in);
    // if (connect(sd, &s_in, slen) < 0) //连接
    // {
    //     gtk_text_buffer_get_end_iter(buffer, &iter);
    //     gtk_text_buffer_insert(buffer, &iter, "连接服务器时出错!\n", -1);
    //     return FALSE;
    // }
    // else
    // {
    //     gtk_text_buffer_get_end_iter(buffer, &iter);
    //     gtk_text_buffer_insert(buffer, &iter, username, -1);
    //     gtk_text_buffer_get_end_iter(buffer, &iter);
    //     gtk_text_buffer_insert(buffer, &iter, "\n成功与服务器连接....\n", -1);
    //     //
    //     write(sd, username, 64); //向服务器发送用户名
    //     //
    //     isconnected = TRUE;
    //     return TRUE;
    // }
}

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