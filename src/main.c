/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-02 09:52:14 -0700
 * @LastEditors: 
 * @Description: 
 */

#include "head.h"
#include "callbacks.h"
#include "interface.h"

int main(int argc, gchar *argv[])
{
    GtkWidget *TalkWindow;
    GtkWidget *FriendWindow;
    GtkWidget *LoadingWindow;
    

    gtk_init(&argc, &argv);
    //好友列表
    FriendWindow = CreateFriendWindow();
    //LoadingWindow = GTKcreateloading();
    g_signal_connect(G_OBJECT(FriendWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event ), NULL);
    gtk_widget_show(FriendWindow);
    gtk_main();

    return FALSE;
}
