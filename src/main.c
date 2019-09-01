/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-01 01:29:46 -0700
 * @LastEditors: 
 * @Description: 
 */


#include "head.h"
#include "callbacks.h"
#include "interface.h"
int main (int argc , gchar* argv[])
{
    GtkWidget * window ;
    gtk_init(&argc,&argv);
    window = create_window();
    g_signal_connect(G_OBJECT(window),"delete_event",
    G_CALLBACK(on_window_delete_event),NULL);
    gtk_widget_show(window);
    gtk_main();
    return FALSE;
}








