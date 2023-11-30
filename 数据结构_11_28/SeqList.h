#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//静态顺序表
//问题：给少了内存不够用，给多了浪费，没有动态灵活
#define MAX_SIZE   10
typedef int SQDataType;


typedef struct SeqList
{
	SQDataType a[MAX_SIZE];
	int size;
}SL;

//typedef struct SeqList SL;


//动态
typedef struct SeqList1
{
	SQDataType* arr;
	int size;  //有效数据的个数
	int capacity;  //容量
}SL2;


void SeqListInit(SL2* ps);
void SeqListPrint(SL2* ps);
void SeqListDestory(SL2* ps);
void SeqListPushBack(SL2* ps, SQDataType x);   //尾插
void SeqListPushFront(SL2* ps, SQDataType x);  //头插
void SeqListPopBack(SL2* ps); //尾删
void SeqListPopFront(SL2* ps);//头删

void SeqListInsert(SL2* ps, int pos, SQDataType x);
void SeqListErase(SL2* ps, int pos);


int SeqListFind(SL2* ps, SQDataType x);
void SeqListModify(SL2* ps, int pos, SQDataType x);


#endif /* __SEQLIST_H__ */

