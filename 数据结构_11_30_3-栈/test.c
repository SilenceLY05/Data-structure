#include "Stack.h"


//栈：一种特殊的线性表，其只允许在固定的一段进行插入和删除元素操作，进行数据插入和删除操作的一端称为栈顶，
//另一端称为栈底。栈中的数据元素遵守后进先出LIFO(last in first out)的原则 
//压栈：栈的插入操作叫做进栈、压栈、入栈，入数据在栈顶
//出栈：栈的删除操作叫做出栈，出数据也在栈顶



//用数组做栈：相当于之前顺序表的尾插尾删，用尾去做了栈顶，非常合适，唯一缺陷就是空间不都需要增容
//用链表实现栈：1、如果用尾插做栈顶那么要用双向链表更好 2、如果用单链表实现，那么就用头去做栈顶更好，这样入栈出栈效率都是O(1)


int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPush(&st, 7);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);

	return 0;
}