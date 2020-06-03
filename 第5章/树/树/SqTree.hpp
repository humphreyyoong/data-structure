//
//  SqTree.hpp
//  树
//
//  Created by 熊智宏 on 2020/3/15.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef SqTree_hpp
#define SqTree_hpp

#include <stdio.h>
#include "global.h"
#define SQ_TREE_MAXSIZE 100
typedef char SqTreeElemType;
typedef struct SqTreeNode{
    SqTreeElemType data;
    int parent;
}SqTreeNode;
typedef struct{
    SqTreeNode nodeList[SQ_TREE_MAXSIZE];
    int r,n;
}SqTree;
#endif /* SqTree_hpp */
