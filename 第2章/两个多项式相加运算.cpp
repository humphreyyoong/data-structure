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
typedef struct{
	int *baseAddress; 
	int length;
}Polynomial;
Status initPolynomial(Polynomial &polynomial){
	polynomial.baseAddress=new int[MAXSIZE];
	polynomial.length=0;
	if(!polynomial.baseAddress){
		exit(OVERFLOW);
		printf("Msg:����ʽ��ʼ��ʧ��\n");
		return FAIL;
	}
	else{
		printf("Msg:����ʽ��ʼ���ɹ�\n");
		return SUCCESS;
	}
}
int insertPolyn(Polynomial &polynomial,int index,float coefficient){
	if(index>=1&&index<=polynomial.length+1){
		int i;
		for(i=polynomial.length-1;i>=index-1;i--){
			polynomial.baseAddress[i+1]=polynomial.baseAddress[i];
		}
		polynomial.baseAddress[index-1]=coefficient;
		polynomial.length++;
		printf("Msg:˳������ɹ�\n");
		return SUCCESS;
	}else{
		printf("Msg:˳������ʧ��\n");
		return FAIL;
	}
}
Status inputPolynomial(Polynomial &polynomial){
	
	
}
int main(){
	Polynomial polynomial1;
	initPolynomial(polynomial1);
	return 0;
}
