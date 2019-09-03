/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-03 05:44:42 -0700
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
   // g_thread_create((GThreadFunc)recv_thread, NULL, FALSE, NULL); 
    gtk_main();
    return FALSE;
}
// static gint //弹出菜单回调函数
// my_popup_handler(GtkWidget *widget, GdkEvent *event)
// {
//     GtkMenu *menu;                //菜单
//     GdkEventButton *event_button; //要弹出菜单的对象
//     g_return_val_if_fail(widget != NULL, FALSE);
//     g_return_val_if_fail(GTK_IS_MENU(widget), FALSE);
//     g_return_val_if_fail(event != NULL, FALSE);
//     menu = GTK_MENU(widget); //转换为菜单
//     if (event->type == GDK_BUTTON_PRESS)
//     //是此事件
//     {
//         event_button = (GdkEventButton *)event;
//         if (event_button->button == 3) //判断是否为右/三键
//         {                              //执行操作
//             gtk_menu_popup(menu, NULL, NULL, NULL, NULL,
//                            event_button->button, event_button->time);
//             return TRUE;
//         }
//     }
//     return FALSE;
// }
// int main(int argc, char *argv[])
// {
//     GtkWidget *window;
//     GtkWidget *box;
//     GtkWidget *button;
//     GtkWidget *menubar;
//     GtkWidget *menu;
//     GtkWidget *editmenu;
//     GtkWidget *helpmenu;
//     GtkWidget *rootmenu;
//     GtkWidget *menuitem;
//     GtkAccelGroup *accel_group;
//     gtk_init(&argc, &argv);
//     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(window), "弹出式菜单");
//     g_signal_connect(G_OBJECT(window), "destroy",
//                      G_CALLBACK(gtk_main_quit), NULL);

//     accel_group = gtk_accel_group_new();
//     gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

//     box = gtk_vbox_new(FALSE, 0);
//     gtk_container_add(GTK_CONTAINER(window), box);
//     menu = gtk_menu_new(); //文件菜单
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     gtk_widget_show(menuitem);
//     menuitem = gtk_separator_menu_item_new();
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
//     rootmenu = gtk_menu_item_new_with_label(" 文件 ");
//     gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), menu);
//     menubar = gtk_menu_bar_new();
//     gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);
//     rootmenu = gtk_menu_item_new_with_label(" 编辑 ");
//     editmenu = gtk_menu_new(); //编辑菜单
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), menuitem);
//     gtk_widget_show(rootmenu);
//     gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), editmenu);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);
//     rootmenu = gtk_menu_item_new_with_label(" 帮助 ");
//     helpmenu = gtk_menu_new();
//     menuitem = gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP, accel_group);
//     gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
//     menuitem = gtk_menu_item_new_with_label(" 关于... ");
//     gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), menuitem);
//     gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu), helpmenu);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menubar), rootmenu);
//     gtk_box_pack_start(GTK_BOX(box), menubar, FALSE, FALSE, 5);
//     //关键---弹出式菜单设计
//     button = gtk_button_new_with_label("单击右键弹出菜单");
//     g_signal_connect_swapped(GTK_OBJECT(button),
//                              "button_press_event",
//                              G_CALLBACK(my_popup_handler), GTK_OBJECT(menu));
//     gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 5);
//     gtk_widget_show_all(window);
//     gtk_main();
//     return FALSE;
// }