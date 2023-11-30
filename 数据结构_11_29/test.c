#include "SList.h"

////LeetCode 27.�Ƴ�Ԫ��
////��һ�ַ��� �����������飬ʱ�临�Ӷ�ΪO(N^2)
//int removeElement(int* nums, int numsSize, int val) {
//    int i = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == val)
//        {
//            if (i < numsSize - 1)
//            {
//                for (int j = i; j < numsSize - 1; j++)
//                {
//                    nums[j] = nums[j + 1];
//                }
//                i--;
//            }
//
//            numsSize--;
//        }
//    }
//    return numsSize;
//}
//
////�ڶ��ַ��� ʹ��˫ָ�� ���Žⷨ
//int removeElement(int* nums, int numsSize, int val) {
//    int k = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] != val)
//        {
//            nums[k] = nums[i];
//            k++;
//        }
//    }
//    return k;
//}
//
//
//
////LeetCode  88. �ϲ�������������
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int i = m - 1;
//    int j = n - 1;
//    int k = m + n - 1;
//    while (j >= 0)
//    {
//        if (i<0 || nums2[j]>nums1[i])
//        {
//            nums1[k--] = nums2[j--];
//        }
//        else
//        {
//            nums1[k--] = nums1[i--];
//        }
//    }
//}


//����:������һ������洢�ṹ�Ϸ����ӡ���˳��Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵġ�
//�����ʾ��ʵ�� - ������   

//��̬˳���
//1���������ݣ��ռ䲻���ˣ�Ҫ����
//2��Ҫ�����������δ洢��
//ȱ�㣺1.����ռ䲻���ˣ����ݻḶ��һ���������ģ���ο��ܴ���һ���Ŀռ��˷�
//2.��ͷ�������в����ҵĲ���Ч�ʵ� ->O(N)
//��ν����1���ռ��ϰ�����ռ�  2����Ҫ������ռ�������ͷ�����м�Ĳ���Ͳ���ҪŲ������


void TestSList1()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPushFront(&plist, 5);
    SListPrint(plist);
    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPrint(plist);
}

void TestSList2()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPushFront(&plist, 5);
    SListPrint(plist);

    //����3��ǰ�����һ��30
    SLTNode* pos = SListFind(plist, 3);
    if (pos)
    {
        SListInsert(&plist, pos, 30);
    }
    SListPrint(plist);
}

void TestSList3()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPushFront(&plist, 5);
    SListPrint(plist);
    SLTNode* pos = SListFind(plist, 3);
    if (pos)
    {
        SListErase(&plist, pos, 30);
    }
    SListPrint(plist);
    
}


int main()
{
    TestSList3();
    return 0;
}

//��������ڵ�ȱ�ݣ����ܴӺ���ǰ��  ���������˫������