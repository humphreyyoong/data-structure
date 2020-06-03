#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	char data[MAXSIZE+1];
	int length;
}SqString;
Status scanSqString(SqString &sqString){
	scanf("%s",&sqString.data[1]);
	sqString.length=strlen(sqString.data)-1; 
	return SUCCESS; 
}
Status printSqString(SqString sqString){
	printf("%s\n",&sqString.data[1]);
	printf("Message:³¤¶ÈÎª%d\n",sqString.length);
	return SUCCESS;
}
int indexBF(SqString &sqString1,SqString &sqString2){
	int i=1,j=1;
	while(i<=sqString1.length&&j<=sqString2.length){
		if(sqString1.data[i]==sqString2.data[j]){
			i++;j++;		
		}else{
			i=i-j+2;
			j=1;
		}
	}
	if(j>sqString2.length){
		cout<<"Message:index="<<i-j+1<<endl;
		return i-j+1;
	}else{
		cout<<"Message:index=0"<<endl;
		return 0;
	}	
}
int main(){
	SqString sqString1;
	scanSqString(sqString1); 
	SqString sqString2;
	scanSqString(sqString2);
//	printSqString(sqString1);
//	printSqString(sqString2);
	indexBF(sqString1,sqString2);
	return 0;
}
