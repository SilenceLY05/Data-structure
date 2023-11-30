#include "List.h"

//��������ڵ�ȱ�ݣ����ܴӺ���ǰ��  ���������˫������

//ʵ���е�����ṹ�ǳ���������8��
//1.����˫��
//2.��ͷ������ͷ  ��ͷ�ڵ㲻��Ҫ�ı䴫������ָ�룬Ҳ����ζ�Ų���Ҫ������ָ��  ��ͷ��Ϊ���ڱ�λ��ͷ��㣬��һ���ڵ㲻�洢��Ч����
//3.ѭ������ѭ��

//�����ͷѭ�� �����ͷ��ѭ�� ���򲻴�ͷѭ�� ���򲻴�ͷ��ѭ�� 
//˫���ͷѭ�� ˫���ͷ��ѭ�� ˫���ͷѭ�� ˫���ͷ��ѭ�� 


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
		//���Ҹ������޸ĵ�����
		pos->data = (pos->data) * 10;
		printf("�ҵ���,���ҽڵ��ֵ*10\n");

	}
	else
	{
		printf("û���ҵ�\n");
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