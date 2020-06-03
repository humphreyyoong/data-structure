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
#define MAXSIZE 100
typedef int Status;
typedef char ElemType;
typedef struct BinaryNode{
		ElemType data;
		struct BinaryNode *lchild;
		struct BinaryNode *rchild;
}BinaryNode,*LinkBinaryTree;
Status initBinaryNode(LinkBinaryTree binaryTree){
	
}
Status visit(){
	
}
Status preOrderTraverse(LinkBinaryTree binaryTree){
	if(binaryTree==NULL){
		return SUCCESS;
	}else{
		visit();
		preOrderTraverse(binaryTree->lchild);
		preOrderTraverse(binaryTree->rchild);
		return SUCCESS;
	}
}
Status inOrderTraverse(LinkBinaryTree binaryTree){
	if(binaryTree==NULL){
		return SUCCESS;
	}else{
		inOrderTraverse(binaryTree->lchild);
		visit();
		inOrderTraverse(binaryTree->rchild);
	}
} 
Status postOrderTraverse(LinkBinaryTree binaryTree){
	if(binaryTree==NULL){
		return SUCCESS;
	}else{
		postOrderTraverse(binaryTree->lchild);
		postOrderTraverse(binaryTree->rchild);
		visit();
	}
}
int main(){
	LinkBinaryTree lchild; 
} 
