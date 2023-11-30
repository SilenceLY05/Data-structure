#include "SList.h"

//打印链表 边遍历 边打印
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
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}



//尾插
//也可以使用C++语法中的引用& 这时传过来的不是形参 而是plist的别名。可以对plist产生影响
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾结点的指针
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//尾结点链接新节点
		tail->next = newnode;
	}

} 

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	//SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//SLTDataType tmp = 0;
	//tmp = (*pphead)->data;
	//(*pphead)->data = x;
	//newnode->data = tmp;
	//newnode->next = (*pphead)->next;
	//(*pphead)->next = newnode;
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	//链表为空
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)  //只有一个节点
	{
		free(*pphead);
		*pphead = NULL;
	}
	else // 一个以上的节点
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

//头删
void SListPopFront(SLTNode** pphead)
{
	if (*pphead != NULL)
	{
		SLTNode* nextnode = (*pphead)->next;

		free(*pphead);
		*pphead = nextnode;
	}
}



SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;

	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


//在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	//SLTNode* newnode = BuySListNode(x);
	//SLTNode* cur = *pphead;
	//SLTNode* prev = NULL;
	//while (cur != pos)
	//{
	//	prev = cur;
	//	cur = cur->next;
	//}

	//prev->next = newnode;
	//newnode->data = x;
	//newnode->next = pos;

	SLTNode* newnode = BuySListNode(x);
	//如果pos为第一个
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


//删除pos位置的值
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