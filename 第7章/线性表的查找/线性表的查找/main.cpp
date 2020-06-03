//
//  main.cpp
//  线性表的查找
//
//  Created by 熊智宏 on 2020/5/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include <iostream>
#include "SqList.hpp"
int main(){
    SqList sqList;
    initSqList(sqList);
    //添加数据
    ElemType elem;
    elem.key="201730621111";
    elem.name="张三";
    insertElem(sqList,1,elem);
    elem.key="201730621112";
    elem.name="李四";
    insertElem(sqList,2,elem);
    elem.key="201730621113";
    elem.name="王五";
    insertElem(sqList,3,elem);
    elem.key="201730621114";
    elem.name="丘六";
    insertElem(sqList,4,elem);
    elem.key="201730621115";
    elem.name="李华";
    insertElem(sqList,5,elem);
    elem.key="201730621116";
    elem.name="李华";
    insertElem(sqList,6,elem);
    printSqList(sqList);
    
    int index=binarySearch(sqList,"201730621113");
    cout<<index<<endl;
    index=recursiveBinarySearch(sqList,"201730621113",1,sqList.length);
    cout<<index<<endl;
    return 0;
}
