#include "SeqList.h"

//void SeqListInit(SL* ps)
//{
//	memset(ps->a, 0, sizeof(SQDataType)* MAX_SIZE);
//	ps->size = 0;
//}
//
//void SeqListPushBack(SL* ps, SQDataType x)
//{
//	if (ps->size < MAX_SIZE)
//	{
//		ps->a[ps->size] = x;
//		ps->size++;
//	}
//	else
//	{
//		printf("SeqList is Full\n");
//		return;
//	}
//}
//
//void SeqListPushFront(SL* ps, SQDataType x)
//{
//	if (ps->size < MAX_SIZE)
//	{
//		int i = 0;
//		for (i = ps->size; i > 0; i--)
//		{
//			ps->a[i] = ps->a[i - 1];
//		}
//		ps->a[0] = x;
//		ps->size++;
//	}
//	else
//	{
//		printf("SeqList is Full\n");
//		return;
//	}
//}
//
//
//void SeqListPopBack(SL* ps)
//{
//	if (ps->size > 0)
//	{
//		ps->a[ps->size - 1] = 0;
//		ps->size--;
//	}
//	else
//	{
//		printf("SeqList is Empty\n");
//		return;
//	}
//
//}
//
//
//void SeqListPopFront(SL* ps)
//{
//	if (ps->size > 0)
//	{
//		int i = 0;
//		for (i = 0; i < ps->size - 1; i++)
//		{
//			ps->a[i] = ps->a[i + 1];
//			ps->size--;
//		}
//	}
//	else
//	{
//		printf("SeqList is Empty\n");
//		return;
//	}
//
//}


//void SeqListInit(SL2* ps)
//{
//	ps->arr = NULL;
//	ps->size = 0;
//	ps->capacity = 0;
//}
//
//
//void SeqListPushBack(SL2* ps, SQDataType x)
//{
//	if (ps->size == ps->capacity)
//	{
//		SQDataType* tmp = (SQDataType*)realloc(ps->arr, ps->size * sizeof(SQDataType));
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		else
//		{
//			ps->arr = tmp;
//			ps->capacity *= 2;
//		}
//		
//	}
//	ps->arr[ps->size] = x;
//	ps->size++;
//}

////�����ʼ��ʱps->capacityΪ��0ֵ
//void SeqListInit(SL2* ps,int initialCapacity)
//{
//	ps->arr = (SQDataType*)malloc(initialCapacity*sizeof(SQDataType)); // �����ʼ����Ϊ1���ڴ�
//	if (ps->arr == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	ps->size = 0;
//	ps->capacity = initialCapacity;//��ps->capacity ��ʼ��Ϊ 1����û��Ϊ ps->arr �����κ��ڴ棬��ô�ڳ�������κ�Ԫ��֮ǰ��
//	//ps->arr ��ָ��һ���գ�NULL��ָ�롣������ǵ�������ʱ�����ԭ��
//}

void SeqListCheckCapacity(SL2* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->arr, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity = newcapacity;
		}

	}
}



//�޸ķ���
void SeqListInit(SL2* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListCheckCapacity(SL2* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->arr, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity = newcapacity;
		}

	}
}


void SeqListPushBack(SL2* ps, SQDataType x)
{
	/*SeqListCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}


void SeqListPrint(SL2* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


void SeqListPushFront(SL2* ps, SQDataType x)
{
	//SeqListCheckCapacity(ps);

	///*int i = 0;
	//for (i = ps->size; i > 0; i--)
	//{
	//	ps->arr[i] = ps->arr[i - 1];
	//}
	//ps->arr[0] = x;
	//ps->size++;*/
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->arr[end + 1] = ps->arr[end];
	//	--end;
	//}
	//ps->arr[0] = x;
	//ps->size++;
	SeqListInsert(ps, 0, x);
}

void SeqListPopBack(SL2* ps)
{
	//assert(ps->size > 0);
	////ps->arr[ps->size - 1] = 0;���Ӱ�첻�� ������Ч������size����
	//ps->size--;
	SeqListErase(ps, ps->size - 1);

}



void SeqListPopFront(SL2* ps)
{
	/*assert(ps->size > 0);
	int start = 1;
	while (start < ps->size)
	{
		ps->arr[start - 1] = ps->arr[start];
		start++;
	}
	ps->size--;*/
	SeqListErase(ps, 0);
}


void SeqListInsert(SL2* ps, int pos, SQDataType x)
{
	//pos���ܴ���size ���ݴ洢Ҫ����
	assert(pos <= ps->size);

	SeqListCheckCapacity(ps);

	/*int i = 0;
	for (i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;*/
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->arr[end + 1] = ps->arr[end];
		--end;
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SeqListErase(SL2* ps, int pos)
{
	assert(ps->size > pos);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->arr[start - 1] = ps->arr[start];
		start++;
	}
	ps->size--;

}

void SeqListDestory(SL2* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

int SeqListFind(SL2* ps, SQDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListModify(SL2* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);

	int i = 0;
	ps->arr[pos] = x;
}