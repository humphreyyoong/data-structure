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
#define MAXSIZE 10
typedef int Status;
typedef char ElemType;
typedef struct{
	ElemType data;
	int weight,parent,rchild,lchild;
}HuffmanNode,*HuffmanTree;
Status select(HuffmanTree tree,int end,int &min1,int &min2){
	int i,temp;
	min1=min2=0;	//min1��ʾ��СȨ�ؽڵ���±꣬min2��ʾ��С�ڵ���±꣬��Ϊ������±�0�Ŀռ䲻�ã����Գ�ʼ�±�Ϊ0 
	for(i=1;i<=end;i++){	//�±�Ϊ0�Ŀռ䲻�ã�ѭ����ָ��λ�� 
		if(tree[i].parent!=0)continue;	//�Ѿ��ϲ����Ľڵ������������ĸ�ڵ㲻Ϊ�գ������ýڵ� 
			if((tree[i].weight<tree[min1].weight)||(min1==0)){		//���min1��û�и�ֵ���ȸ�ֵ �����Ȩ�ر�min1��С 
				min2=min1;	//��ΪȨ����С��min1Ҫ����ֵ������Ҫ��min1��ֵҪ����Ȩ�ش�С��min2; 
				min1=i;		//����min1��ֵ 
			}else if((tree[i].weight<tree[min2].weight)||(min2==0)){	//���min2��û�и�ֵ���ȸ�ֵ �����Ȩ�ر�min2��С 
				min2=i;		//����min1��ֵ 
			}
	}
	return 0;
}
Status createHuffmanTree(HuffmanTree &tree,int n){ //������������ 
	if(n<=1)return FAIL;
	int i,m=2*n-1;
	tree=new HuffmanNode[m+1];			//0��λ�ò��� 
	for(i=1;i<=n;i++){					// �������ݺ�Ȩֵ 
		//cin>>tree[i].data;
		cin>>tree[i].weight;
	}
	for(i=1;i<=m;i++){				//��ʼ��ָ���Ӻ͸�ĸ�ڵ���±�����Ϊ0 
		tree[i].rchild=0;
		tree[i].lchild=0;
		tree[i].parent=0;
	}
	for(i=n+1;i<=m;i++){			//������������ 
		int min1,min2;				 
		select(tree,i-1,min1,min2);		//����Ȩ����С�ڵ���±� 
		tree[i].rchild=min1;		//��¼��ǰ�ڵ���Һ��� 
		tree[i].lchild=min2;		//��¼��ǰ�ڵ���Һ���  
		tree[i].weight=tree[min1].weight+tree[min2].weight;		//���õ�ǰ�ڵ��Ȩ�� 
		tree[min1].parent=i;		//���ú��ӽڵ�ĸ�ĸ�ڵ� 
		tree[min2].parent=i;		//���ú��ӽڵ�ĸ�ĸ�ڵ�
	}
	cout<<"m:"<<m<<endl;
	return SUCCESS;
}
Status printHuffmanTree(HuffmanTree tree,int size){
	size=size*2-1;
	int i;
	printf("     +------+------+------+------+\n");
	printf("index|weight|parent|lchild|rchild|\n");
	printf("     +------+------+------+------+\n");
	for(i=1;i<=size;i++){
		printf("%4d |%4d  |%4d  |%4d  |%4d  |\n",i,tree[i].weight,tree[i].parent,tree[i].lchild,tree[i].rchild);
		printf("     +------+------+------+------+\n");
	}
}
int main(){
	HuffmanTree tree;
	createHuffmanTree(tree,8);
	printHuffmanTree(tree,8);
	return 0;
}

