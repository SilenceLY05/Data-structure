#include "List.h"

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
		exit(-1);
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* ListInit(void)
{
	LTNode*  phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}



void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}




void ListPushFront(LTNode* phead, LTDataType x)
{
	//assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* first = phead->next;

	//newnode->next = first;
	//newnode->prev = phead;
	//phead->next = newnode;
	//first->prev = newnode;
	ListInsert(phead->next, x);
}

void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}


void ListPopBack(LTNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//LTNode* tail = phead->prev;
	//LTNode* prev = tail->prev;
	//phead->prev = prev;
	//prev->next = phead;
	//free(tail);
	//tail = NULL;
	ListErase(phead->prev);
}


void ListPopFront(LTNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//LTNode* first = phead->next;
	//LTNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);
}


LTNode* ListFint(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}


void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}


bool ListEmpty(LTNode* phead)
{
	if (phead->next != phead)
		return 0;
	else
		return 1;
}


int ListSize(LTNode* phead)
{
	LTNode* cur = phead->next;
	int i = 0;

	while (cur != phead)
	{
		cur = cur->next;
		i++;
	}
	return i;
}


