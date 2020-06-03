//
//  AdjacencyGraph.cpp
//  邻接表
//
//  Created by 熊智宏 on 2020/4/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include "AdjacencyGraph.hpp"
int locateVertex(AdjacencyGraph graph,VertexType data){
    int i;
    for(i=0;i<graph.vertexNum;i++){
        if(graph.vertexList[i].data==data)return i;
    }
    return -1;
}
Status createAdjacencyGraph(AdjacencyGraph &graph){ //创建邻接表
    int i,tailIndex,headIndex;
    cout<<"Operation:请输入顶点数:";
    cin>>graph.vertexNum;
    cout<<"Operation:请输入边数:";
    cin>>graph.arcNum;
    for(i=0;i<graph.vertexNum;i++){    //输入顶点，生成顶点表
        cout<<"Operation:请输入第"<<i+1<<"顶点的值:";
        cin>>graph.vertexList[i].data;
        graph.vertexList[i].firstArc=NULL;
    }
    for(i=0;i<graph.arcNum;i++){    //输入边两边的顶点，起始的为弧尾，另一头的节点为弧头
        VertexType arcTail,arcHead;
        ArcWeightType weight;
        cout<<"Operation:请输入第"<<i+1<<"边的边弧尾、权重、弧头:";
        cin>>arcTail>>weight>>arcHead;
        ArcNode *node=new ArcNode();    //弧尾的边
        tailIndex=locateVertex(graph,arcTail); //弧尾节点的下标
        headIndex=locateVertex(graph,arcHead);
        headIndex=locateVertex(graph,arcHead);    //弧头节点的下标
        node->weight=weight;
        node->vertexIndex=headIndex;
        node->nextArc=graph.vertexList[tailIndex].firstArc;    //把顶点节点指向的第一个节点
        graph.vertexList[tailIndex].firstArc=node;    //前插法插入到邻接表中
        
        ArcNode *node2=new ArcNode();    //弧头的边
        node2->weight=weight;
        node2->vertexIndex=tailIndex;
        node2->nextArc=graph.vertexList[headIndex].firstArc;    //把顶点节点指向的第一个节点
        graph.vertexList[headIndex].firstArc=node2;    //前插法插入到邻接表中
    }
    return 0;
}
Status breadthFirstSearch(AdjacencyGraph graph,VertexType vertex){  //广度优先遍历
    int i,visit[graph.vertexNum];   //声明一个记录是否访问过的数组
    for(i=0;i<graph.vertexNum;i++){ //初始化数组
        visit[i]=false;
    }
    LinkQueue queue;
    initLinkQueue(queue);   //初始化队列
    int index=locateVertex(graph, vertex);
    if(index==-1)return false;  //如果在顶点表中不存在该元素，停止运行，返回false值
    enLinkQueue(queue,index);   //如果存在则入队
    while(!isEmpty(queue)){ //如果队列不为空就继续执行
        deLinkQueue(queue,index);
        cout<<graph.vertexList[index].data<<endl;
        visit[index]=true;
        ArcNode *p=graph.vertexList[index].firstArc;
        while(p){   //把所有的与当前节点有联系的节点入队
            Status v=visit[p->vertexIndex]; //判断该元素是否访问过
            Status e=isExist(queue, p->vertexIndex);    //判断是否该元素时候存在于队列
            if(!v&&!e)enLinkQueue(queue, p->vertexIndex); //如果没有访问过，并且不在队列中，入队
            p=p->nextArc;
        }
    }
    return true;
}
Status printArcNodeBottomBorder(AdjacencyGraph graph,int index){    //输出边表的底部边框
    int max=0,n1=0,n2=0,i;
    ArcNode *p;
        if(index!=graph.vertexNum-1){    //判断是不是最后一个顶点
            p=graph.vertexList[index].firstArc;
            while(p){
                n1++;
                p=p->nextArc;
            }
            p=graph.vertexList[index+1].firstArc;
            while(p){
                n2++;
                p=p->nextArc;
            }
            max=(n1>n2)?n1:n2; //判断是现在的边表比较长还是下一个边表比较长，从而确定底边的长度
            for(i=0;i<max;i++){    //输出边表的底边框
                printf("    +----+----+");
            }
            cout<<endl;
        }else{    //最后一个顶点的边表的底边的长度，为，当前边表的长度
            p=graph.vertexList[index].firstArc;
            while(p){
                printf("    +----+----+");
                p=p->nextArc;
            }
        }
    return SUCCESS;
}
Status printAdjacencyGraph(AdjacencyGraph graph){    //输入邻接表
    int i=0;
    cout<<"  +----------+----------+"<<endl;
    cout<<"  |   data   | firstArc |"<<endl;
    cout<<"  +----------+----------+";
    ArcNode *p=graph.vertexList[0].firstArc;    //第1个边表的首地址
    while(p){    //输入下标为0的顶点表的边表的表格的上边框
            printf("    +----+----+");
            p=p->nextArc;
        }
    cout<<endl;
    for(i=0;i<graph.vertexNum;i++){
        printf(" %d|    %c     |      ",i,graph.vertexList[i].data); //输出顶点表的参数
        p=graph.vertexList[i].firstArc;
        while(p){    //输出边表的参数
            printf(" ---|--->| %2d |",p->vertexIndex);
            p=p->nextArc;
        }
        cout<<"    |"<<endl<<"  +----------+----------+";
        printArcNodeBottomBorder(graph,i);    //输出边表的底部边框
    }
    cout<<endl;
    return 0;
}
