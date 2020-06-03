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
}HuffmanCodeRow,*HuffmanCodeList;	//哈夫曼编码表的一行 
Status select(HuffmanTree tree,int end,int &min1,int &min2){
	int i,temp;
	min1=min2=0;	//min1表示最小权重节点的下标，min2表示次小节点的下标，因为数组的下标0的空间不用，所以初始下标为0 
	for(i=1;i<=end;i++){	//下标为0的空间不用，循环到指定位置 
		if(tree[i].parent!=0)continue;	//已经合并过的节点跳过，如果父母节点不为空，跳过该节点 
			if((tree[i].weight<tree[min1].weight)||(min1==0)){		//如果min1还没有赋值，先赋值 ，如果权重比min1的小 
				min2=min1;	//因为权重最小的min1要赋新值，所以要把min1的值要赋给权重次小的min2; 
				min1=i;		//更改min1的值 
			}else if((tree[i].weight<tree[min2].weight)||(min2==0)){	//如果min2还没有赋值，先赋值 ，如果权重比min2的小 
				min2=i;		//更改min1的值 
			}
	}
	return 0;
}
Status createHuffmanTree(HuffmanTree &tree,int n){ //创建哈夫曼树 
	if(n<=1)return FAIL;
	int i,m=2*n-1;
	tree=new HuffmanNode[m+1];			//0的位置不用 
	for(i=1;i<=n;i++){					// 输入数据和权值 
		cin>>tree[i].data;
		cin>>tree[i].weight;
	}
	for(i=1;i<=m;i++){				//初始化指向孩子和父母节点的下标设置为0 
		tree[i].rchild=0;
		tree[i].lchild=0;
		tree[i].parent=0;
	}
	for(i=n+1;i<=m;i++){			//构建哈夫曼树 
		int min1,min2;				 
		select(tree,i-1,min1,min2);		//查找权重最小节点的下标 
		tree[i].rchild=min1;		//记录当前节点的右孩子 
		tree[i].lchild=min2;		//记录当前节点的右孩子  
		tree[i].weight=tree[min1].weight+tree[min2].weight;		//设置当前节点的权重 
		tree[min1].parent=i;		//设置孩子节点的父母节点 
		tree[min2].parent=i;		//设置孩子节点的父母节点
	}
	return SUCCESS;
}
Status createHuffmanCode(HuffmanTree tree,HuffmanCodeList &codeList,int size){
	int i=1,index,parent;
	char *string;
	int n=size;
	codeList=new HuffmanCodeRow[n+1];
	while((tree[i].lchild==0)&&(tree[i].rchild==0)){		//如果是叶子节点就创建哈夫曼编码，即左孩子和右孩子都为0的节点 
		string=new char[size+1];
		string[n]='\0';									//把z 
		index=i;									 	//把现在的下标赋给回溯用的下标 
		parent=tree[index].parent;						//把当前的父母节点的下标赋给回溯的父母下标 
		while(parent!=0){								//回溯创建哈夫曼编码，直到节点是跟节点为止，即父母节点为0的节点 
			n--;
			if(tree[parent].lchild==index)string[n]='0';		//如果是左孩子，就在字符串上添加0 
			else string[n]='1';									//如果是右孩子，就在字符串上添加1 
			index=parent;										//回溯的下边往父母节点移动 
			parent=tree[parent].parent;							//指向父母的指正指向父母节点的父母节点 
		}
		codeList[i].data=tree[i].data;
		codeList[i].huffmanCode=string+n;			//把编码的第一字符的地址赋给编码表的编码行 
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
/*	输入格式为： 
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

