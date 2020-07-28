//
//  HashTable.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "HashTable.hpp"
int hashFunction(int key,int length){ //散列函数
    return key%length;
}
Status inintHashTable(HashTable &hashTable,LinkList &linkList){
    int i,length=getLength(linkList);
    hashTable.baseAddress=new Node[length];
    hashTable.length=length;
    for(i=0;i<hashTable.length;i++){ //初始化散列表的键值为-1
        hashTable.baseAddress[i].next=NULL;
    }
    return SUCCESS;
}
Status createHashTableByChainAddress(HashTable &hashTable,LinkList &linkList){
    int index;
    Node *p=linkList->next;
    while(p!=NULL){
        index=hashFunction(p->elem.key,hashTable.length);
        Node *q=&hashTable.baseAddress[index];
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
        p=p->next;
        q->next->next=NULL;
    }
    return SUCCESS;
}
Status printHashTable(HashTable &hashTable){//输出散列表
    int i;
    for(i=0;i<hashTable.length;i++){
        printf("%d  ",i);
        Node *p=&hashTable.baseAddress[i];
        while(p->next!=NULL){
            p=p->next;
            printf("%d %s   ",p->elem.key,p->elem.name);
        }
        printf("\n");
    }
    printf("散列表输出成功\n");
    return SUCCESS;
}
