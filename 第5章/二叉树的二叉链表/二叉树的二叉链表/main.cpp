//
//  main.cpp
//  二叉树的二叉链表
//
//  Created by 熊智宏 on 2020/3/9.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "LinkBinaryTree.hpp"
int main(int argc, const char * argv[]) {
//    LinkStack linkStack;
//    initLinkStack(linkStack);
//    push(linkStack,'a');
//    push(linkStack,'b');
//    push(linkStack,'c');
//    printLinkStack(linkStack);
//    ElemType e;
//    pop(linkStack,e);
//    cout<<"Message:"<<e<<endl;
//    getTop(linkStack,e);
//    cout<<"Message:"<<e<<endl;
//    printLinkStack(linkStack);
//    isEmpty(linkStack);
    LinkBinaryTree binaryTree;
    createLinkBinaryTree(binaryTree);
    printLinkBinaryTree(binaryTree);
    cout<<endl;
    
    LinkBinaryTree binaryTree2;
    copy(binaryTree,binaryTree2);
    printLinkBinaryTree(binaryTree2);
    cout<<endl;
    cout<<"Message:深度为"<<getDepth(binaryTree2)<<endl;
    cout<<"Message:节点总数为"<<getNodeCount(binaryTree2)<<endl;
    cout<<"Message:叶子总数为"<<getLeafCount(binaryTree2)<<endl;
    return 0;
}
