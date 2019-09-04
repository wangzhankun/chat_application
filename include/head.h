/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
<<<<<<< HEAD
 * @Date: 2019-08-30 15:08:30 +0800
 * @LastEditTime: 2019-09-03 21:25:09 +0800
=======
 * @Date: 2019-08-31 19:44:55 -0700
 * @LastEditTime: 2019-09-04 14:42:49 +0800
>>>>>>> upstream/gtk
 * @LastEditors: 
 * @Description: 这里是主头文件，包含了所有的库文件，全局变量声明，结构体声明等
 */
#ifndef __HEAD_H__
#define __HEAD_H__
///////////////include库文件区/////////////
#include "config.h"//这里为了防止遗忘，确保把config文件链接到所有文件中
#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
<<<<<<< HEAD
#include <gtk/gtk.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>   
=======
#include <gdk/gdkkeysyms.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
>>>>>>> upstream/gtk


/////////////define区////////////////////
#define MAX_QUEUE_SIZE 500




//////////////typedef区/////////////////
typedef int socketfd;


typedef signed char INT8;
typedef unsigned char UINT8;
typedef int INT16;
typedef unsigned int UINT16;
typedef long int INT32;
typedef unsigned long int UINT32;
typedef long long int INT64;
typedef unsigned long long int UINT64;

typedef float FLOAT32;
typedef double FLOAT64;

typedef unsigned char BOOLEAN;
typedef unsigned char boolean;
typedef unsigned char bool;

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


#endif


