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
Status shellSort(SqList &sqList,int dlta[],int t){
    int k;
    for(k=t;k>=0;k--){ //从增量序列的大数开始
        shellInsert(sqList,dlta[k]);//一趟增量为dlta[k]的插入排序
    }
    return SUCCESS;
}
Status shellInsert(SqList &sqList,int dk){ //直接插入排序
    int i,j;
    //对顺序表L进行一趟增量为dk的Shell排序，dk为步长因子
    for(i=dk+1;i<=sqList.length;i++){
        if(sqList.baseAddress[i].key<sqList.baseAddress[i-dk].key){ //如果当前下标为i的key比下标为i-dk的值小则执行，否则当前位置不用改变
            sqList.baseAddress[0]=sqList.baseAddress[i]; //把下标为i的数据元素复制给哨兵
            for(j=i-dk;j>0&&sqList.baseAddress[0].key<sqList.baseAddress[j].key;j=j-dk){ //如果j的值大于0，并且哨兵的key小于下标为j的数据元素的key，则继续执行
                sqList.baseAddress[j+dk]=sqList.baseAddress[j]; //数据元素移动到下一个位置
            }
            sqList.baseAddress[j+dk]=sqList.baseAddress[0]; //哨兵复制到正确的位置
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

