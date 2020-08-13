//
//  SqList.cpp
//  散列表的查找
//
//  Created by 熊智宏 on 2020/7/24.
//  Copyright © 2020 wisyoong. All rights reserved.
//

#include "SqList.hpp"
#include <string.h>
#include "LinkList.hpp"
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
int getMaxBit(SqList &sqList){
    int max=sqList.baseAddress[1].key;
    int maxBit=0;
    int i;
    for(i=2;i<=sqList.length;i++){
        if(sqList.baseAddress[i].key>max)max=sqList.baseAddress[i].key;
    }
    while(max!=0){
        max/=10;
        maxBit++;
    }
    return maxBit;
}
Status distribution(LinkList bucket[],SqList &sqList,int bit){ //分配
    int n=1;
    int i;
    for(i=1;i<bit;i++){ //根据当前遍历关键字的位数，生成对应的n,用于sqList.baseAddress[i].key/n%10;
        n=n*10;
    }
    for(i=0;i<10;i++){ //初始化桶
        initLinkList(bucket[i]);
    }
    for(i=1;i<=sqList.length;i++){
        int index=sqList.baseAddress[i].key/n%10; //求当前关键字的当前位数的数字是多少
        addNode(bucket[index], sqList.baseAddress[i]); //把数据元素放入对应的桶中
    }
    return SUCCESS;
}
Status collect(SqList &sqList,LinkList *bucket){ //收集
    int i;
    int j=0; //桶的下标
    Node *p=bucket[0]->next; //让p指向第一个桶的第一个数据元素
    for(i=1;i<=sqList.length;i++){ //把桶中的数据元素依次放回到顺序表
        while(p==NULL){ //如果当前桶已经遍历完成或没有数据元素，则让p指向下一个桶
            j++;
            p=bucket[j]->next;
        }
        sqList.baseAddress[i]=p->elem; //把桶中的元素放回到顺序表
        p=p->next; //p指向桶中的下一个数据元素
    }
    return SUCCESS;
}
Status radixSort(SqList &sqList){ //基数排序
    int maxBit=getMaxBit(sqList); //获取顺序表中关键字最大的位数是多少
    int bit; //当前的位数，用于遍历
    LinkList bucket[10]; //定义一个桶，因为关键字为10进制数，所以每位数最小数为0，最大数为9，所以定义长度为10的数组即可满足需求，即定义0～9共十个桶
    for(bit=1;bit<=maxBit;bit++){ //从个位开始遍历，1表示个位，2表示十位...遍历到最大位数为止
        distribution(bucket,sqList,bit); //根据个位数中的数字把数据元素放到相应的桶里
        collect(sqList, bucket); //把桶里数据元素取出依次放回顺序表里
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

