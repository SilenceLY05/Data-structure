#ifndef __LIST_H__
#define __LIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int LTDataType;


typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;



LTNode* BuyListNode(LTDataType x);
LTNode* ListInit();
void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);

void ListDestory(LTNode* phead);
LTNode* ListFint(LTNode* pos, LTDataType x);
void ListInsert(LTNode* pos, LTDataType x);
void ListErase(LTNode* pos);
bool ListEmpty(LTNode* phead);
int ListSize(LTNode* phead);


#endif /* __SEQLIST_H__ */