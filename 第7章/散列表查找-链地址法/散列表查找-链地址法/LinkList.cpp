//
//  LinkList.cpp
//  链地址法
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
int isEmpty(LinkList linkList){
    if(linkList->next==NULL)return TRUE;
    else return FALSE;
}
Status deleteLinkList(LinkList &linkList){
    Node *p=linkList;
    if(linkList){
        linkList=linkList->next;
        delete p;
        p=linkList;
    }
    delete linkList;
    return SUCCESS;
}
Status clearLinkList(LinkList &linkList){
    Node *p=linkList->next,*q;
    while(p){
        q=p->next;
        delete p;
        p=q;
    }
    linkList->next=NULL;
    return SUCCESS;
}
int getLength(LinkList &linkList){
    Node *p=linkList->next;
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}
Status insertNode(LinkList &linkList,int i,ElemType elem){
    Node *p=linkList;
    int index=0;
    while(p&&index<i-1){
        p=p->next;
        index++;
    }
    if(index!=i-1){
        printf("插入节点失败\n");
        return FAIL;
    }
    Node *s=new Node;
    s->elem=elem;
    s->next=p->next;
    p->next=s;
    printf("插入节点成功\n");
    return SUCCESS;
}
Status deleteNode(LinkList &linkList,int i){
    Node *p=linkList;
    int index=0;
    while(p->next&&index<i-1){
        p=p->next;
        index++;
    }
    if(!(p->next)||index!=i-1){
        printf("删除节点失败\n");
        return FAIL;
    }
    Node *q=p->next;
    p->next=q->next;
    delete q;
    printf("删除节点成功\n");
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
