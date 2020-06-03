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
	linkList->next=NULL;
	return SUCCESS;
}
int isEmpty(LinkList linkList){
	if(linkList->next==NULL)return TRUE;
	else return FALSE;
}
Status deleteLinkList(LinkList &linkList){
	Node *p=linkList;
	if(linkList){
		linkList=linkList->next;
		delete p;
		p=linkList;
	}
	delete linkList;
	return SUCCESS;
}
Status clearLinkList(LinkList &linkList){
	Node *p=linkList->next,*q;
	while(p){
		q=p->next;
		delete p;
		p=q;
	}
	linkList->next=NULL;
	return SUCCESS;
}
int getLength(LinkList &linkList){
	Node *p=linkList->next;
	int length=0;
	while(p){
		length++;
		p=p->next;
	}
	return length;
}
ElemType getElem(LinkList linkList,int index){
	Node *p=linkList->next;
	int currentIndex=0;
	while(p&&index>=1){
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
	while(p){
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
	while(p&&index<i-1){
		p=p->next;
		index++;
	}	
	if(index!=i-1){
		printf("����ڵ�ʧ��\n");
		return FAIL;
	}
	Node *s=new Node;
	s->elem=elem; 
	s->next=p->next;
	p->next=s;
	printf("����ڵ�ɹ�\n");
	return SUCCESS;
}
Status deleteNode(LinkList &linkList,int i){
	Node *p=linkList;
	int index=0;
	while(p->next&&index<i-1){
		p=p->next;
		index++;
	}	
	if(!(p->next)||index!=i-1){
		printf("ɾ���ڵ�ʧ��\n");
		return FAIL;
	}
	Node *q=p->next;
	p->next=q->next;
	delete q; 
	printf("ɾ���ڵ�ɹ�\n");
	return SUCCESS;
}
Status unionLinkList(LinkList &linkList1,LinkList &linkList2){
	int i;
	Node *p1=linkList1->next;
	Node *p2=linkList2->next;
	int length1=getLength(linkList1);
	int length2=getLength(linkList2);
	ElemType elem;
	for(i=0;i<length2;i++){
		elem=p2->elem;
		if(!locateElem(linkList1,elem)){
			length1=getLength(linkList1);
			insertNode(linkList1,length1+1,elem);
		}
		p2=p2->next;
	}
	printf("����ϲ��ɹ�\n"); 
	return SUCCESS; 
}
Status mergeLinkList(LinkList &linkList1,LinkList &linkList2,LinkList &linkLink3){
	Node *pointer1=linkList1->next;
	Node *pointer2=linkList2->next;
	Node *pointer3=linkLink3=linkList1;
	while(pointer1&&pointer2){
		if(pointer2->elem<pointer1->elem){
			pointer3->next=pointer2;
			pointer2=pointer2->next;	
		}else{
			pointer3->next=pointer1;
			pointer1=pointer1->next;
		}
		pointer3=pointer3->next;
		cout<<"elem:"<<pointer3->elem<<endl;
	}
	pointer3->next=pointer1?pointer1:pointer2;
	delete linkList2; 
}
Status printLinkList(LinkList linkList){
	Node *p=linkList->next;
	printf("\n\n----\n"); 
	while(p){
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
		cout<<"�������"<<i+1<<"��Ԫ��"<<endl; 
		cin>>node->elem;
		node->next=linkList->next;
		linkList->next=node;
	}
	return SUCCESS;
}
Status createLinkList_R(LinkList &linkList,int n){
	linkList=new Node;
	linkList->next=NULL;
	Node *p=linkList;
	int i;
	for(i=0;i<n;i++){
		Node *node=new Node;
		cout<<"�������"<<i+1<<"��Ԫ��"<<endl;
		cin>>node->elem;
		node->next=NULL;
		p->next=node;
		p=node;
	}
	return SUCCESS;
}
int main(){
	LinkList linkList;
	initLinkList(linkList);
//	printf("%d\n",linkList);
	insertNode(linkList,1,'a');
	insertNode(linkList,2,'z');
	printLinkList(linkList);
//	deleteNode(linkList,3);
	
	LinkList linkList2;
	initLinkList(linkList2);
//	printf("%d\n",linkList2);
	insertNode(linkList2,1,'b');
	insertNode(linkList2,2,'x');
	printLinkList(linkList2);
	
//	unionLinkList(linkList,linkList2);
	LinkList linkList3;
	mergeLinkList(linkList,linkList2,linkList3);
	printLinkList(linkList3);
//	printf("�������������Դ���������:");
//	int n=0;
//	cin>>n;
//	createLinkList_R(linkList,n);
//	printLinkList(linkList);
//	deleteLinkList(linkList);
//	printf("%d\n",linkList);
//	int length=getLength(linkList);
//	printf("����ĳ���Ϊ:%d",length);
	return 0;
}
