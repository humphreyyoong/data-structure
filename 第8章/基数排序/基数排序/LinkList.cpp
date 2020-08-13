//
//  LinkList.cpp
//
//  Created by 熊智宏 on 2020/7/28.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "LinkList.hpp"
Status initLinkList(LinkList &linkList){
    linkList=new Node;
    linkList->next=NULL;
    return SUCCESS;
}
Status addNode(LinkList &linkList,ElemType elem){
    Node *p=linkList;
    while(p->next!=NULL){
        p=p->next;
    }
    Node *node=new Node;
    node->elem=elem;
    node->next=NULL;
    p->next=node;
    return SUCCESS;
}
Status printLinkList(LinkList linkList){
    Node *p=linkList->next;
    printf("\n\n--------\n");
    while(p){
        printf("%d | %s\n",p->elem.key,p->elem.name);
        printf("--------\n");
        p=p->next;
    }
    printf("\n\n");
    return SUCCESS;
}
