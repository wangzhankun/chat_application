/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-04 05:31:32 -0700
 * @LastEditors: 
 * @Description: 
 */

#include "head.h"
#include "callbacks.h"
#include "interface.h"
#include "mainprogram.h"

int main(int argc, gchar *argv[])
{
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Array = ( void**)malloc(sizeof(void*) * MAX_QUEUE_SIZE);
    Q->Capacity =MAX_QUEUE_SIZE;
    MakeEmpty(Q);

    gtk_init(&argc, &argv);
    //好友列表
    //FriendWindow = CreateMainWindow();
    LoadingWindow = CreateLoading();
    g_signal_connect(G_OBJECT(LoadingWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event), NULL);
    gtk_widget_show(LoadingWindow);
    //创建一个读取服务器信息的子线程
    //g_thread_create((GThreadFunc)recv_thread, NULL, FALSE, NULL);
    //自动更新的线程

    
    gdk_threads_enter();
    gtk_main();
    gdk_threads_leave();
    return FALSE;
}
