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
#define MAXSIZE 1000
typedef int Status;
typedef char ElemType; 
typedef struct Node{
	ElemType elem; 
	struct Node *prior,*next;
}Node,*LinkList;
Status initLinkList(LinkList &linkList){
	linkList=new Node;
	linkList->prior=linkList; 
	linkList->next=linkList;
	cout<<"Msg:初始化成功"<<endl;
	return SUCCESS;
}
int isEmpty(LinkList linkList){
	if(linkList->next==linkList){
		cout<<"Msg:为空"<<endl; 
		return TRUE;	
	}
	else{
		cout<<"Msg:不为空"<<endl; 
		return FALSE;
	}
}
Status deleteLinkList(LinkList &linkList){
	Node *head=linkList->next;
	Node *p=head;
	if(head->next!=head){
		head=head->next;
		delete p;
		p=head;
	}
	delete linkList;
	return SUCCESS;
}
Status clearLinkList(LinkList &linkList){
	Node *p=linkList->next,*q;
	while(p!=linkList){
		q=p->next;
		delete p;
		p=q;
	}
	linkList->next=NULL;
	return SUCCESS;
}
int getLength(LinkList linkList){
	Node *p=linkList->next;
	int length=0;
	while(p!=linkList){
		length++;
		p=p->next;
	}
	cout<<"Msg:长度为"<<length<<endl;
	return length;
}
Node *locateNode(LinkList &linkList,int i){
	Node *p=linkList->next;
	int index=1;
	while(index<i&&p!=linkList){
		p=p->next;
		index++;
	}
	if(index!=i)return NULL;
	else return p;
}
Status insertNode(LinkList &linkList,int i,ElemType elem){
	Node *p=locateNode(linkList,i);
	if(!p){
		cout<<"Msg:插入节点失败"<<endl; 
		return FAIL;	
	}
	Node *s=new Node;
	s->elem=elem;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	cout<<"Msg:插入节点成功"<<endl;
	return SUCCESS; 
}
Status deleteNode(LinkList &linkList,int i){
	Node *p=locateNode(linkList,i);
	if(!p){
		cout<<"Msg:删除节点失败"<<endl;
		return FAIL;
	}
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
	cout<<"msg:删除节点成功"<<endl;
	return SUCCESS;
} 
Status printLinkList(LinkList linkList){
	Node *p=linkList->next;
	printf("\n\n -----\n"); 
	while(p!=linkList){
		printf("|  %c  |\n",p->elem);
		printf(" -----\n");
		p=p->next;
	}
	printf("\n\n"); 
	return SUCCESS;
}
int main(){
	LinkList linkList;
	initLinkList(linkList);
	isEmpty(linkList);
	getLength(linkList);
	insertNode(linkList,1,'a');
	insertNode(linkList,2,'b');
	insertNode(linkList,3,'c');
	insertNode(linkList,4,'d');
	deleteNode(linkList,2);
	isEmpty(linkList);
	printLinkList(linkList);
	getLength(linkList);
	system("pause");
	return 0;
}
