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
typedef struct{
	VertexType vertexList[MAXSIZE];	//�����
	int visit[MAXSIZE];
	ArcWeightType weightList[MAXSIZE][MAXSIZE];	//�ڽӾ��� 
	int vertexNum,arcNum;	//�������ͱ��� 
}AdjacencyMatrixGraph; 	//�ڽӾ���ͼ
int locateVertex(AdjacencyMatrixGraph graph,VertexType side1){
	int i;
	for(i=0;i<graph.vertexNum;i++){
		if(graph.vertexList[i]==side1)return i; 
	}
	return -1;
}
Status createAdjacencyMatrixGraph(AdjacencyMatrixGraph &graph){
	int i,j,weight;
	VertexType side1,side2;	//����ȷ����Ȩֵ�������˵� 
	int index1,index2 ; //�����˵��ڶ�����е���� 
	cout<<"Operation:������ڵ���:";
	cin>>graph.vertexNum;
	cout<<"Operation:���������:";
	cin>>graph.arcNum;
	for(i=0;i<graph.vertexNum;i++){			//����ÿ�������ֵ 
		cout<<"Operation:�������"<<i<<"�������ֵ:";
		cin>>graph.vertexList[i];
	}
	for(i=0;i<graph.vertexNum;i++){			//ÿ���ߵ�Ȩֵ��ʼ��Ϊ��� 
		for(j=0;j<graph.vertexNum;j++){
			graph.weightList[i][j]=ENDLESS;
		}
	}
	for(i=0;i<graph.vertexNum;i++){			//����ߵ�Ȩֵ 
		cout<<"Operation:�������"<<i<<"���ߵĻ�β��Ȩֵ����ͷ:";
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
Status depthFirstSearch(AdjacencyMatrixGraph &graph,VertexType vertex){ //������ȱ��� 
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
	cout<<"�����"<<endl; 	//�������� 
	for(i=0;i<graph.vertexNum;i++){		//����������� 
		printf("  %d ",i);
	}
	cout<<endl;
	for(i=0;i<graph.vertexNum;i++){		//��������Ŀ��� 
		cout<<"+---";
	}
	cout<<"+"<<endl;
	for(i=0;i<graph.vertexNum;i++){		//���������ֵ 
		printf("| %C ",graph.vertexList[i]);
		
	}
	cout<<"|"<<endl;
	for(i=0;i<graph.vertexNum;i++){
		cout<<"+---";
	}
	cout<<"+"<<endl<<endl;
	
	
	cout<<"Ȩֵ��"<<endl<<"  ";
	for(i=0;i<graph.vertexNum;i++){		//���Ȩֵ�ĺ��򶥵����� 
		cout<<"  "<<i<<"  ";
	}
	cout<<endl<<"  ";
	for(i=0;i<graph.arcNum;i++){		//�����������֮���ȨֵȨֵ 
		for(j=0;j<graph.arcNum;j++){ 
		cout<<"+----";
		}
		cout<<"+"<<endl<<" "<<i;		//���Ȩֵ�����򶥵����� 
		for(j=0;j<graph.arcNum;j++){	 
			if(graph.weightList[i][j]==ENDLESS){
				printf("| �� "); 	//�����32767������������ 
			}else{
				printf("|%3d ",graph.weightList[i][j]);	
			} 
		}
		cout<<"|"<<endl<<"  ";
	}
	for(j=0;j<graph.arcNum;j++){		//���Ȩֵ������һ���� 
		cout<<"+----";
		}
		cout<<"+"<<endl;
} 
int main(){
	AdjacencyMatrixGraph graph;
	createAdjacencyMatrixGraph(graph);
	printAdjacencyMatrixGraph(graph);
	cout<<"Operation:�������������ʼ�ڵ�:";
	VertexType vertex;
	cin>>vertex;
	depthFirstSearch(graph,vertex);
	return 0;
}
