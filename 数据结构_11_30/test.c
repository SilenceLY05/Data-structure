#include "List.h"

//单链表存在的缺陷：不能从后往前走  解决方案是双向链表

//实际中的链表结构非常多样，共8重
//1.单向、双向
//2.带头、不带头  带头节点不需要改变传过来的指针，也就意味着不需要传二级指针  带头即为带哨兵位的头结点，第一个节点不存储有效数据
//3.循环、非循环

//单项带头循环 单项带头不循环 单向不带头循环 单向不带头不循环 
//双项带头循环 双项带头不循环 双项不带头循环 双项不带头不循环 


void TestList1()
{
	ListNode* plist = ListNodeInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListPushFront(plist, 6);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListDestory(plist);
}

void TestList2()
{
	ListNode* plist = ListNodeInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	int num = ListSize(plist);
	printf("%d\n", num);
	ListNode* pos = ListFind(plist, 4);
	if (pos)
	{
		//查找附带着修改的作用
		pos->data = (pos->data) * 10;
		printf("找到了,并且节点的值*10\n");

	}
	else
	{
		printf("没有找到\n");
	}
	ListPrint(plist);

	ListInsert(pos, 300);
	ListPrint(plist);
	ListErase(pos);
	ListPrint(plist);
}


int main()
{
	TestList1();
	return 0;
}