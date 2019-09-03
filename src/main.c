/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-03 02:29:12 -0700
 * @LastEditors: 
 * @Description: 
 */

#include "head.h"
#include "callbacks.h"
#include "interface.h"

int main(int argc, gchar *argv[])
{
    gtk_init(&argc, &argv);
    //好友列表
    //FriendWindow = CreateMainWindow();
    LoadingWindow = CreateLoading();
    g_signal_connect(G_OBJECT(LoadingWindow), "delete_event",
                     G_CALLBACK(on_window_delete_event), NULL);
    gtk_widget_show(LoadingWindow);
    gtk_main();

    return FALSE;
}
// #include <gtk/gtk.h>
// #include <gdk/gdkkeysyms.h>
// #include "ouritem.h"
// //定义枚举类型，说明信号的名称和次序
// enum {
//     OURITEM_OK_SIGNAL,
//     LAST_SIGNAL
// };
// static gint ouritem_signals[LAST_SIGNAL] = { 0 };
// static void our_item_init(OurItem *ouritem);
// static void our_item_class_init(OurItemClass *ouritemclass);
// static void enter_ok(void);
// void    on_key_release(GtkWidget *entry, GdkEventKey *event, gpointer data);
// //注册自定义控件
// GtkType our_item_get_type(void)
// {
//     static GtkType our_item_type = 0;
//     if(!our_item_type)
//     {
//         GtkTypeInfo our_item_info = {
//             "OurItem",  //控件名
//             sizeof(OurItem),    //控件实例的尺寸
//             sizeof(OurItemClass),   //控件类的尺寸
//             (GtkClassInitFunc)our_item_class_init,  //控件类初始化函数
//             our_item_init,    //控件实例初始化函数
//             NULL, //
//             NULL //
//         };
//         our_item_type = gtk_type_unique(GTK_TYPE_HBOX, &our_item_info);//注册此控件
//     }
//     return our_item_type;
// }
// //初始化实例结构
// static void our_item_init(OurItem *ouritem)
// {
//     ouritem->label = gtk_label_new(NULL);
//     gtk_box_pack_start(GTK_BOX(ouritem),ouritem->label,FALSE,FALSE,2);
//     ouritem->entry = gtk_entry_new();
//     g_signal_connect(G_OBJECT(ouritem->entry),"key_release_event",
//             G_CALLBACK(on_key_release),ouritem);
//     gtk_box_pack_start(GTK_BOX(ouritem),ouritem->entry,TRUE,TRUE,2);
// }
// //初始化类结构
// static void our_item_class_init(OurItemClass *ouritemclass)
// {
//     GtkObjectClass *object_class;
//     object_class = (GtkObjectClass*)ouritemclass;
//     //下面函数创建一个新的信号
//     ouritem_signals[OURITEM_OK_SIGNAL] = g_signal_new("ouritem_ok",
//                     G_TYPE_FROM_CLASS(object_class),
//                     G_SIGNAL_RUN_FIRST,
//                     G_STRUCT_OFFSET(OurItemClass, enter_ok),
//                     NULL,NULL,
//                     g_cclosure_marshal_VOID__VOID,
//                     G_TYPE_NONE, 0, NULL);
//     ouritemclass->enter_ok = enter_ok;//此函数在下面定义
// }
// //创建新的自定义控件
// GtkWidget* our_item_new(void)
// {
//     return GTK_WIDGET(g_object_new(TYPE_OUR_ITEM,0));
// }
// //设定自定义控件前面的静态文本
// void our_item_set_label(GtkWidget* item, gchar* label)
// {
//     gtk_label_set_text(GTK_LABEL(OUR_ITEM(item)->label),label);
// }
// //带参数创建自定义控件
// GtkWidget* our_item_new_with_label(gchar* label)
// {
//     GtkWidget* item;
//     item = our_item_new();
//     our_item_set_label(item,label);
//     return item;
// }
// //此函数只是简单的在终端上提示你已经按了一次回车键
// static void enter_ok(void)
// {
//     g_print("OK! Enter key was clicked! \n");
// }
// //以下函数捕获键盘输入消息
// void    on_key_release(GtkWidget *entry, GdkEventKey *event, gpointer data)
// {
//     if(event->keyval == GDK_KEY_Return)  //当按下回车键后发射自定义的信号
//     {
//         g_signal_emit(G_OBJECT(data),ouritem_signals[OURITEM_OK_SIGNAL],0);
//     }
// }
