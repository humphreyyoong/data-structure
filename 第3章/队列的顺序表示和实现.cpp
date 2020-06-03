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
typedef struct{
	ElemType *elemList;
	int head;
	int tail;
}SqQueue;
Status initSqQueue(SqQueue &sqQueue){
	sqQueue.elemList=new ElemType[MAXSIZE];
	if(!sqQueue.elemList){
		cout<<"Fail:初始化失败"<<endl;
		exit(OVERFLOW);
	}
	sqQueue.head=0;
	sqQueue.tail=0;
	cout<<"Success:初始化成功"<<endl;
	return SUCCESS; 
}
int getLength(SqQueue sqQueue){
	int length=(sqQueue.tail+MAXSIZE-sqQueue.head)%MAXSIZE; 
	cout<<"Message:长度为"<<length<<endl;
	return length;
}
Status enQueue(SqQueue &sqQueue,ElemType e){
	if((sqQueue.tail+1)%MAXSIZE==sqQueue.head){
		cout<<"Fail:入队失败"<<endl;
		return FAIL;
	}
	sqQueue.elemList[sqQueue.tail]=e;
	sqQueue.tail=(sqQueue.tail+1)%MAXSIZE;
	cout<<"Success:入队成功"<<endl;
	return SUCCESS; 
}
Status deQueue(SqQueue &sqQueue,ElemType &e){
	if(sqQueue.head==sqQueue.tail){
		cout<<"Fail:队列为空,出队失败"<<endl;
		return FAIL;
	}
	e=sqQueue.elemList[sqQueue.head];
	sqQueue.head=(sqQueue.head+1)%MAXSIZE;
	cout<<"Success:出队成功"<<endl;
	return SUCCESS;
}
Status getHead(SqQueue &sqQueue,ElemType &e){
	if(sqQueue.head==sqQueue.tail){
		cout<<"Fail:队列为空,取队头失败"<<endl;
		return FAIL;
	}
	e=sqQueue.elemList[sqQueue.head];
	cout<<"Message:队头为"<<e<<endl;
	return SUCCESS;
}
Status printSqQueue(SqQueue sqQueue){
	int i,length=getLength(sqQueue);
	cout<<"+"; 
	for(i=0;i<length;i++){
		cout<<"---+";
	}
	cout<<endl;
	cout<<" ";
	while(sqQueue.head!=sqQueue.tail){
		cout<<" "<<sqQueue.elemList[sqQueue.head];
		if(sqQueue.head!=sqQueue.tail-1)cout<<" |";
		sqQueue.head=(sqQueue.head+1)%MAXSIZE;
	}
	cout<<endl;
	cout<<"+";
	for(i=0;i<length;i++){
		cout<<"---+";
	}
	cout<<endl<<"Success:输出成功"<<endl;
	return SUCCESS;
}
int main(){
	SqQueue sqQueue;
	initSqQueue(sqQueue);
	enQueue(sqQueue,'a');
	enQueue(sqQueue,'b');
	ElemType e;
	deQueue(sqQueue,e);
	enQueue(sqQueue,'a');
	enQueue(sqQueue,'c');
	printSqQueue(sqQueue);
	getHead(sqQueue,e);
	getLength(sqQueue);
	return 0;
} 
