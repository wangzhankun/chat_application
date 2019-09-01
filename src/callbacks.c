/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:45:05 -0700
 * @LastEditTime: 2019-09-01 01:44:46 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "interface.h"

/**
 * @Author: 王可欣
 * @Description: 插入表情
 * @Param: 
 * @Return: 
 */
 void insert_sticker(GtkWidget *widget,GdkEventButton *event, struct sticker_info *sinfo)
 {
//     GtkTextIter end;
//     //获取缓冲区的尾部
//     gtk_text_buffer_get_end_iter(sinfo->view2_buffer,&end);
//     //向缓冲区插入数据
//     gtk_text_buffer_insert(sinfo->view2_buffer,&end,sinfo->str,-1);

//     GtkWidget *sticker_window = sinfo->sticker_window;
//     struct sticker_info **p = sinfo->spointer;
//     int i;
//     for (i=0;i<6;i++) free(p[i]);
//     free(p);
//     gtk_widget_destroy(sticker_window);
}

/**
 * @Author: 王可欣
 * @Description: 销毁表情窗口
 * @Param: 
 * @Return: 
 */
void destory_sticker_window(GtkWidget *widget,GdkEventCrossing *event,GtkWidget* data){
    gtk_widget_destroy(data);
}

/**
 * @Author: 王可欣
 * @Description:按下插入表情按钮 
 * @Param: 
 * @Return: 
 */
void PressStickerBtn(GtkWidget *widget, GdkEvent *event, struct text_view_info *viewinfo){
    if(event->type == GDK_BUTTON_RELEASE){

        GdkEventButton *event_button = (GdkEventButton *) event;
        if(event_button->button == 1){
            //显示表情包的界面
            GtkWidget *sticker_window;
            GtkWidget *eventbox;
            GtkWidget *sbox1, *sbox2, *sbox3, *sbox4, *sbox5, *sbox6;  //盛放6个表情的eventbox
            GtkWidget *table;
            GtkWidget *s1, *s2, *s3, *s4, *s5, *s6; //6个表情的image

            sticker_window = gtk_window_new(GTK_WINDOW_POPUP);  //弹出式不边框窗口
            gtk_window_set_default_size(GTK_WINDOW(sticker_window),100,100);
            gtk_widget_set_size_request(sticker_window,200,100);
            gtk_window_set_position(GTK_WINDOW(sticker_window), GTK_WIN_POS_MOUSE);  //出现在鼠标位置

            eventbox = gtk_event_box_new();
            g_signal_connect(G_OBJECT(eventbox),"leave_notify_event",G_CALLBACK(destory_sticker_window),sticker_window);
            gtk_container_add(GTK_CONTAINER(sticker_window),eventbox);
            table = gtk_table_new(2,3,FALSE);
            gtk_container_add(GTK_CONTAINER(eventbox),table);

            sbox1 = gtk_event_box_new();
            sbox2 = gtk_event_box_new();
            sbox3 = gtk_event_box_new();
            sbox4 = gtk_event_box_new();
            sbox5 = gtk_event_box_new();
            sbox6 = gtk_event_box_new();

            struct sticker_info **spointer = (struct sticker_info **)malloc(sizeof(struct sticker_info *)*6);

            struct sticker_info *sinfo1 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo1->str = "/am";sinfo1->view2_buffer = viewinfo->view2_buffer;
            sinfo1->sticker_window = sticker_window;sinfo1->spointer = spointer;

            struct sticker_info *sinfo2 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo2->str = "/dk";sinfo2->view2_buffer = viewinfo->view2_buffer;
            sinfo2->sticker_window = sticker_window;sinfo2->spointer = spointer;

            struct sticker_info *sinfo3 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo3->str = "/fd";sinfo3->view2_buffer = viewinfo->view2_buffer;
            sinfo3->sticker_window = sticker_window;sinfo3->spointer = spointer;

            struct sticker_info *sinfo4 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo4->str = "/sk";sinfo4->view2_buffer = viewinfo->view2_buffer;
            sinfo4->sticker_window = sticker_window;sinfo4->spointer = spointer;

            struct sticker_info *sinfo5 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo5->str = "/wx";sinfo5->view2_buffer = viewinfo->view2_buffer;
            sinfo5->sticker_window = sticker_window;sinfo5->spointer = spointer;

            struct sticker_info *sinfo6 = (struct sticker_info *)malloc(sizeof(struct sticker_info));
            sinfo6->str = "/zj";sinfo6->view2_buffer = viewinfo->view2_buffer;
            sinfo6->sticker_window = sticker_window;sinfo6->spointer = spointer;

            spointer[0] = sinfo1;
            spointer[1] = sinfo2;
            spointer[2] = sinfo3;
            spointer[3] = sinfo4;
            spointer[4] = sinfo5;
            spointer[5] = sinfo6;

            g_signal_connect(G_OBJECT(sbox1),"button_press_event",G_CALLBACK(insert_sticker),sinfo1);
            g_signal_connect(G_OBJECT(sbox2),"button_press_event",G_CALLBACK(insert_sticker),sinfo2);
            g_signal_connect(G_OBJECT(sbox3),"button_press_event",G_CALLBACK(insert_sticker),sinfo3);
            g_signal_connect(G_OBJECT(sbox4),"button_press_event",G_CALLBACK(insert_sticker),sinfo4);
            g_signal_connect(G_OBJECT(sbox5),"button_press_event",G_CALLBACK(insert_sticker),sinfo5);
            g_signal_connect(G_OBJECT(sbox6),"button_press_event",G_CALLBACK(insert_sticker),sinfo6);

            s1 = gtk_image_new_from_file("./bin/sticker/am.gif");
            s2 = gtk_image_new_from_file("./bin/sticker/dk.gif");
            s3 = gtk_image_new_from_file("./bin/sticker/fd.gif");
            s4 = gtk_image_new_from_file("./bin/sticker/sk.gif");
            s5 = gtk_image_new_from_file("./bin/sticker/wx.gif");
            s6 = gtk_image_new_from_file("./bin/sticker/zj.gif");

            gtk_container_add(GTK_CONTAINER(sbox1),s1);
            gtk_container_add(GTK_CONTAINER(sbox2),s2);
            gtk_container_add(GTK_CONTAINER(sbox3),s3);
            gtk_container_add(GTK_CONTAINER(sbox4),s4);
            gtk_container_add(GTK_CONTAINER(sbox5),s5);
            gtk_container_add(GTK_CONTAINER(sbox6),s6);

            gtk_table_attach_defaults(GTK_TABLE(table),sbox1,0,1,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox2,1,2,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox3,2,3,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox4,0,1,1,2);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox5,1,2,1,2);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox6,2,3,1,2);
            
            gtk_widget_show_all(sticker_window);
        }
    }
}




static GtkWidget* dialog = NULL;
/*
 * @Author: 王可欣
 * @Description: 文件选择框点击取消
 * @Param: 
 * @Return: 
 */
void on_cancel (GtkButton *button,gpointer data)
{
    gtk_widget_destroy(dialog);
}

/**
 * @Author: 王可欣
 * @Description: 文件选择框中点击确定
 * @Param: 
 * @Return: 
 */
void on_ok (GtkButton* button, gpointer data)
{
    //filename是文件路径
    const char* filename;
    GtkWidget* window;
    filename = gtk_file_selection_get_filename(GTK_FILE_SELECTION(data));
    //g_print("xnjxnjzx");
    g_printf("%s\n",filename);
    //window = create_view(filename);
    //gtk_widget_show(window);
}


gboolean on_window_delete_event (GtkWidget* widget,GdkEvent *event,gpointer data)
{
    gtk_main_quit();
    return FALSE;
}

/**
 * @Author: 王可欣
 * @Description: 点击发送文件按钮的回调函数
 * @Param: 
 * @Return: 
 */
void on_file_open_activate (GtkMenuItem* menuitem,gpointer data)
{
    //函数创建文件选择的窗口
    g_printf(" njzznjnk");
     dialog = gtk_file_selection_new("请选择一个图像文件");
    g_signal_connect(G_OBJECT(dialog),"destroy",
                G_CALLBACK(gtk_widget_destroy),dialog);
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(dialog)->ok_button),
                                        "clicked", G_CALLBACK(on_ok),dialog);
    g_signal_connect_swapped(G_OBJECT(
                    GTK_FILE_SELECTION(dialog)->ok_button),
                    "clicked",G_CALLBACK(on_cancel),NULL);
    g_signal_connect(G_OBJECT(
                    GTK_FILE_SELECTION(dialog)->cancel_button),
                    "clicked", G_CALLBACK(on_cancel),NULL);
    gtk_widget_show(dialog);
    
}

