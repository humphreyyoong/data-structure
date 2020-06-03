//
//  SqList.cpp
//  线性表的查找
//
//  Created by 熊智宏 on 2020/5/13.
//  Copyright © 2020 熊智宏. All rights reserved.
//

#include "SqList.hpp"
Status initSqList(SqList &sqList){
    sqList.baseAddress=new ElemType[MAXSIZE+1];
    sqList.length=0;
    if(!sqList.baseAddress){
        exit(OVERFLOW);
        printf("顺序表初始化失败\n");
        return FAIL;
    }
    else{
        printf("顺序表初始化成功\n");
        return SUCCESS;
    }
}
Status deleteSqList(SqList &sqList){
    if(sqList.baseAddress){
        delete sqList.baseAddress;
        printf("顺序表删除成功\n");
        return SUCCESS;
    }else{
        printf("顺序表删除失败\n");
        return FAIL;
    }
    
}
Status clearSqList(SqList &sqList){
    sqList.length=0;
    printf("顺序表清空成功\n");
    return SUCCESS;
}
int getLength(SqList sqList){
    return sqList.length;
}
int isEmpty(SqList sqList){
    if(sqList.length==0){
        printf("顺序表为空\n");
        return TRUE;
    }
    else{
        printf("顺序表不为空\n");
        return FALSE;
    }
}
Status getElem(SqList sqList,int index,ElemType &elem){ //获取元素
    if(index>=1&&index<=sqList.length){
        elem=(sqList.baseAddress)[index-1];
        return TRUE;
    }
    else return FALSE;
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
Status deleteElem(SqList &sqList,int index){//删除元素
    if(index>=1&&index<=sqList.length+1){
        int i;
        for(i=index;i<=sqList.length-1;i++){
            sqList.baseAddress[i-1]=sqList.baseAddress[i];
        }
        sqList.length--;
        printf("元素删除成功\n");
        return SUCCESS;
    }
    else{
        printf("元素删除失败\n");
        return FAIL;
    }
}
Status printSqList(SqList sqList){//输出线性表
    int i;
    for(i=1;i<=sqList.length;i++){
        ElemType column=sqList.baseAddress[i];
        printf("%s,%s\n",column.key,column.name);
    }
    printf("顺序表输出成功\n");
    return SUCCESS;
}


int sqSearch1(SqList sqList,KeyType key){//顺序查找
    int i;
       for(i=1;i<=sqList.length;i++){
           if(sqList.baseAddress[i].key==key)return i;
       }
       return 0;
}
int sqSearch2(SqList sqList,KeyType key){//顺序查找
    int i;
    for(i=sqList.length;i>=1;--i){
        if(sqList.baseAddress[i].key==key)return i;
    }
    return 0;
}
int sqSearch3(SqList sqList,KeyType key){//顺序查找
    int i;
    for(i=sqList.length;sqList.baseAddress[i].key!=key;--i)
        if(i<=0)break;
    if(i>0)return i;
    else return 0;
}
int sqSearch4(SqList sqList,KeyType key){//顺序查找
    int i;
    for(i=sqList.length;sqList.baseAddress[i].key!=key&&i>0;--i);
    if(i>0)return i;
    else return 0;
}
int sqSentinelSearch(SqList sqList,KeyType key){//顺序哨兵查找
    int i;
    sqList.baseAddress[0].key=key;
    for(i=sqList.length;sqList.baseAddress[i].key!=key;i--);
    return i;
}
int binarySearch(SqList sqList,KeyType key){//二分查找，也可叫折半查找；必须在有序表中才能使用；当前算法为升序有序表的折半查找
    int low,high,mid;
    low=1;
    high=sqList.length;//置区间初值
    while(low<=high){
        mid=(low+high)/2;
        if(sqList.baseAddress[mid].key==key){ //找到待查元素，返回mid值
            return mid;
        }else if(key<sqList.baseAddress[mid].key){//缩小查找区间
            high=mid-1;//继续在前半区间进行查找
        }else{
            low=mid+1;//继续在后半区间进行查找
        }
    }
    return 0;//顺序表中不存在待查元素，返回0
}
int recursiveBinarySearch(SqList sqList,KeyType key,int low,int high){
    if(high<low)return 0;
    int mid=(low+high)/2;
    if(sqList.baseAddress[mid].key==key)return mid;
    else if(key<sqList.baseAddress[mid].key){
        recursiveBinarySearch(sqList,key,low,mid-1);
    }else{
        recursiveBinarySearch(sqList,key,mid+1,high);
    }
    return 0;
}


