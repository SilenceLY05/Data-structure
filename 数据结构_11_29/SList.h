#ifndef __SLIST_H__
#define __SLIST_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


//һ��ʹ��plist/phead�洢��һ���ڵ�ĵ�ַ

typedef int SLTDataType;
struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;


//���ܻ�ı������ͷָ�룬�ʹ�����ָ�� ����ı�Ĵ�һ��
void SListPrint(SLTNode* phead);
SLTNode* BuySListNode(SLTDataType x);

void SListPushBack(SLTNode** pphead, SLTDataType x);//β��
void SListPushFront(SLTNode** pphead, SLTDataType x);//ͷ��
void SListPopBack(SLTNode** pphead);//βɾ
void SListPopFront(SLTNode** pphead);//ͷɾ

SLTNode* SListFind(SLTNode* phead, SLTDataType x);//����
//��pos��ǰ�����x
void SListInsert(SLTNode** pphead, SLTNode* pos,SLTDataType x);
//ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos);


////��Щ�ط�����������
////��posǰ�����x
//void SListInsert(SLTNode** pphead, int i, SLTDataType x);
////ɾ��posλ�õ�ֵ
//void SListErase(SLTNode** pphead, int i);


#endif /* __SLIST_H__ */

