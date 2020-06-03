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
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;
typedef struct{
	Node *head;
	Node *tail;
}LinkQueue;
Status initLinkQueue(LinkQueue &linkQueue){
	linkQueue.tail=linkQueue.head=new Node();
	if(!linkQueue.head){
		cout<<"Fail:Ӳ���ڴ治��"<<endl;		
		exit(OVERFLOW);	
	}
	linkQueue.head->next=NULL;
	cout<<"Success:���ӳ�ʼ���ɹ�"<<endl; 
	return SUCCESS;
}
int getLength(LinkQueue linkQueue){
	Node *p=linkQueue.head->next;
	int length=0;
	while(p){
		length++;
		p=p->next;
	}
	return length;
}
Status destroyLinkQueue(LinkQueue &linkQueue){
	while(linkQueue.head){
		Node *p=linkQueue.head->next;
		delete linkQueue.head;
		linkQueue.head=p;	
	}
	cout<<"Success:�������ٳɹ�"<<endl;
	return SUCCESS;
}
Status enLinkQueue(LinkQueue &linkQueue,ElemType data){
	Node *p=new Node();
	if(!p){
		cout<<"Fail:�ڴ治�㣬���ʧ��"<<endl;
		exit(OVERFLOW);
	}
	p->data=data;
	linkQueue.tail->next=p;
	linkQueue.tail=p;
	cout<<"Succcess:��ӳɹ�"<<endl;
	return SUCCESS;
}
Status deLinkQueue(LinkQueue &linkQueue,ElemType &data){
	Node *p=linkQueue.head->next;
	if(!p){
		cout<<"Fail:����Ϊ�գ�����ʧ��"<<endl;
		return FAIL;
	}
	data=p->data;
	linkQueue.head->next=p->next;
	if(p==linkQueue.tail)linkQueue.tail=linkQueue.head;
	delete p;
	cout<<"Success:���ӳɹ�"<<endl;
	return SUCCESS;
}
Status getHead(LinkQueue &linkQueue,ElemType &data){
	if(linkQueue.head==linkQueue.tail){
		cout<<"Fail:����Ϊ�գ���ȡʧ��"<<endl;
		return FAIL;
	}
	data=linkQueue.head->next->data;
	cout<<"Success:��ͷΪ:"<<data<<endl;
	return SUCCESS;
}
Status printLinkQueue(LinkQueue linkQueue){
	if(!linkQueue.head){
		cout<<"Fail:���Ӳ����ڣ����ʧ��"<<endl;
		return FAIL;
	}
	if(linkQueue.head==linkQueue.tail){
		cout<<"Fail:����Ϊ�գ����ʧ��"<<endl;
		return FAIL;
	}
	Node *p=linkQueue.head->next;
	int length=getLength(linkQueue);
	int i=length;
	cout<<"+";
	while(i--){
		cout<<"---+";
	}
	cout<<endl<<"|";
	while(p){
		cout<<" "<<p->data<<" |";
		p=p->next;
	}
	cout<<endl<<"+";
	i=length;
	while(i--){
		cout<<"---+";
	}
	cout<<endl;
	return SUCCESS;
}
int main(){
	LinkQueue linkQueue;
	initLinkQueue(linkQueue);
	printLinkQueue(linkQueue);
	enLinkQueue(linkQueue,'a');
	enLinkQueue(linkQueue,'b');
	enLinkQueue(linkQueue,'c');
	ElemType e;
	deLinkQueue(linkQueue,e);
	getHead(linkQueue,e); 
	printLinkQueue(linkQueue);
	destroyLinkQueue(linkQueue);
	printLinkQueue(linkQueue);
	return 0;	
};
