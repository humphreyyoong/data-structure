//
//  main.cpp
//  邻接表
//
//  Created by 熊智宏 on 2020/4/12.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include "AdjacencyGraph.hpp"
int main(){
    AdjacencyGraph graph;
    createAdjacencyGraph(graph);
    printAdjacencyGraph(graph);
    breadthFirstSearch(graph,'a');
    return 0;
}
