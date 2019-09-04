/*
 * @Copyright: CS of BIT
 * @Author: hhz
 * @File name: 
 * @Version: 
 * @Date: 2019-09-02 03:42:58 -0700
 * @LastEditTime: 2019-09-03 20:27:00 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "mainprogram.h"
#include "callbacks.h"
#include "interface.h"
int main(int argc, char *argv[])
{

    //创建一个读取服务器信息的子线程
    g_thread_create((GThreadFunc)startListen, NULL, FALSE, NULL);

    Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Array = ( void**)malloc(sizeof(void*) * MAX_QUEUE_SIZE);
    Q->Capacity =MAX_QUEUE_SIZE;
    MakeEmpty(Q);

    gtk_init(&argc, &argv);
    LoadingWindow = CreateLoading();
     g_signal_connect(G_OBJECT(LoadingWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event), NULL);
    gtk_widget_show(LoadingWindow);
    
    //自动更新的线程

    
    gdk_threads_enter();
    gtk_main();
    gdk_threads_leave();
    return FALSE;
}
