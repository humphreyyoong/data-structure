//
//  LinkQueue.hpp
//  邻接表
//
//  Created by 熊智宏 on 2020/4/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include "global.h"
#endif /* LinkQueue_hpp */
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct{
    Node *head;
    Node *tail;
}LinkQueue;
Status initLinkQueue(LinkQueue &linkQueue); //初始化队列
int getLength(LinkQueue linkQueue); //获取队列长度
Status isEmpty(LinkQueue linkQueue);    //判断是否为空
Status isExist(LinkQueue linkQueue,ElemType data);   //判断一个元素是否在该队列中
Status destroyLinkQueue(LinkQueue &linkQueue); //销毁队列
Status enLinkQueue(LinkQueue &linkQueue,ElemType data); //入队
Status deLinkQueue(LinkQueue &linkQueue,ElemType &data); //出队
Status getHead(LinkQueue &linkQueue,ElemType &data); //获取队头
Status printLinkQueue(LinkQueue linkQueue); //输出队列
