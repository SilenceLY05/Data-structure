#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//反转链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


struct ListNode {
     int val;
     struct ListNode *next;
};
 
//双指针法
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

//头插法:取原链表的节点，头插到新链表
struct ListNode* reverseList(struct ListNode* head) {
   
    struct ListNode* newnode = NULL;
    
    while (head != NULL)
    {
        struct ListNode* next =  head->next;
        head->next = newnode;
        newnode = head;
        head = next;
    }
    return newnode;
}



//链表的中间节点
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。

//遍历两次找到中间节点 
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* pos = head;
    struct ListNode* cur = head;
    int num = 0;
    while (cur != NULL)
    {
        num++;
        cur = cur->next;
    }
    int mid = num / 2;
    for (num = 0; num < mid; num++)
    {
        pos = pos->next;
    }
    return pos;
}


//快慢指针方法 pos一次走一个节点 cur一次走两个节点，当快指针到达链表末尾时，慢指针将位于链表的中间
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* pos = head;
    struct ListNode* cur = head;
    while (cur != NULL && cur->next != NULL)
    {
        pos = pos->next;
        cur = cur->next->next;

    }

    return pos;
}


//21 合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//思路：从头开始，去两个链表中小的那个尾插到新链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode* tail = NULL;
    struct ListNode* head = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            if (tail == NULL)
            {
                head = list1;
                tail = list1;
            }
            else {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (tail == NULL)
            {
                head = list2;
                tail = list2;
            }
            else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != NULL)
        tail->next = list1;
    if (list2 != NULL)
        tail->next = list2;
    return head;
}


//使用一个哑结点，避免处理头结点为空的情况
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}



//141环形链表 
//给你一个链表的头节点 head ，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
//则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

//请证明slow和fast一定会在环里面相遇吗 有没有可能永远追不上
//slow一次走一步，fast一次走三步行不行
//slow一次走一步 fast一次走两步一定能追上  slow进环了以后，fast正式开始追，假设fast和slow之间的距离是N，
//追的过程中，他们之间的距离变化是1。
//如果slow每次走1步，fast走三步，不一定能追上，有可能陷入死循环



//142 环形链表 II
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//一个指针从meet点开始走，一个指针从链表的开始走 会在入口点相遇
//fast走的路程是slow路程的2倍，slow进环了以后，fast一定会追上慢指针 。slow指针进环之前，fast有可能在里面转了N圈，
//如果入环前的长度越长，环越小，N越大。如果入环前的长度越短，环很大，那N就是1，fast只转了1圈。
//假设环的长度为C，入环前的步长为L 在slow在入环后的X步与fast相遇。L+N*C+X= 2(L+X)  N*C = L+X   N*C-X = L  (N-1)*C+C-X= L

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int Cycle = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Cycle = 1;
            break;
        }

    }
    if (Cycle)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}




//顺序表：
//优点：空间连续，支持随机访问 缺点：中间或前面部分的插入删除时间复杂度O(N) 增容的代价比较大

//链表(带头双向循环)：
//缺点：以节点为单位存储，不支持随机访问   优点：任意位置插入删除时间复杂度为O(1) 没有增容消耗，按需申请节点空间，不用就释放
