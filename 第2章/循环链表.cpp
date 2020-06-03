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
	struct Node *next;
}Node,*LinkList;
Status initLinkList(LinkList &linkList){
	linkList=new Node;
	linkList->next=linkList;
	return SUCCESS;
}
int isEmpty(LinkList linkList){
	if(linkList->next==linkList)return TRUE;
	else return FALSE;
}
Status deleteLinkList(LinkList &linkList){
	Node *p=linkList;
	if(linkList->next!=linkList){
		linkList=linkList->next;
		delete p;
		p=linkList;
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
	if(p!=linkList){
		length++;
		p=p->next;
	}
	return length;
}
ElemType getElem(LinkList linkList,int index){
	Node *p=linkList->next;
	int currentIndex=0;
	while(p!=linkList&&index>=1){
		if(currentIndex!=index){
			currentIndex++;
			p++;
		}else{
			return p->elem;
		}	
	}
	return 0;
}
//Node* locateElem(LinkList linkList,ElemType elem){
//	Node *p=linkList->next;
//	while(p&&p->elem!=elem){
//		p=p->next;
//	}
//	return p;
//}
int locateElem(LinkList linkList,ElemType elem){
	Node *p=linkList->next;
	int index=1;
	while(p!=linkList){
		if(p->elem==elem){
			return index;
		}else{
			index++;
			p=p->next;
		}	
	}
	return 0;
}
Status insertNode(LinkList &linkList,int i,ElemType elem){
	Node *p=linkList;
	int index=0;
	while(p!=linkList&&index<i-1){
		p=p->next;
		index++;
	}	
	if(index!=i-1){
		printf("插入节点失败\n");
		return FAIL;
	}
	Node *s=new Node;
	s->elem=elem; 
	s->next=p->next;
	p->next=s;
	printf("插入节点成功\n");
	return SUCCESS;
}
Status deleteNode(LinkList &linkList,int i){
	Node *p=linkList;
	int index=0;
	while(p->next!=linkList&&index<i-1){
		p=p->next;
		index++;
	}	
	if((p->next==linkList)||index!=i-1){
		printf("删除节点失败\n");
		return FAIL;
	}
	Node *q=p->next;
	p->next=q->next;
	delete q; 
	printf("删除节点成功\n");
	return SUCCESS;
}
Status printLinkList(LinkList linkList){
	Node *p=linkList->next;
	printf("\n\n----\n"); 
	while(p!=linkList){
		printf("%c\n",p->elem);
		printf("----\n");
		p=p->next;
	}
	printf("\n\n"); 
	return SUCCESS;
}
Status createLinkList_H(LinkList &linkList,int n){
	linkList=new Node;
	linkList->next=NULL;
	int i;
	for(i=0;i<n;i++){
		Node *node=new Node; 
		cout<<"请输入第"<<i+1<<"个元素"<<endl; 
		cin>>node->elem;
		node->next=linkList->next;
		linkList->next=node;
	}
	return SUCCESS;
}
Status createLinkList_R(LinkList &linkList,int n){
	linkList=new Node;
	linkList->next=linkList;
	Node *p=linkList;
	int i;
	for(i=0;i<n;i++){
		Node *node=new Node;
		cout<<"请输入第"<<i+1<<"个元素"<<endl;
		cin>>node->elem;
		node->next=p->next;
		p->next=node;
		p=node;
	}
	return SUCCESS;
}
int main(){
	LinkList linkList;
	initLinkList(linkList);
	printf("%d\n",linkList);
	insertNode(linkList,1,'a');
	insertNode(linkList,2,'b');
	printLinkList(linkList);
	deleteNode(linkList,3);
	printf("请输入链表长度以创建新链表:");
	int n=0;
	cin>>n;
	createLinkList_R(linkList,n);
	printLinkList(linkList);
//	deleteLinkList(linkList);
//	printf("%d\n",linkList);
//	int length=getLength(linkList);
//	printf("链表的长度为:%d",length);
	return 0;
}
