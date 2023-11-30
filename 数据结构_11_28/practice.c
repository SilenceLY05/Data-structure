#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"


//������ʱ�临�Ӷȣ�O(N) O(N^2) O(logN) O(1)

//�ռ临�Ӷ��Ƕ�һ���㷨������ʱ��ʱռ�ô洢�ռ��С�����ȡ�����Ǳ����ĸ���
//ʱ�����ۼƵģ��ռ��ǲ��ۼƵ�
////ʱ�临�Ӷ�ΪO(N^2)  ʱ�临�Ӷ���һ�����㣬��ȥ�����ʽ��Ӱ��������һ��
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


////ʱ�临�Ӷ�ΪO(N) 
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


////ʱ�临�Ӷ�ΪO(N+M)
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

////ʱ�临�Ӷ�ΪO(1)
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}

////strchrʱ�临�Ӷ�ΪO(N )
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

////ʱ�临�Ӷ�ΪO(N^2)  �ռ临�Ӷȣ�O(1)
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


////ʱ�临�Ӷ�ΪO(logN),�㷨�ĸ��ӶȽ��㣬ϲ��ʡ�Լ�д��logN����Ϊ�ܶ�ط�����д����
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

////ʱ�临�Ӷ�ΪO(N)  �ݹ���N�Σ�ÿ�εݹ�����O(1)���������O(N)   �ռ临�Ӷ�Ϊ��O(N)
////�ݹ������N�㣬ÿ�ε��ý���һ��ջ֡��ÿ��ջ֡ʹ���˳������ռ� O(1)
//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1) * N;
//}


////ʱ�临�Ӷ�Ϊ��O(N)  �ռ临�Ӷ�Ϊ��O(N) ��Ϊʹ����malloc  ���������¿ռ临�Ӷ�ΪO(1),malloc��ΪO(N)
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



////����num������0��n������������������ȱ��һ�����ҳ�ȱʧ�����֣�ʱ�临�Ӷ�ΪO(n)
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
////����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
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
//}//�����Сʱ����ʹ�����ַ�ʽ


//˳���
//1.���Ա���n��������ͬ���Ե�����Ԫ�ص��������У����Ա���һ����ʵ���й㷺ʹ�õ����ݽṹ�����������Ա�˳�������
//ջ�����С��ַ�������
//�����Ǳ����߼��������Խṹ��Ҳ����˵��������һ��ֱ�ߣ����ڽṹ�ϲ���һ�������Ա��������ϴ洢�ǣ�ͨ�����������ʽ�ṹ�洢


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
	printf("*****  1.β������    2.ͷ������  *****\n");
	printf("*****  3.βɾ����    4.ͷɾ����  *****\n");
	printf("*****  5.��ӡ����    6.�˳�      *****\n");
	printf("**************************************\n");
}
int main()
{
	//TestSeqList1();
	menu();

	return 0;
}