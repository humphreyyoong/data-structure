//
//  LinkStack.hpp
//  二叉树的二叉链表
//
//  Created by 熊智宏 on 2020/3/11.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef LinkStack_hpp
#define LinkStack_hpp
#include "Header.h"
typedef char ElemType;
typedef struct LinkStackNode{
    ElemType data;
    struct LinkStackNode *next;
}LinkStackNode,*LinkStack;
Status initLinkStack(LinkStack &linkStack);
int isEmpty(LinkStack linkStack);
Status push(LinkStack &linkStack,ElemType e);
Status pop(LinkStack &linkStack,ElemType &e);
Status printLinkStack(LinkStack linkStack);
Status getTop(LinkStack linkStack,ElemType &e);
#endif /* LinkStack_hpp */
