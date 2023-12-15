#ifndef __SLIST_H__
#define __SLIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLTDataType;


struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;

void SListInit();
void SListPrint(SLTNode* phead);
SLTNode* BuySListNode(SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFint(SLTNode* phead, SLTDataType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);


#endif /* __SLIST_H__ */
