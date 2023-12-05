#include "Queue.h"

//���У�ֻ������һ�ν��в������ݲ���������һ�˽���ɾ�����ݲ������������Ա����������Ƚ��ȳ�
//����У����в��������һ�˳�Ϊ��β
//�����У�����ɾ��������һ�˳�Ϊ��ͷ


void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	

	QueueDestory(&q);
}


//int main()
//{
//	TestQueue();
//
//	return 0;
//}

//��������
void InsertSort(int* a, int n)
{
	//[0,end]����end+1λ�õ�ֵ�����ȥ����[0,end+1]Ҳ����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}

}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void TestInsertSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	PrintArray(arr, size);
}



int main()
{

	TestInsertSort();
	return 0;
}
