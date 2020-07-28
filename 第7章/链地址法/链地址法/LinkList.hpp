//
//  LinkList.hpp
//  链地址法
//
//  Created by 熊智宏 on 2020/7/28.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include "global.h"
typedef int KeyType;
typedef struct{
    KeyType key;
    String name;
}ElemType;
typedef struct Node{
    ElemType elem;
    struct Node *next;
}Node,*LinkList;
Status initLinkList(LinkList &linkList);
int isEmpty(LinkList linkList);
Status deleteLinkList(LinkList &linkList);
Status clearLinkList(LinkList &linkList);
int getLength(LinkList &linkList);
Status insertNode(LinkList &linkList,int i,ElemType elem);
Status deleteNode(LinkList &linkList,int i);
Status unionLinkList(LinkList &linkList1,LinkList &linkList2);
Status printLinkList(LinkList linkList);
#endif /* LinkList_hpp */
