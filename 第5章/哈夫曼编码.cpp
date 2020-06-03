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
	float weight;
	int parent,rchild,lchild;
}HuffmanNode,*HuffmanTree;
typedef struct{
	ElemType data;
	char *huffmanCode;
}HuffmanCodeRow,*HuffmanCodeList;	//������������һ�� 
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
		cin>>tree[i].data;
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
	return SUCCESS;
}
Status createHuffmanCode(HuffmanTree tree,HuffmanCodeList &codeList,int size){
	int i=1,index,parent;
	char *string;
	int n=size;
	codeList=new HuffmanCodeRow[n+1];
	while((tree[i].lchild==0)&&(tree[i].rchild==0)){		//�����Ҷ�ӽڵ�ʹ������������룬�����Ӻ��Һ��Ӷ�Ϊ0�Ľڵ� 
		string=new char[size+1];
		string[n]='\0';									//��z 
		index=i;									 	//�����ڵ��±긳�������õ��±� 
		parent=tree[index].parent;						//�ѵ�ǰ�ĸ�ĸ�ڵ���±긳�����ݵĸ�ĸ�±� 
		while(parent!=0){								//���ݴ������������룬ֱ���ڵ��Ǹ��ڵ�Ϊֹ������ĸ�ڵ�Ϊ0�Ľڵ� 
			n--;
			if(tree[parent].lchild==index)string[n]='0';		//��������ӣ������ַ��������0 
			else string[n]='1';									//������Һ��ӣ������ַ��������1 
			index=parent;										//���ݵ��±�����ĸ�ڵ��ƶ� 
			parent=tree[parent].parent;							//ָ��ĸ��ָ��ָ��ĸ�ڵ�ĸ�ĸ�ڵ� 
		}
		codeList[i].data=tree[i].data;
		codeList[i].huffmanCode=string+n;			//�ѱ���ĵ�һ�ַ��ĵ�ַ���������ı����� 
		i++;
		n=size;
	}
	return SUCCESS;
} 
Status printHuffmanTree(HuffmanTree tree,int size){
	size=size*2-1;
	int i;
	printf("     +------+------+------+------+------+\n");
	printf("index| data |weight|parent|lchild|rchild|\n");
	printf("     +------+------+------+------+------+\n");
	for(i=1;i<=size;i++){
		printf("%4d |  %c   | %4.2f |%4d  |%4d  |%4d  |\n",i,tree[i].data,tree[i].weight,tree[i].parent,tree[i].lchild,tree[i].rchild);
		printf("     +------+------+------+------+------+\n");
	}
}
Status printHuffmanCode(HuffmanCodeList codeList,int size){
	int i;
	printf("     +------+------+\n");
	printf("index| data | code |\n");
	printf("     +------+------+\n");
	for(i=1;i<=size;i++){
			printf("%4d |  %c   |%-6s|\n",i,codeList[i].data,codeList[i].huffmanCode);
		printf("     +------+------+\n");
	}
	return SUCCESS;
}
int main(){
	HuffmanTree tree;
	HuffmanCodeList codeList;
	createHuffmanTree(tree,7);
	printHuffmanTree(tree,7);
	createHuffmanCode(tree,codeList,7);
	printHuffmanCode(codeList,7); 
/*	�����ʽΪ�� 
	A 0.4
	B 0.3
	C 0.15
	D 0.05
	E 0.04
	F 0.03
	G 0.03
	*/ 
	return 0;
}

