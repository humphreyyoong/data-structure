//
//  LinkBinaryTree.hpp
//  二叉排序树查找
//
//  Created by 熊智宏 on 2020/6/17.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef LinkBinaryTree_hpp
#define LinkBinaryTree_hpp

#include "global.h"
#include <stdio.h>
#include <string.h>
typedef struct{
    int key;
    char name[10];
}ElemType;
typedef struct LinkBinaryNode{
    ElemType data;
    struct LinkBinaryNode *lchild, *rchild;
}LinkBinaryNode,*LinkBinaryTree;
#endif /* LinkBinaryTree_hpp */
Status insertLinkBinaryNode(LinkBinaryTree &binaryTree,LinkBinaryNode &binaryNode); //插入到二叉排序树
Status createLinkBinaryTree(LinkBinaryTree &binaryTree,LinkBinaryNode binaryNodeList[],int length); //创建二叉排序树
Status visit(ElemType data); //输入具体数据的函数
Status inOrderTraverse(LinkBinaryTree binaryTree); //中序遍历
LinkBinaryNode* firstOfInOrderTraverse(LinkBinaryTree binaryTree); //查找中序遍历中的第一节点
Status createElemTypeList(ElemType dataList[],int length);//创建数据列表
Status printElemTypeList(ElemType dataList[],int length); //输出数据列表
Status toLinkBinaryNodeList(LinkBinaryNode binaryNodeList[],ElemType dataList[],int length); //把数据列表转换为节点列表
Status printBinaryNodeList(LinkBinaryNode binaryNodeList[],int length); //输出节点列表
LinkBinaryTree SearchLinkBinaryTree(LinkBinaryTree binaryTree,int key); //二叉排序树的递归查找
Status removeBinaryNode(LinkBinaryTree binaryTree,int key); //摘除二叉树排序树节点
