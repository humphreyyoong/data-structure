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
Status merge(SqList &sqList,int left,int mid,int right){ //合并sqList中下标为lefr到mid，和下标为mid+1到right的两个部分，即两个子表
    int length=right-left+1; //两个子表一共多长
    ElemType tempArray[length]; //创建一个临时的ElemType数组,从0号位置开始放数据元素
    int i; //指向顺序表sqList的下标，用来遍历顺序表sqList
    int j=left; //指向顺序表sqList最左边的下标，即第一个子表的起始位置
    int k=mid+1; //指向顺序表sqList中间+1的下标，即第二个子表的起始位置
    int index; //指向临时数组tempArray的下标,用来遍历临时数组tempArray
    for(index=0;index<length;index++){
        if(j>mid){ //如果第一子表已经遍历完成，则把第二个子表的数据元素依次放到临时数组的后面
            tempArray[index]=sqList.baseAddress[k];
            k++; //指向第二个子表的下标后移一位
        }else if(k>right){ //如果第二子表已经遍历完成，则把第一个子表的数据元素依次放到临时数组的后面
            tempArray[index]=sqList.baseAddress[j];
            j++; //指向第一个子表的下标后移一位
        }else if(sqList.baseAddress[j].key>sqList.baseAddress[k].key){ //如果 第一个子表当前数据元素的键值 比 第二个子表当前数据元素的键值 大，则把二个子表当前的数据元素复制到临时数组上
            tempArray[index]=sqList.baseAddress[k];
            k++; //指向第二个子表的下标后移一位
        }else if(sqList.baseAddress[j].key<sqList.baseAddress[k].key){ //如果 第二个子表当前数据元素的键值 比 第一个子表当前数据元素的键值 大，则把一个子表当前的数据元素复制到临时数组上
            tempArray[index]=sqList.baseAddress[j];
            j++; //指向第一个子表的下标后移一位
        }
    }
    for(i=left,index=0;index<length;i++,index++){ //把排好序的临时数组tempArray的数据元素依次复制到顺序表sqList对应的位置上
        sqList.baseAddress[i]=tempArray[index];
    }
    return SUCCESS;
}
Status mergeSort(SqList &sqList,int left,int right){ //归并排序
    if(left<right){ //如果指向第一个子表的下标比指向第二哥子表的下标小则执行
        int mid=(left+right)/2; //获取顺表表sqList的中间位置
        mergeSort(sqList,left,mid); //对第一个子表进行归并排序
        mergeSort(sqList,mid+1,right); //对第二个子表进行归并排序
        merge(sqList,left,mid,right); //合并两个子表
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

