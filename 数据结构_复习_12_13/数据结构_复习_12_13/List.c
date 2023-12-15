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


struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* pos = head;
	struct ListNode* cur = head;
	while (cur != NULL && cur->next != NULL)
	{
		pos = pos->next;
		cur = cur->next->next;
	}

	return pos;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	struct ListNode dummy;
	struct ListNode* tail = &dummy;
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	tail->next = list1 ? list1 : list2;
	return dummy.next;
}


bool hasCycle(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}


struct ListNode* detectCycle(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	int Cycle = 0;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			Cycle = 1;
			break;
		}

	}
	if (Cycle)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
	return NULL;
}