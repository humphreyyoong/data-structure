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
    //创建二叉排序树
    ElemType dataList[10];
    int length=sizeof(dataList)/sizeof(dataList[0]);
    createElemTypeList(dataList, length); //创建一个元素列表
   // printElemTypeList(dataList, length);
    LinkBinaryNode binaryNodeList[length]; //创建一个二叉树的节点列表
    toLinkBinaryNodeList(binaryNodeList, dataList, length); //把元素列表转换为二叉树的节点列表
    //printBinaryNodeList(binaryNodeList, length);
    LinkBinaryTree binaryTree=NULL;
    createLinkBinaryTree(binaryTree, binaryNodeList, length); //通过二叉树的节点列表创建一个二叉排序树
    inOrderTraverse(binaryTree); //中序遍历输出二叉排序树
    LinkBinaryNode *node=firstOfInOrderTraverse(binaryTree);
    cout<<"First Node Of inOrederTraverse:"<<node->data.key<<endl;
    
    //二叉排序树查找
    int key;
    cout<<"请输入要查找数据的主键:";
    cin>>key;
    LinkBinaryTree p=SearchLinkBinaryTree(binaryTree, key);
    cout<<"key:"<<p->data.key<<" name:"<<p->data.name<<endl;
    
    //删除二叉树中的节点
    removeBinaryNode(binaryTree, 2);
    inOrderTraverse(binaryTree);
    return 0;
}
