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
typedef struct{
	ElemType *top;
	ElemType *base;
	int stackSize;
}SqStack;
Status initSqStack(SqStack &sqStack){
	sqStack.base=new ElemType[MAXSIZE];
	if(!sqStack.base)exit(OVERFLOW);
	sqStack.top=sqStack.base;
	sqStack.stackSize=MAXSIZE;
	cout<<"Success:��ʼ���ɹ�"<<endl;
	return SUCCESS; 
}
Status isEmpty(SqStack sqStack){
	if(sqStack.top==sqStack.base){
		cout<<"Message:ջΪ��"<<endl;
		return true;
	}else{
		cout<<"Fail:ջ��Ϊ��"<<endl;
		return false;
	}
}
int getLength(SqStack sqStack){
	int length=0;
	length=sqStack.top-sqStack.base;
	cout<<"Message:����Ϊ"<<length<<endl;
	return length; 
}
Status clearSqStack(SqStack &sqStack){
	if(sqStack.base){
		sqStack.top=sqStack.base;
		cout<<"Success:�������ջ�ɹ�"<<endl;
		return SUCCESS; 
	}else{
		cout<<"Fail:�������ջʧ��"<<endl;
		return FAIL;
	}
}
Status destroySqStack(SqStack &sqStack){
	if(sqStack.base){
		delete[] sqStack.base;//�������������ˣ���˵new ElemType[]��delete[]Ҫƥ��ʹ�ã�����������Ч����֪��Ϊʲô�� 
		sqStack.stackSize=0;
		sqStack.base=sqStack.top=NULL;
		cout<<"Success:����˳��ջ�ɹ�"<<endl;
		return SUCCESS;
	}else{
		cout<<"Fail:����˳��ջʧ��"<<endl;
		return FAIL;
	}
}
Status push(SqStack &sqStack,ElemType e){
	if((sqStack.top-sqStack.base)!=sqStack.stackSize){
		*(sqStack.top)=e;
		cout<<"Success:��ջ�ɹ�"<<endl;
		sqStack.top++;
		return SUCCESS;
	}else{
		cout<<"Fail:��ջʧ��"<<endl;
		return FAIL;
	}
}
Status pop(SqStack &sqStack,ElemType &e){
	if(sqStack.top!=sqStack.base){
		sqStack.top--;
		e=*sqStack.top;	
		cout<<"Success:��ջ�ɹ�"<<endl;
		return SUCCESS;
	}else{
		cout<<"Fail:��ջʧ��"<<endl;
		return FAIL;
	}
}
Status printSqStack(SqStack sqStack){
	cout<<"+---+"<<endl;
	while(sqStack.top>sqStack.base){
		sqStack.top--;
		cout<<"| "<<*sqStack.top<<" |"<<endl; 
		cout<<"+---+"<<endl;
	}
	cout<<"Success:ջ����ɹ�"<<endl;
	return SUCCESS;
}
int main(){
	SqStack sqStack;
	initSqStack(sqStack);
	push(sqStack,'a');
	push(sqStack,'b');
	printSqStack(sqStack);	
	ElemType e;
	pop(sqStack,e);
	isEmpty(sqStack);
	getLength(sqStack);
	clearSqStack(sqStack);
	printSqStack(sqStack);
	destroySqStack(sqStack); 
	return 0;
}
