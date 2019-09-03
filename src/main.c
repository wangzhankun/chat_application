/*
 * @Copyright: CS of BIT
 * @Author: hhz
 * @File name: 
 * @Version: 
 * @Date: 2019-09-02 03:42:58 -0700
 * @LastEditTime: 2019-09-02 03:43:08 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "GTKCreateLoading.h"
#include "Gtkfriendlist.h"
int main(int argc, char *argv[])
{
    GtkWidget *LoadingWindow;
    gtk_init(&argc, &argv);
    LoadingWindow = CreateLoading();
    g_signal_connect(G_OBJECT(LoadingWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(LoadingWindow);

    GtkWidget *ListWindow;
    ListWindow = CreateFriendlist();
    g_signal_connect(G_OBJECT(ListWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(ListWindow);

    gtk_main();
    return FALSE;
}
