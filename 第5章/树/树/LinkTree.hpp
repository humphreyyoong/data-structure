//
//  LinkTree.hpp
//  树
//
//  Created by 熊智宏 on 2020/3/16.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef LinkTree_hpp
#define LinkTree_hpp

#include <stdio.h>
#include <stdio.h>
#include "global.h"
#define LINK_TREE_MAXSIZE 100
typedef char LinkTreeElemType;
typedef struct LinkTreeNode{
    int child;
    struct LinkTreeNode *next;
}LinkTreeNode;
typedef struct LinkTreeNodeBox{
    LinkTreeElemType elem;
    LinkTreeNode *firstChild;
}LinkTreeNodeBox;
typedef struct LinkTree{
    LinkTreeNodeBox nodeList[LINK_TREE_MAXSIZE];
    int total,root;
}LinkTree;
#endif /* LinkTree_hpp */
