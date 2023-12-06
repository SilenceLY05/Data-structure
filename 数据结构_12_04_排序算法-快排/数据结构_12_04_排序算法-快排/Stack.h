#ifndef __STACK_H__
#define __STACK_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Pos {
	int row;
	int col;
}PT;

typedef PT STDataType;

typedef struct Stack
{
	STDataType* _a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);

//栈顶插入删除数据
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);

STDataType StackTop(ST* ps);
int StackSize(ST* ps);

int StackEmpty(ST* ps);


#endif /* __STACK_H__ */

