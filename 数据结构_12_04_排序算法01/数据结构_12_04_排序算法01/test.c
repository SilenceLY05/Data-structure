#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



//��������   ʱ�临�Ӷ���N^2
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


//ֱ�Ӳ�������Ļ������Ż�
//�Ƚ���Ԥ����������ӽ�����
//ϣ������(��С��������)����ѡ��һ���������Ѵ������ļ������м�¼�ֳɸ��飬���о���Ϊgap�ļ�¼��ͬһ�飬
//����ÿһ���ڵļ�¼��������Ȼ��ȡ
void ShellSort(int* arr, int n)
{
	int gap = n ;
	while (gap > 1)
	{
		gap /= 2;   //log2 N
		//gap = gap/3+1;    //log3 N
		for (int i = 0; i < n - gap; i++)
		{

			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
			
		}
		
	}
}

void TestShellSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	PrintArray(arr, size);
}


//������(Heapsort)��ָ���öѻ������ѣ��������ݽṹ����Ƶ�һ�������㷨������ѡ�������һ�֡�����
//ͨ����������ѡ�����ݡ���Ҫע�����������Ҫ����ѣ��Ž���С�ѡ�
//��ѣ�ÿһ������������˫�״����������� С�ѣ�ÿ������������˫��С�ں���
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ����㷨
//ǰ�᣺������������С��   
//�Ӹ��ڵ㿪ʼ ѡ�����Һ�����С����һ���������ױȽϣ�����ȸ���С�ͽ�����Ȼ���ټ������µ�������Ҷ�ӽ�����ֹ
void AdjustDown(int* arr, int n,int root)
{
	/*int tmp = 0;
	while(root < n)
	{
		if (arr[root] > arr[root * 2 + 1] && arr[root] < arr[root * 2 + 2])
		{
			tmp = arr[root];
			arr[root] = arr[root * 2 + 1];
			arr[root * 2 + 1] = tmp;
			AdjustDown(arr, n, root * 2 + 1);
		}
		else if (arr[root] < arr[root * 2 + 1] && arr[root] > arr[root * 2 + 2])
		{
			tmp = arr[root];
			arr[root] = arr[root * 2 + 2];
			arr[root * 2 + 2] = tmp;
			AdjustDown(arr, n, root * 2 + 2);
		}
		else
		{
			return;
		}
		
	}*/
	//int child;
	//int tmp = arr[root];

	//for (; root * 2 + 1 < n; root == child)
	//{
	//	child = root * 2 + 1;
	//	if (child != n - 1 && arr[child + 1] < arr[child])
	//	{
	//		child++;
	//	}

	//	if (arr[child] < tmp)
	//	{
	//		arr[root] = arr[child];
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//arr[root] = tmp;
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//1.ѡ�����Һ�����С����һ��
		if (child<n - 1 && arr[child]>arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}

//���ϵ����㷨 �������� �������С
void AdjustUp(int* arr, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//1.ѡ�����Һ����д����һ��
		if (child<n - 1 && arr[child]<arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

//������������С�ѣ����Ŵ����һ��������ʼ��,Ҷ�������õ��������һ����Ҷ�ӿ�ʼ��
//void HeapSort(int* arr, int n)
//{
//	//�����齨�ɶ� - ����
//	int i = 0;
//	for (i = n/2 - 1; i >= 0; i--)
//	{
//		AdjustDown(arr, n, i);
//	}
//	//for (i = n / 2 - 1; i >= 0; i--)
//	//{
//	//	AdjustUp(arr, n, i);
//	//}
//
//	
//}

//�����򣬽����   �Ž���,��С��
//ѡ������ͨ������ѡ��
//����ǽ�С�ѣ���С���ڶѶ����Ѿ���ѡ�����ˣ���ô��ʣ�µ�����ȥѡ��������ʣ�����ṹ�����ˣ���Ҫ���½��Ѳ���ѡ��һ����
//���ѵ�ʱ�临�Ӷ���O(N)����ô�������ǲ����ԣ����Ƕ������û��Ч������
//�����Ļ�����󣬲������Ƕ�����ģ�ǰn-1�������µ�����ѡ���δ�������ٸ������ڶ���λ�ý���
//���ѵ�ʱ�临�Ӷ�ΪO(N)
//����ʱ�临�Ӷ�O(N*logN)
void HeapSort(int* arr, int n)
{
	while (n > 0)
	{
		//�����齨�ɶ� - ����
		int i = 0;
		for (i = n / 2 - 1; i >= 0; i--)
		{
			//AdjustUp(arr, n, i);
			AdjustDown(arr, n, i);
		}
		Swap(&arr[0], &arr[n - 1]);
		n--;
	}
	


}


void TestHeapSort()
{
	int arr[] = { 3,5,2,7,8,6,1,9,4,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	PrintArray(arr, size);
}


//void TestHeapSort()
//{
//	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, size);
//	PrintArray(arr, size);
//}


//ֱ��ѡ������  ʱ�临�Ӷ�O(N*N)
//�ܲ��Ϊ������Ҳ��O(N*N)
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int i = 0;
		int min = begin;
		int max = begin;
		for (i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[min], &arr[begin]);
		//���begin��max�ص�����Ҫ������max��λ��
		if (begin == max)
		{
			max = min;
		}
		Swap(&arr[max], &arr[end]);
		begin++;
		end--;
	}
}

void TestHSelectSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	PrintArray(arr, size);
}


//ð������ ʱ�临�Ӷ�O(N*N)  ��������O(N)
//��ֱ�Ӳ���������� ֱ�Ӳ������
void BubbleSort(int* arr, int n)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
			if (flag == 0)
			{
				break;
			}
		}
	}
}


void TestBubbleSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	PrintArray(arr, size);
}


void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	HeapSort(a3, N);
	int end3 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("HeapSort:%d\n", end3 - begin3);

	free(a1);
	free(a2);
	free(a3);
}

int main()
{
	//TestShellSort();
	//TestOP();
	//TestHeapSort();
	//TestHSelectSort();
	TestBubbleSort();
	return 0;
}
 

