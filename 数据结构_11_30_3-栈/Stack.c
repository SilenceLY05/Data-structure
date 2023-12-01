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
	//��ʼtop��0��ζ��topָ�����ջ��Ԫ�ص���һ������ʼ��topΪ-1��ζ��topָ�����ջ��Ԫ��
	ps->top = 0;
}


void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->top = ps->capacity = 0;
}

//ջ������ɾ������
//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//���˾�����
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
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	//���ջ���ˣ�����Pop,ֱ����ֹ���򱨴�
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