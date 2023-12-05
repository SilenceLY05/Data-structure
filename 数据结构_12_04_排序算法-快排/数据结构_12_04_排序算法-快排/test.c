#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void InsertSort(int* arr, int n)
{

}


//�ڿӷ�
//һ��ѡ��һ�������һ��ΪKey������һ�˺� ��߱���С���ұ߱�����

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


//�ڿӷ���������
//���������Ӷ�ΪO(N) �ܹ��㷨���Ӷ�ΪO(NlogN)
//������Ϊ��������ʱ���ٶ����� ���Ӷ�ΪO(N*N)
//����ȡ�н��
int GetMidIndix(int* a, int left,int right)
{
	int mid = (right + left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}

}


//�ڿӷ�
int PartSort1(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int index = GetMidIndix(arr, left, right);
	Swap(&arr[left], &arr[index]);

	int pivot = begin;
	int key = arr[begin];
	while (end > begin)
	{
		//�ұ���С
		while (end > begin && arr[end] >= key)
		{
			--end;
		}
		//С�ķŵ���ߵĿ���Լ���Ϊ�µĿ� λ
		arr[pivot] = arr[end];
		pivot = end;

		//����Ҵ�
		while (end > begin && arr[begin] <= key)
		{
			begin++;
		}
		//��ķŵ��ұߵĿ���Լ���Ϊ�µĿ�λ
		arr[pivot] = arr[begin];
		pivot = begin;

	}
	pivot = begin;
	arr[pivot] = key;

	return pivot;
}


//�ڿӷ����� - ����ָ�뷨
int PartSort2(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int index = GetMidIndix(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = begin;
	while (end > begin)
	{
		//��С
		while (end > begin && arr[end] >= arr[key])
		{
			end--;
		}
		//�Ҵ�
		while (end > begin && arr[begin] <= arr[key])
		{
			begin++;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[key], &arr[begin]);
	return begin;
}



//�ڿӷ����� - ǰ��ָ�뷨
int PartSort3(int* arr, int left, int right)
{
	int prev = left;
	int cur = left +1;
	int index = GetMidIndix(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = left;
	while (right >= cur)
	{
		if (arr[cur] < arr[key] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[key], &arr[prev]);
	return prev;
}


void QuickSort(int* arr, int left,int right)
{
	if (left >= right)
	{
		return;
	}

	int keyIndex = PartSort1(arr, left, right);

	//int begin = left;
	//int end = right;
	//int index = GetMidIndix(arr, left, right);
	//Swap(&arr[left], &arr[index]);
	//
	//int pivot = begin;
	//int key = arr[begin];
	//while (end > begin)
	//{
	//	//�ұ���С
	//	while (end > begin && arr[end] >= key)
	//	{
	//		--end;
	//	}
	//	//С�ķŵ���ߵĿ���Լ���Ϊ�µĿ� λ
	//	arr[pivot] = arr[end];
	//	pivot = end;

	//	//����Ҵ�
	//	while (end > begin && arr[begin] <= key)
	//	{
	//		begin++;
	//	}
	//	//��ķŵ��ұߵĿ���Լ���Ϊ�µĿ�λ
	//	arr[pivot] = arr[begin];
	//	pivot = begin;

	//}
	//pivot = begin;
	//arr[pivot] = key;
	//������������������������Ǿ������ˣ���������������أ����εݹ�
	//С�����Ż�
	if ((keyIndex - 1 - left) > 10)
	{
		QuickSort(arr, left, keyIndex - 1);
	}
	else
	{
		InsertSort(arr + left, keyIndex -1 - left+1);
	}
	if ((right - keyIndex - 1) > 10)
	{
		QuickSort(arr, keyIndex + 1, right);
	}
	else
	{
		InsertSort(arr + keyIndex +1, right - (keyIndex +1)+1);
	}
	
	
}



void TestQuickSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0,size-1);
	PrintArray(arr, size);
}



//�鲢����
//��������������� �Ұ��������� �鲢�����ζԱ�ȡС�ķŵ��µ���ʱ����
//�鲢֮ǰ����������û����

void _MergeSort(int* arr, int left, int right,int* arr2)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	//����[left,mid] [mid+1,right] ������ô���ǾͿ��Թ鲢��
	_MergeSort(arr, left, mid, arr2);
	_MergeSort(arr, mid+1, right, arr2);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			arr2[index++] = arr[begin1++];
		}
		else
		{
			arr2[index++] = arr[begin2++];
		}
	}
	while (begin1 <end1)
	{
		arr2[index++] = arr[begin1++];
	}
	while (begin2 < end2)
	{
		arr2[index++] = arr[begin2++];
	}

	//�����ݿ�����ȥ
	for(int i = left;i<=right;i++)
	{
		arr[i] = arr2[i];
	}
}
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1,tmp);


	free(tmp);
}


void TestMergeSort()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, size - 1);
	PrintArray(arr, size);
}

void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
	}

	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();

	//int begin2 = clock();
	//ShellSort(a2, N);
	//int end2 = clock();

	//int begin3 = clock();
	//HeapSort(a3, N);
	//int end3 = clock();

	int begin4 = clock();
	QuickSort(a4, 0,N);
	int end4 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);
	//printf("ShellSort:%d\n", end2 - begin2);
	//printf("HeapSort:%d\n", end3 - begin3);
	printf("QuickSort:%d\n", end4 - begin4);

	//free(a1);
	//free(a2);
	//free(a3);
}

int main()
{

	//TestOP();
	//TestQuickSort();
	TestMergeSort();
	return 0;
}