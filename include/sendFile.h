/*
 * @Copyright: CSDepartment,BIT
 * @Author: Tian Yuhang
 * @File name: 
 * @Version: 
 * @Date: 2019-09-05 00:43:22 +0800
 * @LastEditTime: 2019-09-05 05:19:43 +0800
 * @LastEditors: 
 * @Description: 
 */
#ifndef _SENDFILE_H_
#define _SENDFILE_H_
#include "head.h"
void Rec_File_From_Client(int Fd_of_Send);
void Send_File_To_Server(int Client_Socket_Fd);
void Send_File_To_Client(int Fd_of_Rec,char Name[]);
void Rec_File_From_Server(int Client_Socket_Fd);
#endif