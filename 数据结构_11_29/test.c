#include "SList.h"

////LeetCode 27.移除元素
////第一种方法 遍历整个数组，时间复杂度为O(N^2)
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
////第二种方法 使用双指针 最优解法
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
////LeetCode  88. 合并两个有序数组
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


//链表:链表是一种物理存储结构上非连接、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。
//链表表示和实现 - 单链表   

//动态顺序表
//1、插入数据，空间不够了，要增容
//2、要求数据是依次存储的
//缺点：1.如果空间不够了，增容会付出一定性能消耗，其次可能存在一定的空间浪费
//2.在头部或者中部左右的插入效率低 ->O(N)
//如何解决：1、空间上按需给空间  2、不要求物理空间连续，头部和中间的插入就不需要挪动数据


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

    //想在3的前面插入一个30
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

//单链表存在的缺陷：不能从后往前走  解决方案是双向链表