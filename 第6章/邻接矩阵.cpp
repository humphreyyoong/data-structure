#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100	//最大值 
#define ENDLESS 32767	//无穷大 
typedef int Status;
typedef char VertexType;	//顶点的类型 
typedef int ArcWeightType;		//边的权值类型 
typedef struct{
	VertexType vertexList[MAXSIZE];	//顶点表
	int visit[MAXSIZE];
	ArcWeightType weightList[MAXSIZE][MAXSIZE];	//邻接矩阵 
	int vertexNum,arcNum;	//顶点数和边数 
}AdjacencyMatrixGraph; 	//邻接矩阵图
int locateVertex(AdjacencyMatrixGraph graph,VertexType side1){
	int i;
	for(i=0;i<graph.vertexNum;i++){
		if(graph.vertexList[i]==side1)return i; 
	}
	return -1;
}
Status createAdjacencyMatrixGraph(AdjacencyMatrixGraph &graph){
	int i,j,weight;
	VertexType side1,side2;	//用来确定边权值的两个端点 
	int index1,index2 ; //两个端点在顶点表中的序号 
	cout<<"Operation:请输入节点数:";
	cin>>graph.vertexNum;
	cout<<"Operation:请输入边数:";
	cin>>graph.arcNum;
	for(i=0;i<graph.vertexNum;i++){			//输入每个顶点的值 
		cout<<"Operation:请输入第"<<i<<"个顶点的值:";
		cin>>graph.vertexList[i];
	}
	for(i=0;i<graph.vertexNum;i++){			//每个边的权值初始化为无穷。 
		for(j=0;j<graph.vertexNum;j++){
			graph.weightList[i][j]=ENDLESS;
		}
	}
	for(i=0;i<graph.vertexNum;i++){			//输入边的权值 
		cout<<"Operation:请输入第"<<i<<"条边的弧尾、权值、弧头:";
		cin>>side1>>weight>>side2;
		index1=locateVertex(graph,side1);
		index2=locateVertex(graph,side2);
		graph.weightList[index1][index2]=weight;
		graph.weightList[index2][index1]=weight;
	}
	for(i=0;i<graph.vertexNum;i++){
		graph.visit[i]=FALSE;
	}
	return SUCCESS;	
}
Status depthFirstSearch(AdjacencyMatrixGraph &graph,VertexType vertex){ //深度优先遍历 
	cout<<vertex<<endl;
	int index=locateVertex(graph,vertex);
	graph.visit[index]=TRUE;
	int i;
	for(i=0;i<graph.vertexNum;i++){
		VertexType arcTail=graph.vertexList[i];
		if((graph.weightList[index][i]!=ENDLESS)&&(graph.visit[i]!=TRUE))depthFirstSearch(graph,arcTail);
	}
	return SUCCESS;
}
Status printAdjacencyMatrixGraph(AdjacencyMatrixGraph &graph){
	int i,j;
	cout<<"顶点表"<<endl; 	//输出顶点表 
	for(i=0;i<graph.vertexNum;i++){		//输出顶点的序号 
		printf("  %d ",i);
	}
	cout<<endl;
	for(i=0;i<graph.vertexNum;i++){		//输出顶点表的框线 
		cout<<"+---";
	}
	cout<<"+"<<endl;
	for(i=0;i<graph.vertexNum;i++){		//输出顶点表的值 
		printf("| %C ",graph.vertexList[i]);
		
	}
	cout<<"|"<<endl;
	for(i=0;i<graph.vertexNum;i++){
		cout<<"+---";
	}
	cout<<"+"<<endl<<endl;
	
	
	cout<<"权值表"<<endl<<"  ";
	for(i=0;i<graph.vertexNum;i++){		//输出权值的横向顶点的序号 
		cout<<"  "<<i<<"  ";
	}
	cout<<endl<<"  ";
	for(i=0;i<graph.arcNum;i++){		//输出两个顶点之间的权值权值 
		for(j=0;j<graph.arcNum;j++){ 
		cout<<"+----";
		}
		cout<<"+"<<endl<<" "<<i;		//输出权值的纵向顶点的序号 
		for(j=0;j<graph.arcNum;j++){	 
			if(graph.weightList[i][j]==ENDLESS){
				printf("| ∞ "); 	//如果是32767就输出无穷符号 
			}else{
				printf("|%3d ",graph.weightList[i][j]);	
			} 
		}
		cout<<"|"<<endl<<"  ";
	}
	for(j=0;j<graph.arcNum;j++){		//输出权值表的最后一条边 
		cout<<"+----";
		}
		cout<<"+"<<endl;
} 
int main(){
	AdjacencyMatrixGraph graph;
	createAdjacencyMatrixGraph(graph);
	printAdjacencyMatrixGraph(graph);
	cout<<"Operation:请输入遍历的起始节点:";
	VertexType vertex;
	cin>>vertex;
	depthFirstSearch(graph,vertex);
	return 0;
}
