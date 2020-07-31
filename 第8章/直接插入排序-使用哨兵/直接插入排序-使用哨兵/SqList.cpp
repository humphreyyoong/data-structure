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
Status directInsertionSortByUseSentry(SqList &sqList){ //使用了哨兵的直接插入排序
    int i,j,k;
    for(i=2;i<=sqList.length;i++){ //遍历未排序的数据元素
        sqList.baseAddress[0]=sqList.baseAddress[i];
        for(j=i-1,k=i;k>=1;k--,j--){ //遍历已排序的数据元素
            if(sqList.baseAddress[0].key<sqList.baseAddress[j].key){ //如果 哨兵 比 当前已排序的数据元素 小，则把已排序的数据元素移动到k位置上
                sqList.baseAddress[k]=sqList.baseAddress[j];
            }else{ //如果 哨兵 比 当前已排序的数据元素 大，则把哨兵直接插到k位置上
                sqList.baseAddress[k]=sqList.baseAddress[0];
                break;
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

