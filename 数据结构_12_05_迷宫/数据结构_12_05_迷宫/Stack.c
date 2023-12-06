#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->_a == NULL)
	{
		printf("realloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	//初始top给0意味着top指向的是栈顶元素的下一个，初始化top为-1意味着top指向的是栈顶元素
	ps->top = 0;
}


void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->top = ps->capacity = 0;
}

//栈顶插入删除数据
//入栈
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//满了就增容
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->_a, ps->capacity * 2 * sizeof(STDataType));
		if(tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->_a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->_a[ps->top] = x;
	ps->top++;
	

}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	//如果栈空了，调用Pop,直接终止程序报错
	assert(ps->top > 0);

	ps->top--;

}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->_a[ps->top - 1];
}


int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;

}


int StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;

}