/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-02 03:38:20 -0700
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
    gtk_init(&argc, &argv);
    //好友列表
    TalkWindow = CreateFriendWindow();
    //TalkWindow = CreateTalkWindow();

    g_signal_connect(G_OBJECT(TalkWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event), NULL);
    gtk_widget_show(TalkWindow);
    gtk_main();
    return FALSE;
}
// static GtkWidget *fixed;
// //自由布局控件
// static GtkWidget *button1; //按钮一
// static GtkWidget *button2; //按钮二
// //第二个线程要运行的函数
// void our_thread2(GtkWidget *button)
// {
//     gint x, y, towards;
//     x = 40;
//     y = 40;
//     towards = 1;
//     for (;;)
//     {
//         g_usleep(4);
//         gdk_threads_enter();
//         gtk_fixed_move(GTK_FIXED(fixed), button, x, y);
//         switch (towards)
//         {
//         case 1: //向右
//             x = x + 10;
//             if (x == 250)
//                 towards = 2;
//             break;
//         case 2: //向下
//             y = y + 10;
//             if (y == 250)
//                 towards = 3;
//             break;
//         case 3: //向左
//             x = x - 10;
//             if (x == 40)
//                 towards = 4;
//             break;
//         case 4:
//             //向上
//             y = y - 10;
//             if (y == 40)
//                 towards = 1;
//             break;
//         }
//         gdk_threads_leave();
//     }
// }
// //第二个线程要运行的函数
// void our_thread1(GtkWidget *button)
// {
//     gint i, j, forward;
//     i = 10;
//     j = 10;
//     forward = 1;
//     for (;;)
//     {
//         g_usleep(1);
//         gdk_threads_enter();
//         gtk_fixed_move(GTK_FIXED(fixed), button, i, j);
//         switch (forward)
//         {
//         case 1: //向右
//             i = i + 10;
//             if (i == 290)
//                 forward = 2;
//             break;
//         case 2: //向下
//             j = j + 10;
//             if (j == 290)
//                 forward = 3;
//             break;
//         case 3: //向左
//             i = i - 10;
//             if (i == 10)
//                 forward = 4;
//             break;
//         case 4:
//             //向上
//             j = j - 10;
//             if (j == 10)
//                 forward = 1;
//             break;
//         }
//         gdk_threads_leave();
//     }
// }
// void on_begin(GtkWidget *button, gpointer data)
// {
//     gtk_widget_set_sensitive(button, FALSE);
//     g_thread_create(our_thread1, button1, FALSE, NULL); //创建线程一
//     g_thread_create(our_thread2, button2, FALSE, NULL); //创建线程二
// }
// int main(int argc, char *argv[])
// {
//     GtkWidget *window, *view;
//     GtkWidget *vbox, *button, *label;
//     if (!g_thread_supported())
//         g_thread_init(NULL); //初始线程
//     gtk_init(&argc, &argv);
//     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(window), "线程的运用");
//     g_signal_connect(G_OBJECT(window), "delete_event",
//                      G_CALLBACK(gtk_main_quit), NULL);
//     gtk_container_set_border_width(GTK_CONTAINER(window), 10);
//     vbox = gtk_vbox_new(FALSE, 0);
//     gtk_container_add(GTK_CONTAINER(window), vbox);
//     label = gtk_label_new("注意下面的按钮的运动:");
//     gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);
//     view = gtk_viewport_new(NULL, NULL);
//     gtk_box_pack_start(GTK_BOX(vbox), view, FALSE, FALSE, 5);
//     fixed = gtk_fixed_new();
//     gtk_widget_set_usize(fixed, 330, 330);
//     gtk_container_add(GTK_CONTAINER(view), fixed);
//     button1 = gtk_button_new_with_label("1");
//     button2 = gtk_button_new_with_label("2");
//     gtk_fixed_put(GTK_FIXED(fixed), button1, 10, 10);
//     gtk_fixed_put(GTK_FIXED(fixed), button2, 40, 40);
//     button = gtk_button_new_with_label("开始");
//     gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 5);
//     g_signal_connect(G_OBJECT(button), "clicked",
//                      G_CALLBACK(on_begin), NULL);
//     gtk_widget_show_all(window);
//     gdk_threads_enter();
//     gtk_main();
//     gdk_threads_leave();
//     return FALSE;
// }
