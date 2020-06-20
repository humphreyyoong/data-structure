//
//  main.cpp
//  二叉排序树查找
//
//  Created by 熊智宏 on 2020/6/17.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include <iostream>
#include "LinkBinaryTree.hpp"
int main() {
    ElemType dataList[10];
    int length=sizeof(dataList)/sizeof(dataList[0]);
    createElemTypeList(dataList, length);
   // printElemTypeList(dataList, length);
    LinkBinaryNode binaryNodeList[length];
    toLinkBinaryNodeList(binaryNodeList, dataList, length);
    //printBinaryNodeList(binaryNodeList, length);
    LinkBinaryTree binaryTree=NULL;
    createLinkBinaryTree(binaryTree, binaryNodeList, length);
    inOrderTraverse(binaryTree);
    return 0;
}
