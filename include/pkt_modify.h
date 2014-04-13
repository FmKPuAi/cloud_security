#ifndef __PKT_MODIFY_H
#define __PKT_MODIFY_H
#include <linux/ip.h>
#include <linux/tcp.h>
/****
function: 修改上传文件数据包
参数: data 数据包内容指针  data_len 数据包大小 
****/
void Modify_up_pkt (unsigned char *data,int data_len);
/****
function: 修改下载文件数据包
参数: data 数据包内容指针
****/
void Modify_down_pkt (unsigned char *data);

#endif
