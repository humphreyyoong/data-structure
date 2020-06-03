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
	Node *head=linkList->next;
	Node *p=head->next,*q;
	while(p!=head){
		q=p->next;
		delete p;
		p=q;
	}
	head->next=NULL;
	return SUCCESS;
}
int getLength(LinkList linkList){
	Node *head=linkList->next;
	Node *p=head->next;
	int length=0;
	if(p!=head){
		length++;
		p=p->next;
	}
	return length;
}
ElemType getElem(LinkList linkList,int index){
	Node *head=linkList->next;
	Node *p=head->next;
	int currentIndex=0;
	while(p!=head&&index>=1){
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
	Node *head=linkList->next;
	Node *p=head->next;
	int index=1;
	while(p!=head){
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
	Node *head=linkList->next;
	Node *p;
	int index;
	if(i==1){
		p=head;
		index=0;
	}
	else{
		p=head->next;
		index=1;
		while(index<i-1&&p!=head){
			p=p->next;
			index++;
		}	
	}
	if(index!=i-1){
		printf("插入节点失败\n");
		return FAIL;
	}
	Node *s=new Node;
	s->elem=elem; 
	s->next=p->next;
	p->next=s;
	linkList=s;
	printf("插入节点成功\n");
	return SUCCESS;
}
Status deleteNode(LinkList &linkList,int i){
	Node *head=linkList->next;
	Node *p=head;
	int index=0;
	while(p->next!=head&&index<i-1){
		p=p->next;
		index++;
	}	
	if((p->next==head)||index!=i-1){
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
	Node *head=linkList->next;
	Node *p=head->next;
	printf("\n\n -----\n"); 
	while(p!=head){
		printf("|  %c  |\n",p->elem);
		printf(" -----\n");
		p=p->next;
	}
	printf("\n\n"); 
	return SUCCESS;
}
Status createLinkList_H(LinkList &linkList,int n){
	linkList=new Node;
	linkList->next=linkList;
	Node *head=linkList->next;
	int i;
	for(i=0;i<n;i++){
		Node *node=new Node; 
		cout<<"请输入第"<<i+1<<"个元素:"; 
		cin>>node->elem;
		node->next=head->next;
		head->next=node;
		linkList=node;
	}
	return SUCCESS;
}
Status createLinkList_R(LinkList &linkList,int n){
	linkList=new Node;
	linkList->next=linkList;
	Node *p=linkList->next;
	int i;
	for(i=0;i<n;i++){
		Node *node=new Node;
		cout<<"请输入第"<<i+1<<"个元素:";
		cin>>node->elem;
		node->next=p->next;
		p->next=node;
		p=node;
		linkList=node;
	}
	return SUCCESS;
}
Status merge(LinkList &linkList1,LinkList &linkList2){
	Node *p=linkList2->next;
	linkList2->next=linkList1->next;
	linkList1->next=p->next;	
	delete p;
	linkList1=linkList2;
} 
int main(){
	LinkList linkList;
	initLinkList(linkList);
	printf("%d\n",linkList);
//	Node *node1=new Node;
//	Node *node2=new Node;
//	node1->elem='a';
//	node2->elem='b';
//	node2->next=linkList->next;
//	node1->next=node2;
//	linkList=node2;
//	linkList->next->next=node1; 
	insertNode(linkList,1,'a');
	insertNode(linkList,2,'b');
	printLinkList(linkList);
	deleteNode(linkList,3);
	printf("请输入第一个链表长度以创建新链表:");
	int n=0;
	cin>>n;
	LinkList linkList1;
	createLinkList_R(linkList1,n);
	printLinkList(linkList1);
	
	printf("请输入第二个链表长度以创建新链表:");
	n=0;
	cin>>n;
	LinkList linkList2;
	createLinkList_R(linkList2,n);
	printLinkList(linkList2);
	
	merge(linkList1,linkList2);
	printLinkList(linkList1);
//	deleteLinkList(linkList);
//	printf("%d\n",linkList);
//	int length=getLength(linkList);
//	printf("链表的长度为:%d",length);
	return 0;
}
