#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//��ת����
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������


struct ListNode {
     int val;
     struct ListNode *next;
};
 
//˫ָ�뷨
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

//ͷ�巨:ȡԭ����Ľڵ㣬ͷ�嵽������
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



//������м�ڵ�
//���㵥�����ͷ��� head �������ҳ�������������м��㡣����������м��㣬�򷵻صڶ����м��㡣

//���������ҵ��м�ڵ� 
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


//����ָ�뷽�� posһ����һ���ڵ� curһ���������ڵ㣬����ָ�뵽������ĩβʱ����ָ�뽫λ��������м�
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


//21 �ϲ�������������
//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//˼·����ͷ��ʼ��ȥ����������С���Ǹ�β�嵽������
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


//ʹ��һ���ƽ�㣬���⴦��ͷ���Ϊ�յ����
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



//141�������� 
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л��������������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε��
//�������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ��
//ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������

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

//��֤��slow��fastһ�����ڻ����������� ��û�п�����Զ׷����
//slowһ����һ����fastһ���������в���
//slowһ����һ�� fastһ��������һ����׷��  slow�������Ժ�fast��ʽ��ʼ׷������fast��slow֮��ľ�����N��
//׷�Ĺ����У�����֮��ľ���仯��1��
//���slowÿ����1����fast����������һ����׷�ϣ��п���������ѭ��



//142 �������� II
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//һ��ָ���meet�㿪ʼ�ߣ�һ��ָ�������Ŀ�ʼ�� ������ڵ�����
//fast�ߵ�·����slow·�̵�2����slow�������Ժ�fastһ����׷����ָ�� ��slowָ�����֮ǰ��fast�п���������ת��NȦ��
//����뻷ǰ�ĳ���Խ������ԽС��NԽ������뻷ǰ�ĳ���Խ�̣����ܴ���N����1��fastֻת��1Ȧ��
//���軷�ĳ���ΪC���뻷ǰ�Ĳ���ΪL ��slow���뻷���X����fast������L+N*C+X= 2(L+X)  N*C = L+X   N*C-X = L  (N-1)*C+C-X= L

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




//˳���
//�ŵ㣺�ռ�������֧��������� ȱ�㣺�м��ǰ�沿�ֵĲ���ɾ��ʱ�临�Ӷ�O(N) ���ݵĴ��۱Ƚϴ�

//����(��ͷ˫��ѭ��)��
//ȱ�㣺�Խڵ�Ϊ��λ�洢����֧���������   �ŵ㣺����λ�ò���ɾ��ʱ�临�Ӷ�ΪO(1) û���������ģ���������ڵ�ռ䣬���þ��ͷ�
