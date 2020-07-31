//
//  main.cpp
//  直接插入排序
//
//  Created by 熊智宏 on 2020/7/30.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include <iostream>
#include "SqList.hpp"
int main(){
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

    directInsertionSortByUseSentry(sqList); //直接插入排序
    printSqList(sqList);
    return 0;
}
