//
//  HashTable.hpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp
#include "SqList.hpp"
#include "global.h"
typedef struct{
    ElemType *baseAddress;
    int length;
}HashTable;

int hashFunction(int key,int length); //散列函数
int pseudoRandomNumber(int next); // 生成伪随机数
Status initHashTable(HashTable &hashTable,SqList &sqList); //初始化散列表
Status createHashTableByPseudoRandomDetectionMethod(HashTable &hashTable,SqList &sqList); //通过伪随机探测法创建散列表
Status printHashTable(HashTable &hashTable); //输出散列表
int searchHashTableByPseudoRandomDetectionMethod(HashTable &hashTable,KeyType key); //通过随机探测法在散列表中查找
#endif /* HashTable_hpp */ 

