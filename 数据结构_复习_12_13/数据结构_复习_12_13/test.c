
#include "List.h"

//void Test()
//{
//	SL s1;
//	SeqListInit(&s1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushFront(&s1, 2);
//
//	SeqListPrint(&s1);
//	SeqListPopBack(&s1);
//	SeqListPrint(&s1);
//	SeqListPopFront(&s1);
//	SeqListPrint(&s1);
//	SeqListInsert(&s1, 2, 3);
//	SeqListPrint(&s1);
//	SeqListErase(&s1, 2);
//	SeqListPrint(&s1);
//}




//void TestSLTNode(void)
//{
//	SLTNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//	SListPushBack(&plist, 4);
//	SListPushFront(&plist, 5);
//	SListPrint(plist);
//	SLTNode* pos = SListFint(plist, 3);
//	if (pos)
//	{
//		SListInsert(&plist, pos, 30);
//	}
//	SListPrint(plist);
//}


void TestList()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);
	ListPushFront(plist, 7);
	ListPushFront(plist, 8);
	ListPushFront(plist, 9);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopFront(plist);
	ListPrint(plist);

	LTNode* pos = ListFint(plist, 3);
	if (pos == NULL)
	{
		return;
	}
	else
	{
		ListInsert(pos, 30);
	}
	ListDestory(plist);
}

int main()
{
	TestList();

	return 0;
}





