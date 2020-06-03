#include<stdio.h>
#include<stdlib.h>
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
typedef struct{
	ElemType *baseAddress; 
	int length;
}SqList;
Status initSqList(SqList &sqList){
	sqList.baseAddress=new ElemType[MAXSIZE];
	sqList.length=0;
	if(!sqList.baseAddress){
		exit(OVERFLOW);
		printf("˳����ʼ��ʧ��\n");
		return FAIL;
	}
	else{
		printf("˳����ʼ���ɹ�\n");
		return SUCCESS;
	}
}
Status deleteSqList(SqList &sqList){
	if(sqList.baseAddress){
		delete sqList.baseAddress;
		printf("˳���ɾ���ɹ�\n");
		return SUCCESS;
	}else{
		printf("˳���ɾ��ʧ��\n");	
		return FAIL;
	}
	
}
Status clearSqList(SqList &sqList){
	sqList.length=0;
	printf("˳�����ճɹ�\n");
	return SUCCESS;
}
int getLength(SqList sqList){
	return sqList.length;	
}
int isEmpty(SqList sqList){
	if(sqList.length==0){
		printf("˳���Ϊ��\n"); 
		return TRUE;	
	}
	else{
		printf("˳���Ϊ��\n");
		return FALSE;	
	}
}
Status getElem(SqList sqList,int index,ElemType &elem){
	if(index>=1&&index<=sqList.length){
		elem=(sqList.baseAddress)[index-1];
		return TRUE;
	}
	else return FALSE;
}
int locateElem(SqList sqList,ElemType elem){
	int i;
	for(i=0;i<sqList.length;i++){
		if(sqList.baseAddress[i]==elem)return i+1;
	}
	return 0;
}
int insertElem(SqList &sqList,int index,ElemType elem){
	if(index>=1&&index<=sqList.length+1){
		int i;
		for(i=sqList.length-1;i>=index-1;i--){
			sqList.baseAddress[i+1]=sqList.baseAddress[i];
		}
		sqList.baseAddress[index-1]=elem;
		sqList.length++;
		printf("˳������ɹ�\n");
		return SUCCESS;
	}else{
		printf("˳������ʧ��\n");
		return FAIL;
	}
}
Status deleteElem(SqList &sqList,int index){
	if(index>=1&&index<=sqList.length+1){
		int i;
		for(i=index;i<=sqList.length-1;i++){
			sqList.baseAddress[i-1]=sqList.baseAddress[i];
		}
		sqList.length--;
		printf("Ԫ��ɾ���ɹ�\n");
		return SUCCESS;
	}
	else{
		printf("Ԫ��ɾ��ʧ��\n");
		return FAIL;
	}
}
Status unionSqList(SqList &sqList1,SqList &sqList2){
	int i;
	for(i=0;i<sqList2.length;i++){
		ElemType elem=sqList2.baseAddress[i];
		if(!locateElem(sqList1,elem)){
			insertElem(sqList1,sqList1.length+1,elem);
		}
	}
	printf("���Ա�ϲ��ɹ�\n");
	return SUCCESS;
}
Status mergeSqList(SqList sqList1,SqList sqList2,SqList &sqList3){
	int i=0,j=0,k=0; 
	sqList3.baseAddress=new ElemType[sqList1.length+sqList2.length];
	sqList3.length=0;
	while((i<sqList1.length)&&(j<sqList2.length)){
		if((sqList1.baseAddress[i])<(sqList2.baseAddress[j])){
			sqList3.baseAddress[k]=sqList1.baseAddress[i];
			i++;
		}else{
			sqList3.baseAddress[k]=sqList2.baseAddress[j];
			j++;
		}
		k++;
		sqList3.length++;
	}
	while(i<sqList1.length){
		sqList3.baseAddress[k]=sqList1.baseAddress[i];
		i++;
		k++;
		sqList3.length++; 
	}
	while(j<sqList2.length){
		sqList3.baseAddress[k]=sqList2.baseAddress[j];
		j++;
		k++;
		sqList3.length++;
	}
	printf("�����ϲ��ɹ�\n"); 
	return SUCCESS;
}
Status printSqList(SqList sqList){
	int i;
	for(i=0;i<sqList.length;i++){
		printf("%c\n",sqList.baseAddress[i]);
	}
	printf("˳�������ɹ�\n");
	return SUCCESS;
}
int main(){
	SqList sqList;
	initSqList(sqList);
	printf("%d\n",sqList.baseAddress);
	insertElem(sqList,1,'a');
	insertElem(sqList,2,'c');
	insertElem(sqList,3,'e');
//	insertElem(sqList,2,'b'); 
//	insertElem(sqList,2,'q'); 
	printSqList(sqList);
	
	SqList sqList2;
	initSqList(sqList2);
	printf("%d\n",sqList2.baseAddress);
	insertElem(sqList2,1,'b');
	insertElem(sqList2,2,'d');
	insertElem(sqList2,3,'f');
//	insertElem(sqList2,2,'t'); 
//	insertElem(sqList2,2,'u'); 
	printSqList(sqList2);
	SqList sqList3;
	mergeSqList(sqList,sqList2,sqList3);
	
	printSqList(sqList3);
	unionSqList(sqList,sqList2);
	printSqList(sqList);
//	deleteElem(sqList,2);
//	printSqList(sqList);
//	clearSqList(sqList);
//	isEmpty(sqList); 
//	deleteSqList(sqList);
//	printf("%d\n",sqList.baseAddress);
//	printSqList(sqList);
	return 0;
}
