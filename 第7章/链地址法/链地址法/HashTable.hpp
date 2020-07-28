//
//  HashTable.hpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp
#include "global.h"
#include "LinkList.hpp"
typedef struct{
    Node *baseAddress;
    int length;
}HashTable;
Status inintHashTable(HashTable &hashTable,LinkList &linkList);
Status createHashTableByChainAddress(HashTable &hashTable,LinkList &linkList);
Status printHashTable(HashTable &hashTable); //输出散列表
#endif /* HashTable_hpp */ 

