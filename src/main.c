/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-03 07:42:22 -0700
 * @LastEditors: 
 * @Description: 
 */

#include "head.h"
#include "callbacks.h"
#include "interface.h"
#include "mainprogram.h"

int main(int argc, gchar *argv[])
{
    gtk_init(&argc, &argv);
    //好友列表
    //FriendWindow = CreateMainWindow();
    LoadingWindow = CreateLoading();
    g_signal_connect(G_OBJECT(LoadingWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event), NULL);
    gtk_widget_show(LoadingWindow);
    //创建一个读取服务器信息的子线程
    // g_thread_create((GThreadFunc)recv_thread, NULL, FALSE, NULL);
    gtk_main();
    return FALSE;
}

// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #define OURPORT 8088
// //定义端口号
// gint sd;
// //套接字句柄
// struct sockaddr_in s_in;
// //套接字数据结构
// gchar username[64];
// //用户名
// gchar buf[1024];
// //写缓冲区
// gchar get_buf[1048];
// //读缓冲区
// gboolean isconnected = FALSE; //定义逻辑值表示是否连接
// static GtkWidget *text;
// static GtkTextBuffer *buffer; //显示对话内容的文本显示缓冲区
// static GtkWidget *message_entry;
// //显示输入消息的单行录入控件
// static GtkWidget *name_entry;
// //输入用户名的单行录入控件
// static GtkWidget *login_button;
// //登录按钮

// //线程要执行的函数,读取来自服务器的数据
// void get_message(void)
// {
//     GtkTextIter iter;
//     gchar get_buf[1024];
//     gchar buf[1024];
//     while (read(sd, buf, 1024) != -1) //只要读取数据成功就循环执行
//     {
//         sprintf(get_buf, "%s", buf);
//         gdk_threads_enter();
//         //进入
//         gtk_text_buffer_get_end_iter(buffer, &iter);
//         gtk_text_buffer_insert(buffer, &iter, get_buf, -1); //显示读取的数据
//         gdk_threads_leave();
//         //离开
//     }
// }

// void on_destroy(GtkWidget *widget, GdkEvent *event, gpointer data)
// {
//     //当前关闭登录窗口时执行
//     sprintf(username, "guest");
//     if (do_connect() == TRUE)
//     {
//         gtk_widget_set_sensitive(login_button, FALSE);
//         g_thread_create((GThreadFunc)get_message, NULL, FALSE, NULL);
//     }
//     gtk_widget_destroy(widget);
// }

// void on_button_clicked(GtkButton *button, gpointer data)
// {
//     //当点击登录窗口的登录按钮时执行
//     const gchar *name;
//     name = gtk_entry_get_text(GTK_ENTRY(name_entry));
//     sprintf(username, "%s", name);
//     if (do_connect())
//     {
//         gtk_widget_set_sensitive(login_button, FALSE);
//         g_thread_create((GThreadFunc)get_message, NULL, FALSE, NULL);
//     }
//     gtk_widget_destroy(data);
// }

// void create_win(void)
// {
//     //创建登录窗口
//     GtkWidget *win, *vbox;
//     GtkWidget *button;
//     win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(win), "输入用户名");
//     gtk_container_set_border_width(GTK_CONTAINER(win), 10);
//     g_signal_connect(G_OBJECT(win), "delete_event",
//                      G_CALLBACK(on_destroy), NULL);
//     gtk_window_set_modal(GTK_WINDOW(win), TRUE);
//     gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
//     vbox = gtk_vbox_new(FALSE, 0);
//     gtk_container_add(GTK_CONTAINER(win), vbox);
//     name_entry = gtk_entry_new();
//     gtk_box_pack_start(GTK_BOX(vbox), name_entry, TRUE, TRUE, 5);
//     button = gtk_button_new_from_stock(GTK_STOCK_OK);
//     g_signal_connect(G_OBJECT(button), "clicked",
//                      G_CALLBACK(on_button_clicked), win);
//     gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 5);
//     gtk_widget_show_all(win);
// }

// gboolean do_connect(void) //连接多人聊天服务器
// {
//     GtkTextIter iter;
//     gint slen;
//     sd = socket(AF_INET, SOCK_STREAM, 0); //创建
//     if (sd < 0)
//     {
//         gtk_text_buffer_get_end_iter(buffer, &iter);
//         gtk_text_buffer_insert(buffer, &iter, "打开套接字时出错!\n", -1);
//         return FALSE;
//     }
//     s_in.sin_family = AF_INET;
//     s_in.sin_port = OURPORT;
//     slen = sizeof(s_in);
//     if (connect(sd, &s_in, slen) < 0) //连接
//     {
//         gtk_text_buffer_get_end_iter(buffer, &iter);
//         gtk_text_buffer_insert(buffer, &iter, "连接服务器时出错!\n", -1);
//         return FALSE;
//     }
//     else
//     {
//         gtk_text_buffer_get_end_iter(buffer, &iter);
//         gtk_text_buffer_insert(buffer, &iter, username, -1);
//         gtk_text_buffer_get_end_iter(buffer, &iter);
//         gtk_text_buffer_insert(buffer, &iter, "\n成功与服务器连接....\n", -1);
//         //
//         write(sd, username, 64); //向服务器发送用户名
//         //
//         isconnected = TRUE;
//         return TRUE;
//     }
// }

// void on_send(GtkButton *button, gpointer data) 
// {
//         //向服务器发送数据
//         const char *message;
//     if (isconnected == FALSE)
//         return;
//     message = gtk_entry_get_text(GTK_ENTRY(message_entry));
//     sprintf(buf, "%s\n", message);
//     write(sd, buf, 1024); //发送
//     gtk_entry_set_text(GTK_ENTRY(message_entry), "");
//     //清除单行录中的文字
// }
// void on_login(GtkWidget *button, gpointer data)
// {
//     //点击登录按钮时执行
//     create_win();
// }
// voidon_delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
// {
//     //关闭主窗口时执行
//     close(sd); //关闭
//     gtk_main_quit();
// }
// int main(int argc, char *argv[])
// {
//     GtkWidget *window;
//     GtkWidget *vbox, *hbox, *button, *label, *view;
//     if (!g_thread_supported())
//         g_thread_init(NULL);
//     gtk_init(&argc, &argv);
//     //初始线程
//     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(window), "客户端");
//     g_signal_connect(G_OBJECT(window), "delete_event",
//                      G_CALLBACK(on_window_delete_event), NULL);
//     gtk_container_set_border_width(GTK_CONTAINER(window), 10);
//     vbox = gtk_vbox_new(FALSE, 0);
//     gtk_container_add(GTK_CONTAINER(window), vbox);
//     hbox = gtk_hbox_new(FALSE, 0);
//     gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
//     label = gtk_label_new("点击登录按钮连接服务器");
//     gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 5);
//     login_button = gtk_button_new_with_label("登录");
//     gtk_box_pack_start(GTK_BOX(hbox), login_button, FALSE, FALSE, 5);
//     g_signal_connect(G_OBJECT(login_button), "clicked",
//                      G_CALLBACK(on_login), NULL);
//     view = gtk_scrolled_window_new(NULL, NULL);
//     gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(view), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
//     text = gtk_text_view_new();
//     gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 5);
//     gtk_container_add(GTK_CONTAINER(view), text);
//     buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
//     hbox = gtk_hbox_new(FALSE, 0);
//     gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
//     label = gtk_label_new("输入消息:");
//     gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 5);
//     message_entry = gtk_entry_new();
//     gtk_box_pack_start(GTK_BOX(hbox), message_entry, FALSE, FALSE, 5);
//     button = gtk_button_new_with_label("发送");
//     gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 5);
//     g_signal_connect(G_OBJECT(button), "clicked",
//                      G_CALLBACK(on_send), NULL);
//     gtk_widget_show_all(window);
//     gdk_threads_enter(); //
//     gtk_main();
//     gdk_threads_leave(); //
//     return FALSE;
// }