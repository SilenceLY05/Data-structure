#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


//常见的时间复杂度：O(N) O(N^2) O(logN) O(1)

//空间复杂度是对一个算法在运行时临时占用存储空间大小的量度。算的是变量的个数
//时间是累计的，空间是不累计的
////时间复杂度为O(N^2)  时间复杂度是一个估算，是去看表达式中影响最大的那一项
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}


////时间复杂度为O(N) 
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d", count);
//}


////时间复杂度为O(N+M)
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d", count);
//}

////时间复杂度为O(1)
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

////strchr时间复杂度为O(N )
//const char* strchr(const char* str, char character)
//{
//	while (*str != '\0')
//	{
//		if(*str == character)
//			return str;
//		++str;
//	}
//	return NULL;
//}

////时间复杂度为O(N^2)  空间复杂度：O(1)
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] < a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}


////时间复杂度为O(logN),算法的复杂度结算，喜欢省略简写成logN，因为很多地方不好写底数
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}

////时间复杂度为O(N)  递归了N次，每次递归运算O(1)，整体就是O(N)   空间复杂度为：O(N)
////递归调用了N层，每次调用建立一个栈帧，每个栈帧使用了常数个空间 O(1)
//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1) * N;
//}


////时间复杂度为：O(N)  空间复杂度为：O(N) 因为使用了malloc  大多数情况下空间复杂度为O(1),malloc的为O(N)
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}



////数组num包含从0到n的所有整数，但其中缺了一个，找出缺失的数字，时间复杂度为O(n)
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		ret ^= nums[i];
//		ret ^= i;
//	}
//	return ret ^ numsSize;
//
//}
//
//int missingNumber2(int* nums, int numsSize)
//{
//	int i = 0;
//	int ret = 0;
//	int ret2 = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		ret += nums[i];
//		ret2 += i;
//	}
//	return ret2 + numsSize - ret;
//
//}
//
////给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//void rotate(int* nums,int numsSize,int k)
//{
//	k = k % numsSize;
//	while(k--)
//	{
//		int tmp = nums[numsSize -1];
//		for(int end = numsSize -2;end>=0;end--)
//		{
//			nums[end+1] = nums[end];
//		}
//		nums[0] = tmp;
//	}
//}//数组较小时可以使用这种方式


//顺序表
//1.线性表：是n个具有相同特性的数据元素的有限序列，线性表是一种在实际中广泛使用的数据结构，常见的线性表：顺序表、链表
//栈、队列、字符串……
//吓你星标在逻辑上是线性结构，也就是说是连续的一条直线，但在结构上并不一定，线性表在物理上存储是，通常以数组和链式结构存储


void TestSeqList1()
{
	SL2 s2;
	SeqListInit(&s2);
	SeqListPushFront(&s2, 1);
	SeqListPushFront(&s2, 2);
	SeqListPushFront(&s2, 3);
	SeqListPushFront(&s2, 4);
	SeqListPushFront(&s2, 5);
	SeqListPushFront(&s2, 6);
	SeqListPushFront(&s2, 7);
	SeqListPushFront(&s2, 8);
	SeqListPushFront(&s2, 9);
	SeqListPushFront(&s2, 10);
	SeqListPushFront(&s2, 11);
	SeqListPrint(&s2);
	SeqListPopBack(&s2);
	SeqListPrint(&s2);
}

void menu()
{
	printf("**************************************\n");
	printf("*****  1.尾插数据    2.头插数据  *****\n");
	printf("*****  3.尾删数据    4.头删数据  *****\n");
	printf("*****  5.打印数据    6.退出      *****\n");
	printf("**************************************\n");
}
int main()
{
	//TestSeqList1();
	menu();

	return 0;
}