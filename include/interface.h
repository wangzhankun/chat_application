/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 09:02:24 -0700
 * @LastEditTime: 2019-09-01 05:13:18 -0700
 * @LastEditors: 
 * @Description: 
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__
GtkWidget* create_window( void );
typedef struct sticker_info{
    GtkWidget *sticker_window;
    GtkTextBuffer *view2_buffer; //文本缓冲区
    char *str;   //表情的名字
    struct sticker_info **spointer;
}Stiker;

struct text_view_info{
    GtkWidget *view1, *view2;
    GtkTextBuffer *view1_buffer,*view2_buffer;
};

#endif
