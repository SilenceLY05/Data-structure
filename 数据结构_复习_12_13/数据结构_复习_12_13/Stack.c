#include "Stack.h"



void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType)*4);
	if (ps->a == NULL)
	{
		printf("malloc is fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}


void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}


void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a,sizeof(STDataType) * (ps->capacity)*2);
		if (tmp == NULL)
		{
			printf("realloc is fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}

	ps->a[ps->top] = x;
	ps->top++;
	
}


void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top);//栈空了直接报错终止

	ps->top--;
}


STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top);

	return ps->a[ps->top - 1];
}


int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}


bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}