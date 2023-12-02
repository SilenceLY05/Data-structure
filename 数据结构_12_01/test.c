#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//20.有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。有效字符串需满足：
//左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。每个右括号都有一个对应的相同类型的左括号。
//bool isValid(char* s) {
//    int size = 1;
//    int n = 0;
//    int i = 0;
//    char* arr = (char*)malloc(size * sizeof(char));
//    while (*s)
//    {
//        if (*s == '(' || *s == '[' || *s == '{')
//        {
//            if (n == size)
//            {
//                size *= 2;
//                arr = realloc(arr, size * sizeof(char));
//            }
//            arr[n++] = *s;
//        }
//        else
//        {
//            if (n == 0)
//            {
//                free(arr);
//                return false;
//            }
//            if ((*s == ')' && arr[n - 1] != '(') || (*s == ']' && arr[n - 1] != '[') || (*s == '}' && arr[n - 1] != '{'))
//            {
//                free(arr);
//                return false;
//            }
//            n--;
//        }
//        s++;
//    }
//    free(arr);
//    return n == 0;
//}



typedef char STDataType;

typedef struct Stack
{
    STDataType* _a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps)
{
    assert(ps);

    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->_a == NULL)
    {
        printf("realloc fail\n");
        exit(-1);
    }
    ps->capacity = 4;
    //初始top给0意味着top指向的是栈顶元素的下一个，初始化top为-1意味着top指向的是栈顶元素
    ps->top = 0;
}


void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->_a);
    ps->_a = NULL;
    ps->top = ps->capacity = 0;
}

//栈顶插入删除数据
//入栈
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //满了就增容
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->_a, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            ps->_a = tmp;
            ps->capacity *= 2;
        }
    }
    ps->_a[ps->top] = x;
    ps->top++;


}
//出栈
void StackPop(ST* ps)
{
    assert(ps);
    //如果栈空了，调用Pop,直接终止程序报错
    assert(ps->top > 0);

    ps->top--;

}

STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->_a[ps->top - 1];
}


int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;

}


int StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;

}

bool isValid(char* s) {
    ST st;
    StackInit(&st);
    while (*s)
    {
        switch (*s)
        {
        case'{':
        case'(':
        case'[':
        {
            StackPush(&st, *s);
            ++s;
            break;
        }
        case'}':
        case']':
        case')':
        {
            if (StackEmpty(&st))
            {
                StackDestory(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == ')' && top != '(') || (*s == ']' && top != '[') || (*s == '}' && top != '{'))
            {
                StackDestory(&st);
                return false;
            }
            else
            {
                ++s;
            }
            break;
        }
        default:
            break;
        }
    }
    bool ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}



//225 用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
// 实现 MyStack 类：void push(int x) 将元素 x 压入栈顶。int pop() 移除并返回栈顶元素。int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
typedef int QDataType;

typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;


void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;

}


void QueueDestory(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}


void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->tail == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}


void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }


}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->tail->data;
}

int QueueSize(Queue* pq)
{
    assert(pq);

    int num = 0;
    QNode* cur = pq->head;
    while (cur != NULL)
    {
        ++num;
        cur = cur->next;
    }
    return num;
}
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QueueInit(&ps->q1);
    QueueInit(&ps->q2);

    return ps;
}

void myStackPush(MyStack* obj, int x) {
    assert(obj);
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }

}

int myStackPop(MyStack* obj) {
    assert(obj);
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    if (!QueueEmpty(emptyQ))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }
    //倒数据

    while (QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }

    //要删除掉的
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);
    return top;
}

int myStackTop(MyStack* obj) {
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/




//232. 用栈实现队列
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾int pop(), 从队列的开头移除并返回元素,int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
typedef int STDataType;

typedef struct Stack
{
    STDataType* _a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps)
{
    assert(ps);

    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->_a == NULL)
    {
        printf("realloc fail\n");
        exit(-1);
    }
    ps->capacity = 4;
    //初始top给0意味着top指向的是栈顶元素的下一个，初始化top为-1意味着top指向的是栈顶元素
    ps->top = 0;
}


void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->_a);
    ps->_a = NULL;
    ps->top = ps->capacity = 0;
}

//栈顶插入删除数据
//入栈
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //满了就增容
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->_a, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            ps->_a = tmp;
            ps->capacity *= 2;
        }
    }
    ps->_a[ps->top] = x;
    ps->top++;


}
//出栈
void StackPop(ST* ps)
{
    assert(ps);
    //如果栈空了，调用Pop,直接终止程序报错
    assert(ps->top > 0);

    ps->top--;

}

STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->_a[ps->top - 1];
}


int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;

}


int StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;

}


typedef struct {
    ST push;
    ST pop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* ps = (MyQueue*)malloc(sizeof(MyQueue));
    if (ps == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    StackInit(&ps->push);
    StackInit(&ps->pop);
    return ps;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    StackPush(&obj->push, x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    if (StackEmpty(&obj->pop))
    {
        while (!StackEmpty(&obj->push))
        {
            StackPush(&obj->pop, StackTop(&obj->push));
            StackPop(&obj->push);
        }
    }
    //倒数据

    //要删除掉的
    int top = StackTop(&obj->pop);
    StackPop(&obj->pop);
    return top;
}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->pop))
    {
        while (!StackEmpty(&obj->push))
        {
            StackPush(&obj->pop, StackTop(&obj->push));
            StackPop(&obj->push);
        }
    }
    return StackTop(&obj->pop);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->push) && StackEmpty(&obj->pop);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->pop);
    StackDestory(&obj->push);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/