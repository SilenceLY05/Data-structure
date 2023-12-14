#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int SQDataType;


typedef struct SeqList	
{
	SQDataType* _a;
	int size;
	int capacity;
}SL;


void SeqListInit(SL* ps);

//ÔöÉ¾²é¸Ä
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
void SeqListInsert(SL* ps, int pos, SQDataType x);
void SeqListErase(SL* ps, int pos);

void SeqListDestory(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);

int SeqListFind(SL* ps, SQDataType x);
void SeqListModify(SL* ps, int pos, SQDataType x);

#endif /* __SEQLIST_H__ */