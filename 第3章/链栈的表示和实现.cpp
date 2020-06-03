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
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkStack;
Status initLinkStack(LinkStack &linkList){
	linkList=NULL;
	cout<<"Success:��ջ��ʼ���ɹ�"<<endl;
	return SUCCESS;
}
int isEmpty(LinkStack linkList){
	if(linkList==NULL){
		cout<<"Message:��ջΪ��"<<endl;
		return SUCCESS;
	}else{
		cout<<"Message:��ջ��Ϊ��"<<endl;
		return FAIL;
	}
}
Status push(LinkStack &linkList,ElemType e){
	Node *p=new Node();
	p->data=e;
	p->next=linkList;
	linkList=p;
	cout<<"Message:��ջ�ɹ�"<<endl;
	return SUCCESS;
}
Status pop(LinkStack &linkList,ElemType &e){
	if(linkList){
		Node *p=linkList;
		e=p->data;
		linkList=p->next;
		delete p;
		cout<<"Success:��ջ�ɹ�"<<endl;
		return SUCCESS;
	}
	cout<<"Fail:��ջʧ��"<<endl;
	return FAIL;	
}
Status printLinkStack(LinkStack linkStack){
	cout<<"+   +"<<endl;
	while(linkStack){
		cout<<"| "<<linkStack->data<<" |"<<endl;
		cout<<"+---+"<<endl;
		linkStack=linkStack->next;
	}
	return SUCCESS;
}
Status getTop(LinkStack linkStack,ElemType &e){
	if(linkStack){
		e=linkStack->data;
		cout<<"Success:��ȡջ���ɹ�"<<endl;
		return SUCCESS;
	}else{
		cout<<"Fail:��ȡջ��ʧ��"<<endl;
	}
}
int main(){
	LinkStack linkStack;
	initLinkStack(linkStack);
	push(linkStack,'a');
	push(linkStack,'b');
	push(linkStack,'c');
	printLinkStack(linkStack);
	ElemType e;
	pop(linkStack,e);
	cout<<"Message:"<<e<<endl;
	getTop(linkStack,e);
	cout<<"Message:"<<e<<endl;
	printLinkStack(linkStack);
	isEmpty(linkStack);
	return 0;
} 
