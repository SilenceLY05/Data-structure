#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//��̬˳���
//���⣺�������ڴ治���ã��������˷ѣ�û�ж�̬���
#define MAX_SIZE   10
typedef int SQDataType;


typedef struct SeqList
{
	SQDataType a[MAX_SIZE];
	int size;
}SL;

//typedef struct SeqList SL;


//��̬
typedef struct SeqList1
{
	SQDataType* arr;
	int size;  //��Ч���ݵĸ���
	int capacity;  //����
}SL2;


void SeqListInit(SL2* ps);
void SeqListPrint(SL2* ps);
void SeqListDestory(SL2* ps);
void SeqListPushBack(SL2* ps, SQDataType x);   //β��
void SeqListPushFront(SL2* ps, SQDataType x);  //ͷ��
void SeqListPopBack(SL2* ps); //βɾ
void SeqListPopFront(SL2* ps);//ͷɾ

void SeqListInsert(SL2* ps, int pos, SQDataType x);
void SeqListErase(SL2* ps, int pos);


int SeqListFind(SL2* ps, SQDataType x);
void SeqListModify(SL2* ps, int pos, SQDataType x);


#endif /* __SEQLIST_H__ */

