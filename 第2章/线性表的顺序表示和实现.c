#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 1000
typedef int Status;
typedef char ElemType; 
typedef struct{
	char isbn[20];
	char name[30];
	int price;
}Book;
typedef struct{
	Book *baseAddress; 
	int length;
}SqList;
Status initSqList(SqList *sqList){
	sqList->baseAddress=(Book*)malloc(sizeof(Book)*MAXSIZE);
	sqList->length=0;
	if(!sqList->baseAddress){
		exit(OVERFLOW);
		return FAIL;
	}
	else{
		return SUCCESS;
	}
}
Status deleteSqList(SqList *sqList){
	if(sqList->baseAddress)free(sqList->baseAddress);
	return SUCCESS;
}
Status clearSqList(SqList *sqList){
	sqList->length=0;
	return SUCCESS;
}
int getLength(SqList sqList){
	return sqList.length;	
}
int isEmpty(SqList sqList){
	if(sqList.length==0)return TRUE;
	else return FALSE;
}
Status getBook(SqList sqList,int i,Book *book){
	if(i>=1&&i<=sqList.length){
		book=&((sqList.baseAddress)[i-1]);
		return TRUE;
	}
	else return FALSE;
}
int main(){
	SqList bookList;
	initSqList(&bookList);
	return;
}
