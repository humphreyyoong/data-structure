//
//  main.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/23.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include <iostream>
#include "HashTable.hpp"
int main(int argc, const char * argv[]) {
    LinkList linkList;
    initLinkList(linkList);
    //添加数据
    ElemType elem;
    elem.key=16;
    elem.name="张三";
    insertNode(linkList,1,elem);
    elem.key=12;
    elem.name="李四";
    insertNode(linkList,2,elem);
    elem.key=14;
    elem.name="王五";
    insertNode(linkList,3,elem);
    elem.key=18;
    elem.name="丘六";
    insertNode(linkList,4,elem);
    elem.key=13;
    elem.name="李华";
    insertNode(linkList,5,elem);
    elem.key=11;
    elem.name="李花";
    insertNode(linkList,6,elem);
    printLinkList(linkList);
    printf("\n");
    
    HashTable hashTable;
    inintHashTable(hashTable, linkList);
    createHashTableByChainAddress(hashTable, linkList);
    printHashTable(hashTable);
    
    return 0;
}
