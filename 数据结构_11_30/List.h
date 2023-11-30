#ifndef __LIST_H__
#define __LIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//查找 -> 平衡搜索树 (AVL树和红黑树)  哈希表   B树 B+树系列

//带头双向循环链表 - 最优的链表结构 在任意位置插入删除数据都是O(1)
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListNodeInit(void);
void ListPrint(ListNode* phead);
void ListDestory(ListNode* phead);


void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

bool ListEmpty(ListNode* phead);
int ListSize(ListNode* phead);

#endif /* __LIST_H__ */

