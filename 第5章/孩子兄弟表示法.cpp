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
typedef struct ChildSiblingNode{
	ElemType data;
	struct ChildBrotherNode *firstChild,*nextSibling;
}ChildSiblingNode,*ChildSiblingTree;
int main(){
	
} 
