/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:08:01 -0700
 * @LastEditTime: 2019-09-01 01:29:01 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "callbacks.h"
static GtkWidget* dialog = NULL;

GtkWidget* create_toolbar (GtkWidget* window);
static gboolean on_drag_drop();
static void on_drag_data_received(GtkWidget *widget, GdkDragContext *context,
        gint x,gint y,GtkSelectionData *data,guint info,guint time,gpointer user_data);

/**
 * @Author: 王可欣
 * @Description: 创建主窗口
 * @Param: 
 * @Return: 
 */
GtkWidget* create_window(void)
{
 
    GtkWidget* window;
    GtkWidget* SendText;
    GtkWidget* scrolledwin;
    GtkWidget* box;
    GtkWidget* statusbar;
    GtkWidget* menubar ;
    GtkWidget* toolbar ;
    GtkAccelGroup* accel_group ;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"完整的应用程序窗口");

    gtk_window_set_default_size(GTK_WINDOW(window),400,300);
    accel_group = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(window),accel_group);
    box = gtk_vbox_new(FALSE,0);
    gtk_container_add (GTK_CONTAINER (window), box);
    

    toolbar = create_toolbar(window);
    gtk_box_pack_start(GTK_BOX(box),toolbar,0,1,0);
    scrolledwin = gtk_scrolled_window_new(NULL,NULL);
    SendText = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(box),scrolledwin,TRUE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(scrolledwin),SendText);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(SendText),TRUE);

    // //拖拽
    GtkTargetEntry targets={"text/uri-list", GTK_TARGET_OTHER_APP,1 };    
    gtk_drag_dest_set(SendText, GTK_DEST_DEFAULT_DROP, &targets,1, GDK_ACTION_COPY);   
    g_signal_connect(G_OBJECT(SendText),"drag-data-received",G_CALLBACK(on_drag_data_received),NULL);    
    g_signal_connect(G_OBJECT(SendText),"drag-drop",G_CALLBACK(on_drag_drop),NULL);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(box),statusbar,FALSE,FALSE,0);
    gtk_widget_show_all(window);
    return window;
}

/**
 * @Author: 王可欣
 * @Description: 创建一个toolbar
 * @Param: 
 * @Return: 
 */
GtkWidget* create_toolbar (GtkWidget* window)
{
    
    GtkWidget* toolbar;
    GtkWidget *StickerIcon,*DocuIcon;
    GtkWidget* sticker;
	GtkToolItem *OpenDocu;

    toolbar = gtk_toolbar_new();
    StickerIcon = gtk_image_new_from_file("./bin/pic/pic.png");
    DocuIcon=gtk_image_new_from_file("./bin/pic/document.png");
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
 
    sticker=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "发送表情", "Private", StickerIcon, 
                                                        GTK_SIGNAL_FUNC (PressStickerBtn), NULL);
    OpenDocu=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "打开文件", "Private", DocuIcon, 
                                                        GTK_SIGNAL_FUNC (on_file_open_activate), NULL);                               
    return toolbar;
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
        while(uris[i]!=NULL||uris[i]!='\0')
        {            
            //文件储存地址
            g_printf("%s\n",uris[i]);            
            i++;        
        }        
        g_strfreev(uris);    
    }    
    gtk_drag_finish(context,TRUE,TRUE,time);
}
