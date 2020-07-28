//
//  AdjacencyGraph.hpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/28.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#ifndef AdjacencyGraph_hpp
#define AdjacencyGraph_hpp

#include <stdio.h>
#include "global.h"
typedef struct DataNode{
    int key;
    String name;
    struct ArcNode *nextData;
}DataNode;
typedef struct IndexNode{
    ArcNode *firstArc;    //指向第一条弧另一端的节点
}IndexNode;
typedef struct{
    IndexNode *indexNodeList;
    int indexNodeNum;
}AdjacencyList;
#endif /* AdjacencyGraph_hpp */
