#include "SList.h"

//��ӡ���� �߱��� �ߴ�ӡ
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



//β��
//Ҳ����ʹ��C++�﷨�е�����& ��ʱ�������Ĳ����β� ����plist�ı��������Զ�plist����Ӱ��
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//�ҵ�β����ָ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//β��������½ڵ�
		tail->next = newnode;
	}

} 

//ͷ��
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

//βɾ
void SListPopBack(SLTNode** pphead)
{
	//����Ϊ��
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)  //ֻ��һ���ڵ�
	{
		free(*pphead);
		*pphead = NULL;
	}
	else // һ�����ϵĽڵ�
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

//ͷɾ
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


//��pos��ǰ�����x
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
	//���posΪ��һ��
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


//ɾ��posλ�õ�ֵ
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