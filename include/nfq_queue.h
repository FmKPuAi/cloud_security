#ifndef __NFQ_QUEUE_H
#define __NFQ_QUEUE_H

#include <netinet/in.h>
#include <linux/types.h>
#include <linux/netfilter.h>            /* for NF_ACCEPT */
#include <libnetfilter_queue/libnetfilter_queue.h>
#include <libnetfilter_queue/libnetfilter_queue_tcp.h>

/****
function:创建netfilrer队列
参数: h netfilter队列连接句柄 qh 队列句柄 hook 抓包hook点 
****/
void create_nfq(struct nfq_handle **h,struct nfq_q_handle **qh,int hook);
/****
function:队列持续接收数据包
参数: h netfilter队列连接句柄 
****/
void receive_nfq(struct nfq_handle *h);
/****
function:解除netfilter队列绑定
参数: h netfilter队列连接句柄  qh 队列句柄
****/
void unbind_nfq(struct nfq_handle *h,struct nfq_q_handle *qh);

#endif
