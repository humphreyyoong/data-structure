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
Status splitInsertionSort(SqList &sqList){ //折半插入排序
    int i,j,low,mid,high;
    for(i=2;i<=sqList.length;i++){ //依次插入2～第n个元素
        sqList.baseAddress[0]=sqList.baseAddress[i]; //当前插入元素存到“哨兵”位置
        low=1;high=i-1; //采用二分查找法查找插入位置
        while(low<=high){
            mid=(low+high)/2;
            if(sqList.baseAddress[0].key<sqList.baseAddress[mid].key){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        } //循环结束，high+1 则为插入位置
        for(j=i-1;j>high;j--){
            sqList.baseAddress[j+1]=sqList.baseAddress[j]; //移动元素
        }
        sqList.baseAddress[high+1]=sqList.baseAddress[0]; //插入到正确位置
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

