//
//  HashTable.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "HashTable.hpp"
int hashFunction(int key){ //散列函数
    return key%7;
}
Status initHashTable(HashTable &hashTable,SqList &sqList){ //初始化散列表
    hashTable.baseAddress=new ElemType[sqList.length];
    hashTable.length=sqList.length;
    int i;
    for(i=0;i<sqList.length;i++){ //初始化散列表的键值为-1
        hashTable.baseAddress[i].key=-1;
    }
    for(i=1;i<=sqList.length;i++){ //把数据填入散列表中
        int index=hashFunction(sqList.baseAddress[i].key);
        while(hashTable.baseAddress[index].key!=-1){ //如果当前下标指向的空间已经有数据，则选择下一个下标
            index=hashFunction(index+1);
        }
        hashTable.baseAddress[index]=sqList.baseAddress[i]; //把顺序表中的数据复制到散列表中
    }
    return SUCCESS;
}
Status printHashTable(HashTable &hashTable){//输出散列表
    int i;
    for(i=0;i<hashTable.length;i++){
        ElemType column=hashTable.baseAddress[i];
        printf("%d,%s\n",column.key,column.name);
    }
    printf("散列表输出成功\n");
    return SUCCESS;
}
int searchHashTable(HashTable &hashTable,KeyType key){//在散列表中查找
    int index=hashFunction(key);
    int i=0;
    while(hashTable.baseAddress[index].key!=key){ //如果当前的下标的主键与想查找的下标不一致则继续查找
        index=hashFunction(index+1);
        if(i>=hashTable.length){
            return -1;
        }
    }
    return index;
}
