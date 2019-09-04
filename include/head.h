/*
 * @Copyright: CS of BIT
 * @Author: 王占坤
 * @File name: 
 * @Version: 
 * @Date: 2019-08-30 15:08:30 +0800
 * @LastEditTime: 2019-09-03 02:34:24 -0700
 * @LastEditors: 
 * @Description: 这里是主头文件，包含了所有的库文件，全局变量声明，结构体声明等
 */
#ifndef __HEAD_H__
#define __HEAD_H__
///////////////include库文件区/////////////
#include "config.h"//这里为了防止遗忘，确保把config文件链接到所有文件中
#include <cjson/cJSON.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>   


/////////////define区////////////////////





//////////////typedef区/////////////////
typedef int socketfd;




/////////////全局结构体定义区//////////




///////////////全局变量声明区/////////////


#endif