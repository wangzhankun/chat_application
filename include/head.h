/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:44:55 -0700
 * @LastEditTime: 2019-09-03 18:40:37 -0700
 * @LastEditors: 
 * @Description: 
 */
///////////////include库文件区/////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <gdk/gdkkeysyms.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


/////////////define区////////////////////
#define MAX_QUEUE_SIZE 500




//////////////typedef区/////////////////
typedef int socketfd;
//从队列中读取服务器发送消息
typedef struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    void **Array;
}*Queue;


/////////////全局结构体定义区//////////



///////////////全局变量声明区/////////////
GtkWidget *FriendWindow;
GtkWidget *LoadingWindow;
Queue Q;
