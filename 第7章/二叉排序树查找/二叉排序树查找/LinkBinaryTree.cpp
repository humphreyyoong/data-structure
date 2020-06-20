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
