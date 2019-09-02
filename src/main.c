/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2019-08-29 23:38:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2019-09-01 19:45:52 -0700
 */
#include "head.h"
#include "GTKCreateLoading.h"

int main(int argc, char *argv[])
{
    GtkWidget *LoadingWindow;
    gtk_init(&argc, &argv);
    LoadingWindow = CreateLoading();
    g_signal_connect(G_OBJECT(LoadingWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(LoadingWindow);
    gtk_main();
    return FALSE;
}