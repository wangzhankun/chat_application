/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:08:01 -0700
 * @LastEditTime: 2019-09-01 20:06:11 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "callbacks.h"
#include "interface.h"
static GtkWidget* dialog = NULL;
TextView SendText;
GtkWidget* CreateSendToolbar (GtkWidget* window);
static gboolean DropDocument();
static void ReceiveDrop(GtkWidget *widget, GdkDragContext *context,
        gint x,gint y,GtkSelectionData *data,guint info,guint time,gpointer user_data);


/**
 * @Author: 王可欣
 * @Description: 好友列表
 * @Param: 
 * @Return: 
 */
// GtkWidget* CreateFriendWindow(void)
// {
//     GtkWidget* FriendWindow;
//     gtk_window_set_title(GTK_WINDOW(FriesdWindow),"好友");

//     gtk_window_set_default_size(GTK_WINDOW(TalkWindow),100,300);
//     accel_group = gtk_accel_group_new();
//     gtk_window_add_accel_group(GTK_WINDOW(TalkWindow),accel_group);
//     TalkMenuBox = gtk_vbox_new(FALSE,0);
//     gtk_container_add (GTK_CONTAINER (TalkWindow), TalkMenuBox);

//     gtk_widget_show_all(FriendWindow);
//     return FriendWindow;
// }
/**
 * @Author: 王可欣
 * @Description: 创建主窗口
 * @Param: 
 * @Return: 
 */
GtkWidget* CreateTalkWindow(void)
{
    GtkWidget* TalkWindow;
    GtkWidget* scrolledwin;
    GtkWidget* TalkMenuBox;
    GtkWidget* statusbar;
    GtkWidget* menubar ;
    GtkWidget* toolbar ;
    GtkWidget* SendBtn;
    GtkAccelGroup* accel_group ;
    TalkWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(TalkWindow),"完整的应用程序窗口");

    gtk_window_set_default_size(GTK_WINDOW(TalkWindow),400,300);
    accel_group = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(TalkWindow),accel_group);
    TalkMenuBox = gtk_vbox_new(FALSE,0);
    gtk_container_add (GTK_CONTAINER (TalkWindow), TalkMenuBox);
    

    toolbar = CreateSendToolbar(TalkWindow);
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),toolbar,0,1,0);
    scrolledwin = gtk_scrolled_window_new(NULL,NULL);
    
    SendText.view = gtk_text_view_new();
    SendText.view_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(SendText.view));
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),scrolledwin,TRUE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(scrolledwin),SendText.view);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(SendText.view),TRUE);

    SendBtn = gtk_button_new_with_label("发送");
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),SendBtn,FALSE,FALSE,0);
    gtk_widget_set_size_request(GTK_BOX(SendBtn),30,30);

    // //拖拽
    GtkTargetEntry targets={"text/uri-list", GTK_TARGET_OTHER_APP,1 };    
    gtk_drag_dest_set(SendText.view, GTK_DEST_DEFAULT_DROP, &targets,1, GDK_ACTION_COPY);   
    g_signal_connect(G_OBJECT(SendText.view),"drag-data-received",G_CALLBACK(ReceiveDrop),NULL);    
    g_signal_connect(G_OBJECT(SendText.view),"drag-drop",G_CALLBACK(DropDocument),NULL);

    statusbar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),statusbar,FALSE,FALSE,0);
    gtk_widget_show_all(TalkWindow);
    return TalkWindow;
}

/**
 * @Author: 王可欣
 * @Description: 创建一个toolbar
 * @Param: 
 * @Return: 
 */
GtkWidget* CreateSendToolbar (GtkWidget* window)
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
                                                        GTK_SIGNAL_FUNC (PressStickerBtn), &SendText);
    OpenDocu=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "打开文件", "Private", DocuIcon, 
                                                        GTK_SIGNAL_FUNC (OpenSelectDocument), NULL);                               
    return toolbar;
}


/**
 * @Author: 王可欣
 * @Description: 防止on_drag_data_received调用两次
 * @Param: 
 * @Return: 
 */
static gboolean DropDocument()
{    
    return TRUE;
}

/**
 * @Author: 王可欣
 * @Description: 识别拖拽进来的文件
 * @Param: 
 * @Return: 
 */
static void ReceiveDrop(GtkWidget *widget, GdkDragContext *context,
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
