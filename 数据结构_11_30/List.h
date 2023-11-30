#ifndef __LIST_H__
#define __LIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//���� -> ƽ�������� (AVL���ͺ����)  ��ϣ��   B�� B+��ϵ��

//��ͷ˫��ѭ������ - ���ŵ�����ṹ ������λ�ò���ɾ�����ݶ���O(1)
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

