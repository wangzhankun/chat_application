/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2019-08-29 23:38:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2019-09-02 03:29:09 -0700
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
