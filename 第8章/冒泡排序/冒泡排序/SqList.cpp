//
//  SqList.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/24.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "SqList.hpp"
Status initSqList(SqList &sqList){
    sqList.baseAddress=new ElemType[MAXSIZE+1];
    sqList.length=0;
    if(!sqList.baseAddress){
        printf("顺序表初始化失败\n");
        exit(OVERFLOW);
        return FAIL;
    }
    else{
        printf("顺序表初始化成功\n");
        return SUCCESS;
    }
}
int insertElem(SqList &sqList,int index,ElemType elem){
    if(index>=1&&index<=sqList.length+1){ //如果插入的位置在合理范围，即大于1和小于长度+1
        int i;
        for(i=sqList.length;i>=index;i--){
            sqList.baseAddress[i+1]=sqList.baseAddress[i];
        }
        sqList.baseAddress[index]=elem;
        sqList.length++;
        printf("顺序表插入成功\n");
        return SUCCESS;
    }else{
        printf("顺序表插入失败\n");
        return FAIL;
    }
}
Status bubbleSort(SqList &sqList){ //正序冒泡排序
    int i,j;
    for(i=sqList.length;i>=1;i--){
        for(j=1;j<i;j++){
            if(sqList.baseAddress[j].key>sqList.baseAddress[j+1].key){
                ElemType temp=sqList.baseAddress[j];
                sqList.baseAddress[j]=sqList.baseAddress[j+1]; //交换
                sqList.baseAddress[j+1]=temp;
            }
        }
    }
    return SUCCESS;
}
Status bubbleSortByAscending(SqList &sqList){ //改进的升序冒泡排序
    int i,j,flag=1; //flag作为是否有交换的标记
    for(i=sqList.length;i>=1&&flag==1;i--){
        flag=0;
        for(j=1;j<i;j++){
            if(sqList.baseAddress[j].key>sqList.baseAddress[j+1].key){
                flag=1; //发生交换，flag置为1，若本趟没发生交换，flag保持为0
                ElemType temp=sqList.baseAddress[j];
                sqList.baseAddress[j]=sqList.baseAddress[j+1]; //交换
                sqList.baseAddress[j+1]=temp;
            }
        }
    }
    return SUCCESS;
}
Status bubbleSortByDescending(SqList &sqList){ //改进的降序冒泡排序
    int i,j,flag=1; //flag作为是否有交换的标记
    for(i=sqList.length;i>=1&&flag==1;i--){
        flag=0;
        for(j=1;j<i;j++){
            if(sqList.baseAddress[j].key<sqList.baseAddress[j+1].key){
                flag=1; //发生交换，flag置为1，若本趟没发生交换，flag保持为0
                ElemType temp=sqList.baseAddress[j];
                sqList.baseAddress[j]=sqList.baseAddress[j+1]; //交换
                sqList.baseAddress[j+1]=temp;
            }
        }
    }
    return SUCCESS;
}
Status printSqList(SqList sqList){//输出线性表
    int i;
    for(i=1;i<=sqList.length;i++){
        ElemType column=sqList.baseAddress[i];
        printf("%d,%s\n",column.key,column.name);
    }
    printf("顺序表输出成功\n");
    return SUCCESS;
}

