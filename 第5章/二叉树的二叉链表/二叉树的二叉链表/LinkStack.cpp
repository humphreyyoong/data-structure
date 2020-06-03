//
//  LinkStack.cpp
//  二叉树的二叉链表
//
//  Created by 熊智宏 on 2020/3/11.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include "LinkStack.hpp"
Status initLinkStack(LinkStack &linkStack){
    linkStack=NULL;
    cout<<"Success:链栈初始化成功"<<endl;
    return SUCCESS;
}
int isEmpty(LinkStack linkStack){
    if(linkStack==NULL){
        cout<<"Message:链栈为空"<<endl;
        return SUCCESS;
    }else{
        cout<<"Message:链栈不为空"<<endl;
        return FAIL;
    }
}
Status push(LinkStack &linkStack,ElemType e){
    LinkStackNode *p=new LinkStackNode();
    p->data=e;
    p->next=linkStack;
    linkStack=p;
    cout<<"Message:入栈成功"<<endl;
    return SUCCESS;
}
Status pop(LinkStack &linkStack,ElemType &e){
    if(linkStack){
        LinkStackNode *p=linkStack;
        e=p->data;
        linkStack=p->next;
        delete p;
        cout<<"Success:出栈成功"<<endl;
        return SUCCESS;
    }
    cout<<"Fail:入栈失败"<<endl;
    return FAIL;
}
Status printLinkStack(LinkStack linkStack){
    cout<<"+   +"<<endl;
    while(linkStack){
        cout<<"| "<<linkStack->data<<" |"<<endl;
        cout<<"+---+"<<endl;
        linkStack=linkStack->next;
    }
    return SUCCESS;
}
Status getTop(LinkStack linkStack,ElemType &e){
    if(linkStack){
        e=linkStack->data;
        cout<<"Success:获取栈顶成功"<<endl;
        return SUCCESS;
    }else{
        cout<<"Fail:获取栈顶失败"<<endl;
        return FAIL;
    }
}

