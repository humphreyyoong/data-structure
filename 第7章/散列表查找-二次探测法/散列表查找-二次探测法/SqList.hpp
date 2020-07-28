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
#define MAXSIZE 1000
typedef int Status;
typedef int KeyType;
typedef struct{
    KeyType key;
    String name;
} ElemType;
typedef struct{
    ElemType *baseAddress;
    int length;
}SqList;
Status initSqList(SqList &sqList);
int insertElem(SqList &sqList,int index,ElemType elem);
Status printSqList(SqList sqList);
#endif /* SqList_hpp */

