#include "SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}



void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}


void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((* pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
	
}


void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* next = (*pphead)->next;
		free(pphead);
		*pphead = next;
	}
}

SLTNode* SListFint(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	SLTNode* prev = *pphead;
	
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	
	prev->next = newnode;
	newnode->next = pos;
}


void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;

		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}	
}