/*
 * @Description: In User Settings Edit
 * @Author: your namewei
 * @Date: 2019-08-29 23:25:48wei
 * @LastEditTime: 2019-08-31 03:23:54 -0700
 * @LastEditors: Please set LastEditors
 */

#include "head.h"
static GtkWidget* dialog = NULL;
//窗口中可见的文本框
static GtkTextBuffer *message_buffer;


GtkWidget* create_view (gchar* filename)
{
    //创建新的图像窗口
    GtkWidget* image;
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),filename);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    image = gtk_image_new_from_file(filename);
    gtk_container_add(GTK_CONTAINER(window),image);
    gtk_widget_show_all(window);
    return window;
}

/**
 * @Author: 王可欣
 * @Description: 文件选择框中点击确定
 * @Param: 
 * @Return: 
 */
void on_ok (GtkButton* button, gpointer data)
{
    const char* filename;
    GtkWidget* window;
    filename = gtk_file_selection_get_filename(GTK_FILE_SELECTION(data));
    window = create_view(filename);
    gtk_widget_show(window);
}



/**
 * @Author: 王可欣
 * @Description: 防止on_drag_data_received调用两次
 * @Param: 
 * @Return: 
 */
static gboolean on_drag_drop()
{    
    return TRUE;
}
/**
 * @Author: 王可欣
 * @Description: 识别拖拽进来的文件
 * @Param: 
 * @Return: 
 */
static void on_drag_data_received(GtkWidget *widget, GdkDragContext *context,
        gint x,gint y,GtkSelectionData *data,guint info,guint time,gpointer user_data)
{    
    GdkAtom atom=gtk_selection_data_get_data_type(data);    
    if(gtk_targets_include_uri(&atom,1))
    {        
        gchar **uris=gtk_selection_data_get_uris(data);       
        gint i=0;        
        while(uris[i]!=NULL)
        {            
            //文件储存地址
            g_printf("%s\n",uris[i]);            
            i++;        
        }        
        //gtk_entry_set_text(GTK_ENTRY(widget),uris[0]);        
        /* 使用默认程序打开 */        
        //g_app_info_launch_default_for_uri(uris[0],NULL,NULL);        
        //释放地址
        g_strfreev(uris);    
    }    
    gtk_drag_finish(context,TRUE,TRUE,time);
}

/**
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
 * @Description: 点击选择图片的按钮
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void on_clicked (GtkButton *button, gpointer data)
{
    //函数创建文件选择的窗口
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


/**
 * @Author: 王可欣
 * @Description: 创建打开文件挂管理器的按钮
 * @Param: 
 * @Return: 
 * @Throw: 
 */
GtkWidget* CreateImageBtn(void)
{
    GtkWidget* box;
    GtkWidget* image;
    GtkWidget* label;
    GtkWidget* button;
    char* title = "图片";
    image = gtk_image_new_from_file("apple-red.png");
    label = gtk_label_new(title);
    box = gtk_vbox_new(FALSE,2);
    gtk_container_set_border_width(GTK_CONTAINER(box),5);
    gtk_box_pack_start(GTK_BOX(box),image,FALSE,FALSE,3);
    gtk_box_pack_start(GTK_BOX(box),label,FALSE,FALSE,3);
    gtk_widget_show(image);
    gtk_widget_show(label);
    button = gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button),box);
    gtk_widget_show(box);
    return button ;
}


int main ( int argc , char* argv[])
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *image, *button,*message;
    GtkTextIter iter;
    gtk_init(&argc,&argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window),"delete_event",
    G_CALLBACK(gtk_main_quit),NULL);
    gtk_window_set_title(GTK_WINDOW(window),"图像查看软件");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gtk_window_set_default_size(GTK_WINDOW(window),500,500);
    vbox = gtk_vbox_new(FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),vbox);
    
   
    button=CreateImageBtn();
    gtk_box_pack_start(GTK_BOX(vbox),button,FALSE,FALSE,5);
    g_signal_connect(G_OBJECT(button),"clicked",
                        G_CALLBACK(on_clicked),NULL);

    //创建文本框
    message=gtk_text_view_new();
    gtk_widget_set_size_request(message,400,250); 
    gtk_box_pack_start(GTK_BOX(vbox),message,FALSE,FALSE,0); 

    message_buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(message));
     
    GtkTargetEntry targets={"text/uri-list", GTK_TARGET_OTHER_APP,1 };    
    gtk_drag_dest_set(message, GTK_DEST_DEFAULT_DROP, &targets,1, GDK_ACTION_COPY);   
    g_signal_connect(G_OBJECT(message),"drag-data-received",G_CALLBACK(on_drag_data_received),NULL);    
    g_signal_connect(G_OBJECT(message),"drag-drop",G_CALLBACK(on_drag_drop),NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return FALSE;
}






