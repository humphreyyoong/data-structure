//
//  AdjacencyGraph.hpp
//  邻接表
//
//  Created by 熊智宏 on 2020/4/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#ifndef AdjacencyGraph_hpp
#define AdjacencyGraph_hpp

#include "global.h"
#include "LinkQueue.hpp"
#endif /* AdjacencyGraph_hpp */

typedef struct ArcNode{
    int vertexIndex;
    ArcWeightType weight;
    struct ArcNode *nextArc;
}ArcNode;
typedef struct VertexNode{
    VertexType data;    //顶点信息
    ArcNode *firstArc;    //指向第一条弧另一端的节点
}VertexNode,AdjacencyList[MAXSIZE];
typedef struct{
    AdjacencyList vertexList;
    int vertexNum,arcNum;
}AdjacencyGraph;
int locateVertex(AdjacencyGraph graph,VertexType data); //查找顶点的下标
Status createAdjacencyGraph(AdjacencyGraph &graph); //创建邻接表
Status breadthFirstSearch(AdjacencyGraph graph,VertexType); //广度优先遍历
Status printArcNodeBottomBorder(AdjacencyGraph graph,int index);    //输出边表的底部边框
Status printAdjacencyGraph(AdjacencyGraph graph);    //输入邻接表
