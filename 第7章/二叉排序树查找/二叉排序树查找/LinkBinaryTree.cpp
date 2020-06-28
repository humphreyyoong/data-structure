//
//  LinkBinaryTree.cpp
//  二叉排序树查找
//
//  Created by 熊智宏 on 2020/6/17.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "LinkBinaryTree.hpp"
Status insertLinkBinaryNode(LinkBinaryTree &binaryTree,LinkBinaryNode &binaryNode){ //插入到二叉排序树 第一个参数需要&符号
    if(binaryTree==NULL){
        binaryTree=(&binaryNode);
        return SUCCESS;
    }else if(binaryNode.data.key<binaryTree->data.key){
        insertLinkBinaryNode(binaryTree->lchild,binaryNode);
        return SUCCESS;
    }else if(binaryNode.data.key>binaryTree->data.key){
         insertLinkBinaryNode(binaryTree->rchild,binaryNode);
        return SUCCESS;
    }else return FAIL;
}
Status createLinkBinaryTree(LinkBinaryTree &binaryTree,LinkBinaryNode binaryNodeList[],int length){ //创建二叉排序树
    int i;
    for(i=0;i<length;i++){
        insertLinkBinaryNode(binaryTree,binaryNodeList[i]);
    }
    return SUCCESS;
    
}
Status visit(ElemType data){
    cout<<data.key<<" "<<data.name<<endl;
     return SUCCESS;
}
Status inOrderTraverse(LinkBinaryTree binaryTree){ //中序遍历
    if(binaryTree==NULL){
        return SUCCESS;
    }else{
        inOrderTraverse(binaryTree->lchild);
        visit(binaryTree->data);
        inOrderTraverse(binaryTree->rchild);
        return SUCCESS;
    }
}
LinkBinaryNode* firstOfInOrderTraverse(LinkBinaryTree binaryTree){ //查找中序遍历中的第一节点
    if(binaryTree==NULL){
        return binaryTree;
    }else{
        LinkBinaryNode *lnode=firstOfInOrderTraverse(binaryTree->lchild);
        if(lnode!=NULL)return lnode;
        else return binaryTree;
    }
}
Status createElemTypeList(ElemType dataList[],int length){ //创建数据列表
    int i;
    for(i=0;i<length;i++){
        printf("请输入第%d组数据:\n",i+1);
        printf("    请输入主键:");
        scanf("%d",&dataList[i].key);
        printf("    请输入名字:");
        scanf("%s",dataList[i].name);
    }
    return SUCCESS;
}
Status printElemTypeList(ElemType dataList[],int length){ //输出数据列表
    int i;
    for(i=0;i<length;i++){
          printf("%d %s\n",dataList[i].key,dataList[i].name);
      }
    return SUCCESS;
}
Status toLinkBinaryNodeList(LinkBinaryNode binaryNodeList[],ElemType dataList[],int length){ //把数据列表转换为节点列表
    int i;
    for(i=0;i<length;i++){
        binaryNodeList[i].data.key=dataList[i].key;
        strcpy(binaryNodeList[i].data.name, dataList[i].name);
        binaryNodeList[i].rchild=NULL; //初始化左右孩子指针为NULL,不然会报错
        binaryNodeList[i].lchild=NULL;
    }
    return SUCCESS;
}
Status printBinaryNodeList(LinkBinaryNode binaryNodeList[],int length){ //输出节点列表
    int i;
    for(i=0;i<length;i++){
        printf("%d %s\n",binaryNodeList[i].data.key,binaryNodeList[i].data.name);
      }
    return SUCCESS;
}
LinkBinaryTree SearchLinkBinaryTree(LinkBinaryTree binaryTree,int key){  //二叉排序树的递归查找
    if(!binaryTree || key==binaryTree->data.key)return binaryTree;
    else{
        if(key<binaryTree->data.key)return SearchLinkBinaryTree(binaryTree->lchild, key);
        else return SearchLinkBinaryTree(binaryTree->rchild, key);
    }
}
Status removeBinaryNode(LinkBinaryTree binaryTree,int key){// 在二叉排序中摘除节点
    LinkBinaryTree parent=binaryTree; //父母节点
    while(key!=binaryTree->data.key && binaryTree!=NULL){
        parent=binaryTree;
        if(key<binaryTree->data.key)binaryTree=binaryTree->lchild;
        else binaryTree=binaryTree->rchild;
    }//查找与关键字匹配的节点
    if(binaryTree!=NULL){
        if(!binaryTree->lchild && !binaryTree->rchild){ //如果是叶子节点，直接删除
            if(parent->lchild==binaryTree)parent->lchild=NULL;
            else parent->rchild=NULL;
        }
        if(binaryTree->lchild && !binaryTree->rchild){ //如果是只有左孩子的节点，那就用左孩子顶替当前节点的位置
            if(parent->lchild==binaryTree)parent->lchild=binaryTree->lchild;
            else parent->rchild=binaryTree->lchild;
        }
        if(binaryTree->rchild && !binaryTree->lchild){ //如果是只有右孩子的节点，那就用右孩子顶替当前节点的位置
            if(parent->lchild==binaryTree)parent->lchild=binaryTree->rchild;
            else parent->rchild=binaryTree->rchild;
        }
        if(binaryTree->lchild && binaryTree->rchild){ //如果既有左孩子，又有右孩子
            LinkBinaryNode *node=firstOfInOrderTraverse(binaryTree->rchild); //查找要删除的节点的前驱节点，也就是后继节点
            removeBinaryNode(binaryTree, node->data.key); //摘除这个后继节点
            if(parent->lchild==binaryTree)parent->lchild=node; //把 这个节点 挂接到 当前要删除节点的父母节点 中
            else parent->rchild=node;
        }
        return SUCCESS;
    }
    return FAIL;
}
