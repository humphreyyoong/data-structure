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
Status adjustHeap(SqList &sqList,int start,int end){
    /*已知sqList[start...end]中记录的关键字除sqList.baseAddress[start]之外均满足堆的定义，本函数调整sqList.baseAddress[start]的关键字，使sqList.baseAddress[start...end]成为一个大根堆*/
    int i;
    ElemType temp;
    for(i=2*start;i<=end;i*=2){ //沿key较大的孩子节点向下筛选
        if(i<end&&sqList.baseAddress[i+1].key>sqList.baseAddress[i].key)i++;//i为key较大的记录的下标
        if(sqList.baseAddress[start].key>=sqList.baseAddress[i].key)break; //如果双亲节点比孩子节点都大则不用换位置，否则与较大的孩子节点调换位置
        temp=sqList.baseAddress[start];
        sqList.baseAddress[start]=sqList.baseAddress[i];
        sqList.baseAddress[i]=temp;
        start=i; //让开始的位置更新为i
    }
    return SUCCESS;
}
Status heapSort(SqList &sqList){
    int i;
    for(i=sqList.length/2;i>=1;i--){ //建立初始堆
        adjustHeap(sqList,i,sqList.length);
    }
    ElemType temp;
    for(i=sqList.length;i>=1;i--){ //把根节点抽出来放在顺序表的i的位置上，然后重新调整从1到i-1为范围的堆
        temp=sqList.baseAddress[1];
        sqList.baseAddress[1]=sqList.baseAddress[i];
        sqList.baseAddress[i]=temp;//根与堆中的最后一个元素交换
        adjustHeap(sqList,1,i-1); //对sqList.baseAddress[1]到[i-1]重新建立堆
    }
    return SUCCESS;
}
