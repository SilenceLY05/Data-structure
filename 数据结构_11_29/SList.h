#ifndef __SLIST_H__
#define __SLIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


//一般使用plist/phead存储第一个节点的地址

typedef int SLTDataType;
struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;


//可能会改变链表的头指针，就传二级指针 不会改变的穿一级
void SListPrint(SLTNode* phead);
SLTNode* BuySListNode(SLTDataType x);

void SListPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SListPushFront(SLTNode** pphead, SLTDataType x);//头插
void SListPopBack(SLTNode** pphead);//尾删
void SListPopFront(SLTNode** pphead);//头删

SLTNode* SListFind(SLTNode* phead, SLTDataType x);//查找
//在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos,SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);


////有些地方这有这样的
////在pos前面插入x
//void SListInsert(SLTNode** pphead, int i, SLTDataType x);
////删除pos位置的值
//void SListErase(SLTNode** pphead, int i);


#endif /* __SLIST_H__ */

