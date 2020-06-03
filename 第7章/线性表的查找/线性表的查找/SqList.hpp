//
//  SqList.hpp
//  线性表的查找
//
//  Created by 熊智宏 on 2020/5/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef SqList_hpp
#define SqList_hpp

#include "global.h"
#define MAXSIZE 1000
typedef int Status;
typedef char *KeyType;
typedef struct{
    KeyType key;
    String name;
} ElemType;
typedef struct{
    ElemType *baseAddress;
    int length;
}SqList;
Status initSqList(SqList &sqList);
Status deleteSqList(SqList &sqList);
Status clearSqList(SqList &sqList);
int getLength(SqList sqList);
int isEmpty(SqList sqList);
Status getElem(SqList sqList,int index,ElemType &elem);
int locateElem(SqList sqList,ElemType elem);
int insertElem(SqList &sqList,int index,ElemType elem);
Status deleteElem(SqList &sqList,int index);
Status unionSqList(SqList &sqList1,SqList &sqList2);
Status mergeSqList(SqList sqList1,SqList sqList2,SqList &sqList3);
Status printSqList(SqList sqList);
int sqSearch1(SqList sqList,KeyType key);
int sqSearch2(SqList sqList,KeyType key);
int sqSearch3(SqList sqList,KeyType key);
int sqSearch4(SqList sqList,KeyType key);
int sqSentinelSearch(SqList sqList,KeyType key);//顺序哨兵查找
int binarySearch(SqList sqList,KeyType key);//二分查找（折半查找）
int recursiveBinarySearch(SqList sqList,KeyType key,int low,int high);//递归二分查找（递归折半查找）
#endif /* SqList_hpp */
