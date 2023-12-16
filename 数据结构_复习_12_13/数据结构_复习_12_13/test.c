#include "Queue.h"

//void Test()
//{
//	SL s1;
//	SeqListInit(&s1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushBack(&s1, 1);
//	SeqListPushFront(&s1, 2);
//
//	SeqListPrint(&s1);
//	SeqListPopBack(&s1);
//	SeqListPrint(&s1);
//	SeqListPopFront(&s1);
//	SeqListPrint(&s1);
//	SeqListInsert(&s1, 2, 3);
//	SeqListPrint(&s1);
//	SeqListErase(&s1, 2);
//	SeqListPrint(&s1);
//}




//void TestSLTNode(void)
//{
//	SLTNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//	SListPushBack(&plist, 4);
//	SListPushFront(&plist, 5);
//	SListPrint(plist);
//	SLTNode* pos = SListFint(plist, 3);
//	if (pos)
//	{
//		SListInsert(&plist, pos, 30);
//	}
//	SListPrint(plist);
//}


//void TestList()
//{
//	LTNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 4);
//	ListPushBack(plist, 5);
//	ListPushBack(plist, 6);
//	ListPrint(plist);
//	ListPushFront(plist, 7);
//	ListPushFront(plist, 8);
//	ListPushFront(plist, 9);
//	ListPrint(plist);
//	ListPopBack(plist);
//	ListPopFront(plist);
//	ListPrint(plist);
//
//	LTNode* pos = ListFint(plist, 3);
//	if (pos == NULL)
//	{
//		return;
//	}
//	else
//	{
//		ListInsert(pos, 30);
//	}
//	ListDestory(plist);
//}
//
//int main()
//{
//	TestList();
//
//	return 0;
//}
//
//
//struct ListNode* middleNode(struct ListNode* head) {
//	struct ListNode* pos = head;
//	struct ListNode* cur = head;
//	while (cur != NULL && cur->next != NULL)
//	{
//		pos = pos->next;
//		cur = cur->next->next;
//	}
//
//	return pos;
//}
//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//		return list2;
//	if (list2 == NULL)
//		return list1;
//
//	struct ListNode dummy;
//	struct ListNode* tail = &dummy;
//	while (list1 != NULL && list2 != NULL)
//	{
//		if (list1->val < list2->val)
//		{
//			tail->next = list1;
//			list1 = list1->next;
//		}
//		else
//		{
//			tail->next = list2;
//			list2 = list2->next;
//		}
//		tail = tail->next;
//	}
//	tail->next = list1 ? list1 : list2;
//	return dummy.next;
//}
//
//
//bool hasCycle(struct ListNode* head) {
//	if (head == NULL)
//		return NULL;
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//			return true;
//	}
//	return false;
//}
//
//
//struct ListNode* detectCycle(struct ListNode* head) {
//	if (head == NULL)
//		return NULL;
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	int Cycle = 0;
//	while (fast != NULL && fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			Cycle = 1;
//			break;
//		}
//
//	}
//	if (Cycle)
//	{
//		slow = head;
//		while (slow != fast)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//	return NULL;
//}




//int main()
//{
//	ST st;
//	StackInit(&st);
//
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	StackPush(&st, 5);
//
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//
//	StackDestory(&st);
//
//	return 0;
//}

//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//
//	while (!QueueEmpty(&q))
//	{
//		printf("%d ", QueueFront(&q));
//		QueuePop(&q);
//	}
//
//
//	QueueDestory(&q);
//}
//
//
//int main()
//{
//	TestQueue();
//
//	return 0;
//}




//bool isValid(char* s) {
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		switch (*s)
//		{
//		case'{':
//		case'(':
//		case'[':
//		{
//			StackPush(&st, *s);
//			++s;
//			break;
//		}
//		case'}':
//		case']':
//		case')':
//		{
//			if (StackEmpty(&st))
//			{
//				StackDestory(&st);
//				return false;
//			}
//			char top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == ')' && top != '(') || (*s == ']' && top != '[') || (*s == '}' && top != '{'))
//			{
//				StackDestory(&st);
//				return false;
//			}
//			else
//			{
//				++s;
//			}
//			break;
//		}
//		default:
//			break;
//		}
//	}
//	bool ret = StackEmpty(&st);
//	StackDestory(&st);
//	return ret;
//}




//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BTNode;
//
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//		
//	printf("%c ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}
//
//
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	InOrder(root->left);
//	printf("%c ", root->data);
//	InOrder(root->right);
//}
//
//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%c ", root->data);
//}


//int TreeSize(BTNode* root)
//{
//	static int num = 0;
//	if (root == NULL)
//		return;
//	num++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return num;
//}

//int TreeSize(BTNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//
//int TreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	
//	return TreeLeafSize(root->left)+TreeLeafSize(root->right);
//}
//
//
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ", front->data);
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
//	A->data = 'A';
//	A->left = NULL;
//	A->right = NULL;
//	
//	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
//	B->data = 'B';
//	B->left = NULL;
//	B->right = NULL;
//	
//	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
//	C->data = 'C';
//	C->left = NULL;
//	C->right = NULL;
//	
//	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
//	D->data = 'D';
//	D->left = NULL;
//	D->right = NULL;
//	
//	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
//	E->data = 'E';
//	E->left = NULL;
//	E->right = NULL;
//	
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	PrevOrder(A);
//	printf("\n");
//	int num = TreeSize(A);
//	printf("%d ", num);
//	int num2 = TreeLeafSize(A);
//	printf("%d ", num2);
//
//	LevelOrder(A);
//	return 0;
//}
//
//
//
//
//
//int TreeSize(struct TreeNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->right) + TreeSize(root->left) + 1;
//}
//
//void _prevOrder(struct TreeNode* root, int* a, int* i)
//{
//	if (root == NULL)
//		return;
//	a[(*i)] = root->val;
//	(*i)++;
//	_prevOrder(root->left, a, i);
//	_prevOrder(root->right, a, i);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//	int size = TreeSize(root);
//	int* arr = (int*)malloc(size * sizeof(int));
//	int i = 0;
//	_prevOrder(root, arr, &i);
//	*returnSize = size;
//
//	return arr;
//}
//
//
//int maxDepth(struct TreeNode* root) {
//
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int leftnum = maxDepth(root->left);
//	int rightnum = maxDepth(root->right);
//	int max = leftnum > rightnum ? leftnum : rightnum;
//	return max + 1;
//}
//
//
//
//int maxDepth(struct TreeNode* root) {
//
//	if (root == NULL)
//	{
//		return 0;
//	}
//
//	int leftnum = maxDepth(root->left);
//	int rightnum = maxDepth(root->right);
//	int max = leftnum > rightnum ? leftnum : rightnum;
//	return max + 1;
//}
//
//bool isBalanced(struct TreeNode* root) {
//	if (root == NULL)
//	{
//		return true;
//	}
//	int leftDepth = maxDepth(root->left);
//	int rightDepth = maxDepth(root->right);
//
//	return (abs(leftDepth - rightDepth) <= 1) && isBalanced(root->left) && isBalanced(root->right);
//}
//
//
//
//
//void DestoryTree(BTNode** root)
//{
//	if (*root == NULL)
//		return;
//
//	DestoryTree(( * root)->left);
//	DestoryTree(( * root)->right);
//
//	free(*root);
//	*root = NULL;
//}
//
//
//
//typedef struct TreeNode {
//	char val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//} TNode;
//
//TNode* BuildTree(char* str, int* num) {
//	if (str[*num] == '#') {
//		++(*num);
//		return NULL;
//	}
//
//	TNode* newnode = (TNode*)malloc(sizeof(TNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newnode->val = str[*num];
//	++(*num);
//	newnode->left = BuildTree(str, num);
//	newnode->right = BuildTree(str, num);
//
//	return newnode;
//}
//
//
//void InOrder(struct TreeNode* root) {
//	if (root == NULL)
//		return;
//	InOrder(root->left);
//	printf("%c ", root->val);
//	InOrder(root->right);
//}
//
//int main() {
//	char str[100];
//	scanf("%s", str);
//
//	int i = 0;
//	TNode* root = BuildTree(str, &i);
//	InOrder(root);
//	return 0;
//}



int main()
{


	return 0;
}