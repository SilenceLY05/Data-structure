#include "Queue.h"

//队列：只允许在一段进行插入数据操作，在另一端进行删除数据操作的特殊线性表，对流具有先进先出
//入队列：进行插入操作的一端称为队尾
//出队列：进行删除操作的一端称为队头


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

//插入排序
void InsertSort(int* a, int n)
{
	//[0,end]有序，end+1位置的值插入进去，让[0,end+1]也有序
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
