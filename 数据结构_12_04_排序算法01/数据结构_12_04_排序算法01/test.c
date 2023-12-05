#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



//插入排序   时间复杂度是N^2
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


//直接插入排序的基础上优化
//先进性预排序，让数组接近有序
//希尔排序(缩小增量排序)：先选定一个整数，把待排序文件中所有记录分成个组，所有距离为gap的记录在同一组，
//并对每一组内的记录进行排序，然后取
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


//堆排序(Heapsort)是指利用堆积树（堆）这种数据结构所设计的一种排序算法，它是选择排序的一种。它是
//通过堆来进行选择数据。需要注意的是排升序要建大堆，排降序建小堆。
//大堆：每一个子树都满足双亲大于两个孩子 小堆；每个子树都满足双亲小于孩子
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//向下调整算法
//前提：左右子树都是小堆   
//从根节点开始 选出左右孩子中小的那一个，跟父亲比较，如果比父亲小就交换，然后再继续往下调，调到叶子结点就终止
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
		//1.选出左右孩子中小的那一个
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

//向上调整算法 上面的最大 下面的最小
void AdjustUp(int* arr, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//1.选出左右孩子中大的那一个
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

//左右子树不是小堆，倒着从最后一颗子树开始调,叶子树不用调，从最后一个非叶子开始调
//void HeapSort(int* arr, int n)
//{
//	//把数组建成堆 - 建堆
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

//排升序，建大堆   排降序,建小堆
//选择排序，通过堆来选数
//如果是建小堆，最小数在堆顶，已经被选出来了，那么在剩下的数再去选数，但是剩下树结构都乱了，需要重新建堆才能选下一个数
//建堆的时间复杂度是O(N)，那么这样不是不可以，但是堆排序就没有效率优势
//把最大的换到最后，不看做是堆里面的，前n-1个数向下调整，选出次大的数，再跟倒数第二个位置交换
//建堆的时间复杂度为O(N)
//整体时间复杂度O(N*logN)
void HeapSort(int* arr, int n)
{
	while (n > 0)
	{
		//把数组建成堆 - 建堆
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


//直接选择排序  时间复杂度O(N*N)
//很差，因为最好情况也是O(N*N)
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
		//如果begin和max重叠，需要修正下max的位置
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


//冒泡排序 时间复杂度O(N*N)  最好情况是O(N)
//跟直接插入排序相比 直接插入更好
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
 

