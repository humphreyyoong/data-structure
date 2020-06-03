//
//  LinkBinaryTree.hpp
//  二叉树的二叉链表
//
//  Created by 熊智宏 on 2020/3/11.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef LinkBinaryTree_hpp
#define LinkBinaryTree_hpp

#include <stdio.h>
#include "Header.h"
#include "LinkStack.hpp"
typedef char TreeElemType;
//链树
typedef struct LinkBinaryNode{
        TreeElemType data;
        struct LinkBinaryNode *lchild;
        struct LinkBinaryNode *rchild;
}LinkBinaryNode,*LinkBinaryTree;
//队列
typedef LinkBinaryNode *QueueElemType;
typedef struct LinkQueueNode{
    QueueElemType data;
    struct LinkQueueNode *next;
}LinkQueueNode;
typedef struct{
    LinkQueueNode *head;
    LinkQueueNode *tail;
}LinkQueue;
//链树方法
Status initLinkBinaryTree(LinkBinaryTree binaryTree);
Status visit(TreeElemType data);
Status preOrderTraverse(LinkBinaryTree binaryTree);
Status inOrderTraverse(LinkBinaryTree binaryTree);
Status postOrderTraverse(LinkBinaryTree binaryTree);
Status inOrderTraverseWithoutRecursive(LinkBinaryTree binaryTree);
Status levelOrderTraverse(LinkBinaryTree binaryTree);
Status createLinkBinaryTree(LinkBinaryTree &binaryTree);   //先序创建二叉树
Status printLinkBinaryTree(LinkBinaryTree binaryTree);  //输出二叉树
Status copy(LinkBinaryTree &binaryTree,LinkBinaryTree &newBinaryTree);//复制二叉树
int getDepth(LinkBinaryTree binaryTree);//获取二叉树深度
int getNodeCount(LinkBinaryTree binaryTree);//获取节点总数
int getLeafCount(LinkBinaryTree binaryTree);//获取叶子结点数
//队列方法
Status initLinkQueue(LinkQueue &linkQueue);
int getLength(LinkQueue linkQueue);
Status destroyLinkQueue(LinkQueue &linkQueue);
Status enLinkQueue(LinkQueue &linkQueue,QueueElemType data);
Status deLinkQueue(LinkQueue &linkQueue,QueueElemType &data);
Status getHead(LinkQueue &linkQueue,QueueElemType &data);
Status printLinkQueue(LinkQueue linkQueue);
#endif /* LinkBinaryTree_hpp */
