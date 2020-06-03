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
#define MAXSIZE 100	//���ֵ 
#define ENDLESS 32767	//����� 
typedef int Status;
typedef char VertexType;	//��������� 
typedef int ArcWeightType;		//�ߵ�Ȩֵ���� 
typedef struct ArcNode{
	int vertexIndex;
	ArcWeightType weight; 
	struct ArcNode *nextArc;
}ArcNode;
typedef struct VertexNode{
	VertexType data;	//������Ϣ 
	ArcNode *firstArc;	//ָ���һ������һ�˵Ľڵ� 
}VertexNode,AdjacencyList[MAXSIZE];
typedef struct{
	AdjacencyList vertexList;
	int vertexNum,arcNum;
}AdjacencyGraph;
int locateVertex(AdjacencyGraph graph,VertexType data){
	int i;
	for(i=0;i<graph.vertexNum;i++){
		if(graph.vertexList[i].data==data)return i;
	}
	return -1;
}
Status createAdjacencyGraph(AdjacencyGraph &graph){
	int i,tailIndex,headIndex;
	cout<<"Operation:�����붥����:";
	cin>>graph.vertexNum;
	cout<<"Operation:���������:";
	cin>>graph.arcNum;	
	for(i=0;i<graph.vertexNum;i++){	//���붥�㣬���ɶ���� 
		cout<<"Operation:�������"<<i+1<<"�����ֵ:";
		cin>>graph.vertexList[i].data;
		graph.vertexList[i].firstArc=NULL;
	}
	for(i=0;i<graph.arcNum;i++){	//��������ߵĶ��㣬��ʼ��Ϊ��β����һͷ�Ľڵ�Ϊ��ͷ 
		VertexType arcTail,arcHead;
		ArcWeightType weight; 
		cout<<"Operation:�������"<<i+1<<"�ߵı߻�β��Ȩ�ء���ͷ:";
		cin>>arcTail>>weight>>arcHead;
		ArcNode *node=new ArcNode();	//��β�ı�
		tailIndex=locateVertex(graph,arcTail); //��β�ڵ���±� 
		headIndex=locateVertex(graph,arcHead);
		headIndex=locateVertex(graph,arcHead);	//��ͷ�ڵ���±� 
		node->weight=weight;
		node->vertexIndex=headIndex; 
		node->nextArc=graph.vertexList[tailIndex].firstArc;	//�Ѷ���ڵ�ָ��ĵ�һ���ڵ� 
		graph.vertexList[tailIndex].firstArc=node;	//ǰ�巨���뵽�ڽӱ���
		
		ArcNode *node2=new ArcNode();	//��ͷ�ı� 
		node2->weight=weight;
		node2->vertexIndex=tailIndex; 
		node2->nextArc=graph.vertexList[headIndex].firstArc;	//�Ѷ���ڵ�ָ��ĵ�һ���ڵ� 
		graph.vertexList[headIndex].firstArc=node2;	//ǰ�巨���뵽�ڽӱ���
	}
	return 0;
}
Status breadthFirstSearch(AdjacencyGraph graph,VertexType){
	
}
Status printArcNodeBottomBorder(AdjacencyGraph graph,int index){	//����߱�ĵײ��߿� 
	int max=0,n1=0,n2=0,i;
	ArcNode *p;
		if(index!=graph.vertexNum-1){	//�ж��ǲ������һ������ 
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
			max=(n1>n2)?n1:n2; //�ж������ڵı߱�Ƚϳ�������һ���߱�Ƚϳ����Ӷ�ȷ���ױߵĳ��� 
			for(i=0;i<max;i++){	//����߱�ĵױ߿� 
				printf("    +----+----+"); 
			}
			cout<<endl;
		}else{	//���һ������ı߱�ĵױߵĳ��ȣ�Ϊ����ǰ�߱�ĳ��� 
			p=graph.vertexList[index].firstArc;
			while(p){
				printf("    +----+----+"); 
				p=p->nextArc;
			}
		}
}
Status depthFirstSearch(AdjacencyGraph graph,int index){ //������ȱ��� 
	
}
Status printAdjacencyGraph(AdjacencyGraph graph){	//�����ڽӱ� 
	int i=0,j;
	cout<<"  +----------+----------+"<<endl;
	cout<<"  |   data   | firstArc |"<<endl;
	cout<<"  +----------+----------+";
	ArcNode *p=graph.vertexList[0].firstArc;	//��1���߱���׵�ַ 
	while(p){	//�����±�Ϊ0�Ķ����ı߱�ı����ϱ߿� 
			printf("    +----+----+",p->vertexIndex); 
			p=p->nextArc;
		}
	cout<<endl;
	for(i=0;i<graph.vertexNum;i++){		
		printf(" %d|    %c     |      ",i,graph.vertexList[i].data); //��������Ĳ��� 
		p=graph.vertexList[i].firstArc;
		while(p){	//����߱�Ĳ��� 
			printf(" ---|--->| %2d |",p->vertexIndex); 
			p=p->nextArc;
		}
		cout<<"    |"<<endl<<"  +----------+----------+";
		printArcNodeBottomBorder(graph,i);	//����߱�ĵײ��߿� 	
	}
	return 0;
}
int main(){
	AdjacencyGraph graph;
	createAdjacencyGraph(graph);
	printAdjacencyGraph(graph);
	return 0;
}
