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
    SqList sqList;
    initSqList(sqList);
    
    //添加数据
    ElemType elem;
    elem.key=16;
    elem.name="张三";
    insertElem(sqList,1,elem);
    elem.key=12;
    elem.name="李四";
    insertElem(sqList,2,elem);
    elem.key=14;
    elem.name="王五";
    insertElem(sqList,3,elem);
    elem.key=18;
    elem.name="丘六";
    insertElem(sqList,4,elem);
    elem.key=13;
    elem.name="李华";
    insertElem(sqList,5,elem);
    elem.key=11;
    elem.name="李花";
    insertElem(sqList,6,elem);
    printSqList(sqList);
    printf("\n");
    
    //创建散列表并输出
    HashTable hashTable;
    initHashTable(hashTable, sqList);
    //createHashTableByOpenAddressMethod(hashTable, sqList); //通过开放地址法创建散列表
    createHashTableBySecondDetectionMethod(hashTable, sqList); //通过二次探测法创建散列表
    printHashTable(hashTable);
    printf("\n");
    
    //在散列表中查找数据
    int key;
    printf("请输入你要查找数据的主键:");
    scanf("%d",&key);
    //key=searchHashTableByOpenAddressMethod(hashTable, key); //通过开放地址法在散列表中查找
    key=searchHashTableBySecondDetectionMethod(hashTable, key); //通过开放地址法在散列表中查找
    printf("该数据在散列表的下标是:%d\n",key);
}
