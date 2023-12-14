#include "SeqList.h"


void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->_a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc if fail\n");
			exit(-1);
		}
		else
		{
			ps->_a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

void SeqListInit(SL* ps)
{
	if (ps == NULL)
		return;
	ps->_a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPushBack(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);
	ps->_a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->_a[i] = ps->_a[i - 1];
	}
	ps->_a[0] = x;
	ps->size++;
}


void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}


void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	for (int i = 0; i <ps->size-1; i++)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->size--;
}



void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	SeqListCheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->_a[i] = ps->_a[i - 1];
	}
	ps->_a[pos] = x;
	ps->size++;
}


void SeqListErase(SL* ps, int pos)
{
	assert(ps->size > 0);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->size--;

}


void SeqListDestory(SL* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


int SeqListFind(SL* ps, SQDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->_a[i] == x)
			return i;
	}

	return -1;
}


void SeqListModify(SL* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	ps->_a[pos] = x;
}
