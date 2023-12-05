#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void InsertSort(int* arr, int n)
{

}


//挖坑法
//一般选第一个或最后一个为Key，排完一趟后 左边比它小，右边比它大

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


//挖坑法快速排序
//单趟排序复杂度为O(N) 总共算法复杂度为O(NlogN)
//当数组为有序数组时，速度最慢 复杂度为O(N*N)
//三数取中解决
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


//挖坑法
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
		//右边找小
		while (end > begin && arr[end] >= key)
		{
			--end;
		}
		//小的放到左边的坑里，自己成为新的坑 位
		arr[pivot] = arr[end];
		pivot = end;

		//左边找大
		while (end > begin && arr[begin] <= key)
		{
			begin++;
		}
		//大的放到右边的坑里，自己成为新的坑位
		arr[pivot] = arr[begin];
		pivot = begin;

	}
	pivot = begin;
	arr[pivot] = key;

	return pivot;
}


//挖坑法变形 - 左右指针法
int PartSort2(int* arr, int left, int right)
{
	int begin = left;
	int end = right;
	int index = GetMidIndix(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = begin;
	while (end > begin)
	{
		//找小
		while (end > begin && arr[end] >= arr[key])
		{
			end--;
		}
		//找大
		while (end > begin && arr[begin] <= arr[key])
		{
			begin++;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[key], &arr[begin]);
	return begin;
}



//挖坑法变形 - 前后指针法
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
	//	//右边找小
	//	while (end > begin && arr[end] >= key)
	//	{
	//		--end;
	//	}
	//	//小的放到左边的坑里，自己成为新的坑 位
	//	arr[pivot] = arr[end];
	//	pivot = end;

	//	//左边找大
	//	while (end > begin && arr[begin] <= key)
	//	{
	//		begin++;
	//	}
	//	//大的放到右边的坑里，自己成为新的坑位
	//	arr[pivot] = arr[begin];
	//	pivot = begin;

	//}
	//pivot = begin;
	//arr[pivot] = key;
	//左子区间和右子区间有序，我们就有序了，如果让他们有序呢？分治递归
	//小区间优化
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



//归并排序
//假设左半区间有序 右半区间有序 归并，依次对比取小的放到新的临时数组
//归并之前左右子区间没有序

void _MergeSort(int* arr, int left, int right,int* arr2)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	//假设[left,mid] [mid+1,right] 有序，那么我们就可以归并了
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

	//将数据拷贝回去
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