#include "Stack.h"
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
	QuickSort(arr, 0, size - 1);
	PrintArray(arr, size);
}


//�ݹ��ȱ�ݣ��ڼ�������»����ջ������  �ݹ����̫�������û��ģ�����ջ�Ŀռ䲻����
//�ݹ�ķǵݹ飺1��ֱ�Ӹ�ѭ��(��) 2���������ݽṹ��ջģ��ݹ����(����һ���)
//�������ý���ջ֡��ջ֡�д洢�ֲ�����������
void QuickSortNonR(int* arr, int n)
{
	ST st;
	StackInit(&st);

	//ջ��������������Ҫ�����˷ָ������
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		 int keyIndex = PartSort1(arr, left, right);


		//[left keyIndex -1] keyIndex [keyIndex+1 right]
		if (keyIndex+1 < right)
		{
			StackPush(&st,right);
			StackPush(&st, keyIndex + 1);
		}
		if (left < keyIndex - 1)
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}

	StackDestory(&st);
	
}

void TestQuickSortNonR()
{
	int arr[] = { 3,5,4,3,2,6,7,1,9,8,20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, size);
	PrintArray(arr, size);
}



//ʱ�临�Ӷȶ���O(N*logN)
void MergeSortNonR(int* arr, int n)
{
	if (arr == NULL || n <= 0)
		return;
	int* arr2 = (int*)malloc(sizeof(int) * n);
	if (arr2 == NULL)
		return;

	int gap = 1; //ÿ�����ݵĸ���
	while (gap <= n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// �鲢�������Ұ�������ܾͲ�����
			if (end1 >= n)
				end1 = n - 1;

			// �鲢�������Ұ����������, ����һ��
			if (end2 >= n)
				end2 = n - 1;

			int index = i;
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
			while (begin1 <= end1)
			{
				arr2[index++] = arr[begin1++];
			}
			while (begin2 <= end2)
			{
				arr2[index++] = arr[begin2++];
			}

			
		}
		//�����ݿ�����ȥ
		for (int i = 0; i <n; i++)
		{
			arr[i] = arr2[i];
		}
		gap *= 2;
	}
	free(arr2);
}



//�鲢���� - �ݹ�  
//��������������� �Ұ��������� �鲢�����ζԱ�ȡС�ķŵ��µ���ʱ����
//�鲢֮ǰ����������û����
//�ݹ����˼�������ƶ������еĺ�������
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
	while (begin1 <= end1)
	{
		arr2[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
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
	MergeSortNonR(arr, size);
	PrintArray(arr, size);
}

//�鲢����Ҳ��������, �����Զ��ļ��е����ݽ�����
//����10G�����ݷŵ�Ӳ�̵��ļ��У�Ҫ��������ţ������ڴ治����������1G�ڴ������
//10G���ļ����зֳ�10��1G���ļ���������10��1G���ļ��������ζ��ļ���ÿ�ζ�1G���ڴ��зŵ�һ�����飬�ÿ��Ŷ�������
//��д��һ���ļ����ټ�������һ��1G������




//�������� Ͱ����
//˼�룺���ηֱ�ȡ���ǵĸ�λ��ʮλ����λ...����   ʵ����ûʲô�� ���岻��


//��������  ˼����ɣ����÷�Χ���о�����
//ͳ��ÿ�������ֵĴ����� ʹ�ô����Ϳ��Կ�ʼ������
//�ǱȽ����� ʱ�临�Ӷ�O(N+range)��˵���������ڷ�Χ����һ��������������  �ռ临�Ӷ�O(range)
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
		return;
	memset(count, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}


	free(count);
	count = NULL;
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
	//TestQuickSortNonR();
	return 0;
}



