/*
 * @Copyright: CS of BIT
 * @Author: hhz
 * @File name: 
 * @Version: 
 * @Date: 2019-09-01 19:43:01 -0700
 * @LastEditTime: 2019-09-01 19:51:39 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "GTKCreateLoading.h"
static GtkWidget *entry1;
static GtkWidget *entry2;
void on_button_clicked(GtkWidget *button, gpointer data)
{
    const gchar *username = gtk_entry_get_text(GTK_ENTRY(entry1));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry2));
    g_print("用户名是:%s ", username);
    g_print("\n");
    g_print("密码是:%s ", password);
    g_print("\n");
}

GtkWidget *create_button1(void)
{
    GtkWidget *box;
    GtkWidget *image;
    GtkWidget *button;
    GtkWidget *align;

    image = gtk_image_new_from_file("./pic/130pixel.png");
    box = gtk_hbox_new(FALSE, 0);
    //gtk_image_set_pixel_size(image,50);
    gtk_container_set_border_width(GTK_CONTAINER(box), 20);
    gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);
    gtk_widget_set_size_request(GTK_BOX(box), 150, 150);
    gtk_widget_show(image);
    align = gtk_alignment_new(0, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(align), box);
    gtk_widget_show(box);
    return align;
}


GtkWidget * CreateLoading(void)
{
    GtkWidget *window;
    GtkWidget *hbox;
    GtkWidget *vbox;
    GtkWidget *box1;
    GtkWidget *box2;
    GtkWidget *box3;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *sep;
    GtkWidget *sep1;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(window), "登录窗口");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    gtk_widget_set_size_request(GTK_WINDOW(window), 550, 150);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    hbox = gtk_hbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    //显示头像
    button1 = create_button1();
    gtk_box_pack_start(GTK_BOX(hbox), button1, FALSE, FALSE, 5);
    //分隔线
    sep1 = gtk_vseparator_new();
    gtk_box_pack_start(GTK_BOX(hbox), sep1, FALSE, FALSE, 5);

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 5);
    box1 = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), box1, FALSE, FALSE, 5);
    box2 = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), box2, FALSE, FALSE, 5);
    //label1 = gtk_label_new("用户名:");
    entry1 = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box1), entry1, FALSE, FALSE, 5);
    //label2 = gtk_label_new("密码:");
    entry2 = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(entry2), FALSE);
    gtk_box_pack_start(GTK_BOX(box2), entry2, FALSE, FALSE, 5);
    //登录按钮
    button = gtk_button_new_with_label("登录");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_button_clicked), NULL);
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
    gtk_widget_set_size_request(G_OBJECT(button), 50, 50);
    gtk_widget_show_all(window);
    return window;
}
