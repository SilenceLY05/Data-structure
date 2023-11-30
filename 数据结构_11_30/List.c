#include "List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


ListNode* ListNodeInit(void)
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}


void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}


void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	//
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode; 
	ListInsert(phead, x);
}


void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);

	//first->prev = newnode;
	//newnode->prev = phead;
	//newnode->next = first;
	//phead->next = newnode;

	////如果不另外设置一个变量first更改链接时需要注意顺序 顺序不能换
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	ListInsert(phead->next, x);
}


void ListPopBack(ListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//ListNode* tail = phead->prev;
	//ListNode* penul = tail->prev;

	//penul->next = phead;
	//phead->prev = penul;
	//free(tail);
	//tail = NULL;
	ListErase(phead->prev);
}


void ListPopFront(ListNode* phead)
{
	assert(phead);
	//assert(phead->next != phead);

	//ListNode* first = phead->next;
	//ListNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;
	ListErase(phead->next);

}


ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	
	next->prev = prev;
	prev->next = next;
	free(pos);
	pos = NULL;
	
}


bool ListEmpty(ListNode* phead)
{
	if (phead->next != phead)
		return 0;
	else
		return 1;
}
int ListSize(ListNode* phead)
{
	ListNode* cur = phead->next;
	int i = 0;

	while (cur != phead)
	{
		cur = cur->next;
		i++;
	}
	return i;
}