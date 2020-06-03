//
//  LinkBinaryTree.cpp
//  二叉树的二叉链表
//
//  Created by 熊智宏 on 2020/3/11.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include "LinkBinaryTree.hpp"
//链树方法
Status initLinkBinaryTree(LinkBinaryTree &binaryTree){
    return SUCCESS;
}
Status visit(TreeElemType data){
    cout<<data;
     return SUCCESS;
}
Status preOrderTraverse(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return SUCCESS;
    }else{
        visit(binaryTree->data);
        preOrderTraverse(binaryTree->lchild);
        preOrderTraverse(binaryTree->rchild);
        return SUCCESS;
    }
}
Status inOrderTraverse(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return SUCCESS;
    }else{
        inOrderTraverse(binaryTree->lchild);
        visit(binaryTree->data);
        inOrderTraverse(binaryTree->rchild);
        return SUCCESS;
    }
}
Status postOrderTraverse(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return SUCCESS;
    }else{
        postOrderTraverse(binaryTree->lchild);
        postOrderTraverse(binaryTree->rchild);
        visit(binaryTree->data);
        return SUCCESS;
    }
}
Status inOrderTraverseWithoutRecursive(LinkBinaryTree binaryTree){
    LinkBinaryNode *p=binaryTree;
    LinkStack linkStack;
    initLinkStack(linkStack);
    while(p||linkStack!=NULL){
        if(p){
            push(linkStack, p->data);
            p=p->lchild;
        }else{
            TreeElemType data;
            pop(linkStack, data);
            visit(data);
            p=p->rchild;
        }
    }
    return SUCCESS;
}
Status levelOrderTraverse(LinkBinaryTree binaryTree){   //层次遍历
    LinkBinaryNode *p;
    LinkQueue linkQueue;
    initLinkQueue(linkQueue);
    enLinkQueue(linkQueue, binaryTree);
    while(getLength(linkQueue)>0){
        deLinkQueue(linkQueue, p);
        if(p->lchild)enLinkQueue(linkQueue,p->lchild);
        if(p->rchild)enLinkQueue(linkQueue,p->rchild);
        visit(p->data);
    }
    return SUCCESS;
}
Status createLinkBinaryTree(LinkBinaryTree &binaryTree){    //先序创建二叉树
    TreeElemType data;
    cin>>data;
    if(data=='#'){
        binaryTree=NULL;
    }else{
        if(!(binaryTree=new LinkBinaryNode()))exit(OVERFLOW);
        binaryTree->data=data;
        createLinkBinaryTree(binaryTree->lchild);
        createLinkBinaryTree(binaryTree->rchild);
    }
    return SUCCESS;
}
Status printLinkBinaryTree(LinkBinaryTree binaryTree){  //输出二叉树
       LinkQueue linkQueue;
       initLinkQueue(linkQueue);
       enLinkQueue(linkQueue, binaryTree);
       while(getLength(linkQueue)>0){
           deLinkQueue(linkQueue, binaryTree);
           if(binaryTree->lchild)enLinkQueue(linkQueue,binaryTree->lchild);
           if(binaryTree->rchild)enLinkQueue(linkQueue,binaryTree->rchild);
           visit(binaryTree->data);
       }
       return SUCCESS;
}
Status copy(LinkBinaryTree &binaryTree,LinkBinaryTree &newBinaryTree){
    if(binaryTree==NULL){
        newBinaryTree=NULL;
        return FAIL;
    }else{
        newBinaryTree=new LinkBinaryNode();
        newBinaryTree->data=binaryTree->data;
        copy(binaryTree->lchild,newBinaryTree->lchild);
        copy(binaryTree->rchild,newBinaryTree->rchild);
        return SUCCESS;
    }
}
int getDepth(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return 0;
    }else{
        int m=getDepth(binaryTree->lchild);
        int n=getDepth(binaryTree->rchild);
        if(m>n)return m+1;
        else return n+1;
    }
}
int getNodeCount(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return 0;
    }else{
        return getNodeCount(binaryTree->lchild)+
        getNodeCount(binaryTree->rchild)+1;
    }
}
int getLeafCount(LinkBinaryTree binaryTree){
    if(binaryTree==NULL){
        return 0;
    }else{
        if(binaryTree->rchild==NULL&&binaryTree->lchild==NULL){
            return 1;
        }else{
            int m=getLeafCount(binaryTree->lchild);
            int n=getLeafCount(binaryTree->rchild);
            return m+n;
        }
    }
}


//队列方法
Status initLinkQueue(LinkQueue &linkQueue){
    linkQueue.tail=linkQueue.head=new LinkQueueNode();
    if(!linkQueue.head){
        cout<<"Fail:硬件内存不足"<<endl;
        exit(OVERFLOW);
    }
    linkQueue.head->next=NULL;
    cout<<"Success:链队初始化成功"<<endl;
    return SUCCESS;
}
int getLength(LinkQueue linkQueue){
    LinkQueueNode *p=linkQueue.head->next;
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}
Status destroyLinkQueue(LinkQueue &linkQueue){
    while(linkQueue.head){
        LinkQueueNode *p=linkQueue.head->next;
        delete linkQueue.head;
        linkQueue.head=p;
    }
    cout<<"Success:链队销毁成功"<<endl;
    return SUCCESS;
}
Status enLinkQueue(LinkQueue &linkQueue,QueueElemType data){
    LinkQueueNode *p=new LinkQueueNode();
    if(!p){
        cout<<"Fail:内存不足，入队失败"<<endl;
        exit(OVERFLOW);
    }
    p->data=data;
    linkQueue.tail->next=p;
    linkQueue.tail=p;
//    cout<<"Succcess:入队成功"<<endl;
    return SUCCESS;
}
Status deLinkQueue(LinkQueue &linkQueue,QueueElemType &data){
    LinkQueueNode *p=linkQueue.head->next;
    if(!p){
        cout<<"Fail:链队为空，出队失败"<<endl;
        return FAIL;
    }
    data=p->data;
    linkQueue.head->next=p->next;
    if(p==linkQueue.tail)linkQueue.tail=linkQueue.head;
    delete p;
//    cout<<"Success:出队成功"<<endl;
    return SUCCESS;
}
Status getHead(LinkQueue &linkQueue,QueueElemType &data){
    if(linkQueue.head==linkQueue.tail){
        cout<<"Fail:链队为空，获取失败"<<endl;
        return FAIL;
    }
    data=linkQueue.head->next->data;
//    cout<<"Success:队头为:"<<data<<endl;
    return SUCCESS;
}
Status printLinkQueue(LinkQueue linkQueue){
    if(!linkQueue.head){
        cout<<"Fail:链队不存在，输出失败"<<endl;
        return FAIL;
    }
    if(linkQueue.head==linkQueue.tail){
        cout<<"Fail:链队为空，输出失败"<<endl;
        return FAIL;
    }
    LinkQueueNode *p=linkQueue.head->next;
    int length=getLength(linkQueue);
    int i=length;
    cout<<"+";
    while(i--){
        cout<<"---+";
    }
    cout<<endl<<"|";
    while(p){
//        cout<<" "<<p->data<<" |";
        p=p->next;
    }
    cout<<endl<<"+";
    i=length;
    while(i--){
        cout<<"---+";
    }
    cout<<endl;
    return SUCCESS;
}
