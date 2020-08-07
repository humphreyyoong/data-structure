//
//  SqList.cpp
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
Status simpleSelectionSort(SqList &sqList){ //简单选择排序
    int i,j,index;
    for(i=1;i<sqList.length;i++){
        index=i;
        for(j=i+1;j<=sqList.length;j++){
            if(sqList.baseAddress[j].key<sqList.baseAddress[i].key){
                index=j; //记录最小值位置
            }
        }
        if(index!=i){ //如果有比下标为i的元素小的元素则交换位置
            sqList.baseAddress[0]=sqList.baseAddress[i]; //用哨兵的位置作为交换空间
            sqList.baseAddress[i]=sqList.baseAddress[index];
            sqList.baseAddress[index]=sqList.baseAddress[0];
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

