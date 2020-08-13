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
Status addNode(LinkList &linkList,ElemType elem);
Status printLinkList(LinkList linkList);
#endif /* LinkList_hpp */
