//
//  SqList.hpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/24.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef SqList_hpp
#define SqList_hpp

#include "global.h"
#include "LinkList.hpp"
#define MAXSIZE 1000
typedef int Status;
typedef struct{
    ElemType *baseAddress;
    int length;
}SqList;
Status initSqList(SqList &sqList); //初始化线性表
int insertElem(SqList &sqList,int index,ElemType elem); //在线性表中插入数据元素
Status printSqList(SqList sqList); //输出线性表
Status radixSort(SqList &sqList);
#endif /* SqList_hpp */


