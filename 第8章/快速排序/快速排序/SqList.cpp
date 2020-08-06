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
Status printSqList(SqList sqList){//输出线性表
    int i;
    for(i=1;i<=sqList.length;i++){
        ElemType column=sqList.baseAddress[i];
        printf("%d,%s\n",column.key,column.name);
    }
    printf("顺序表输出成功\n");
    return SUCCESS;
}
int partition(SqList &sqList,int low,int high){ //排序并返回枢轴元素
    sqList.baseAddress[0]=sqList.baseAddress[low];
    int pivotkey=sqList.baseAddress[0].key; //把以low为下标的元素指定为枢轴元素
    while(low<high){
        while (low<high&&sqList.baseAddress[high].key>=pivotkey) { //如果当前指向元素的键值比枢轴元素的键值大，则下标减1
            high--;
        }
        sqList.baseAddress[low]=sqList.baseAddress[high];
        while (low<high&&sqList.baseAddress[low].key<=pivotkey) {//如果当前指向元素的键值比枢轴元素的键值小，则下标加1
            low++;
        }
        sqList.baseAddress[high]=sqList.baseAddress[low];
    }
    sqList.baseAddress[low]=sqList.baseAddress[0]; //low和high指向同一位置的时候，把哨兵放到当前位置
    return low; //返回枢轴元素的下标
}
Status quickSort(SqList &sqList,int low,int high){ //对顺序表L快速排序
    if(low<high){ //长度大于1
        int pivotloc=partition(sqList,low,high);
        //将L.r[low..high]一分为二，pivotloc为枢轴元素排序好序的位置
        quickSort(sqList, low, pivotloc-1); //对低子表递归排序
        quickSort(sqList, pivotloc+1, high); //对高子表递归排序
    }
    return SUCCESS;
}

