#include "Queue.h"
#include "Stack.h"

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


void Print(int* arr, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void InsertSort(int* arr, int num)
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
	}
}


void ShellSort(int* arr, int num)
{
	int gap = num;
	while (gap > 1)
	{
		gap /= 2;
		int i = 0;
		for (i = 0; i <= num - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end-= gap;
				}
				else
					break;
			}
			arr[end + gap] = tmp;
		}
	}
	
}


void TestInsertSort()
{
	int arr[] = { 2,1,3,4,5,2,3,35,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	Print(arr, size);
}


void TestShellSort()
{
	int arr[] = { 2,1,3,4,5,2,3,35,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	Print(arr, size);
}

void Swap(int* addr1, int* addr2)
{
	int tmp = 0;
	tmp = *addr1;
	*addr1 = *addr2;
	*addr2 = tmp;
}


//建小堆
void AdjustDown(int* arr, int num, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child<num)
	{
		if (child + 1 < num &&arr[child] > arr[child + 1])
			child++;
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}


//建大堆
void AdjustUp(int* arr, int num, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < num)
	{
		if (child + 1 < num && arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, int num)
{
	while (num > 0)
	{
		int i = 0;
		for (i = (num - 1 - 1) / 2; i >= 0; i--)
		{
			//AdjustDown(arr, num, i);
			AdjustUp(arr, num, i); 
		}
		Swap(&arr[0], &arr[num-1]);
		num--;
	}
}



void TestHeapSort()
{
	int arr[] = { 2,1,3,4,5,2,3,35,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	Print(arr, size);
}



void SelectSort(int* arr, int num)
{
	int begin = 0;
	int end = num - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
		}
		Swap(&arr[begin], &arr[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&arr[end], &arr[maxi]);
		begin++;
		end--;
	}
}



void TestSelectSort()
{
	int arr[] = { 2,1,3,4,5,2,3,35,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	Print(arr, size);
}



void BubbleSort(int* arr, int num)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < num; i++)
	{
		int exchange = 0;
		for (j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}


void TestBubbleSort()
{
	int arr[] = { 2,1,3,4,5,2,3,35,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	Print(arr, size);
}


//void QuickSort(int* arr, int left,int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = arr[begin];
//	while (begin < end)
//	{
//		while (end > begin && arr[end] >= key)
//			end--;
//
//		arr[pivot] = arr[end];
//		pivot = end;
//
//		while (end > begin && arr[begin] <= key)
//			begin++;
//
//		arr[pivot] = arr[begin];
//		pivot = begin;
//			
//	}
//	pivot = begin;
//	arr[pivot] = key;
//
//	QuickSort(arr, left, pivot - 1);
//	QuickSort(arr, pivot + 1,right );
//}


int GetMidIndix(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else
	{
		if (arr[mid] > arr[right])
			return mid;
		else if (arr[right] > arr[left])
			return left;
		else
			return right;
	}
}

//挖坑法
int PartSort1(int* arr, int left, int right)
{
	int begin = left, end = right;
	int Index = GetMidIndix(arr, left, right);
	Swap(&arr[begin], &arr[Index]);

	int pivot = begin;
	int key = arr[begin];
	while (begin < end)
	{
		while (end > begin && arr[end] >= key)
			end--;

		arr[pivot] = arr[end];
		pivot = end;

		while (end > begin && arr[begin] <= key)
			begin++;

		arr[pivot] = arr[begin];
		pivot = begin;

	}
	pivot = begin;
	arr[pivot] = key;

	return pivot;
}


//左右指针法
int PartSort2(int* arr, int left, int right)
{
	int begin = left, end = right;
	int Index = GetMidIndix(arr, left, right);
	Swap(&arr[begin], &arr[Index]);

	int key = begin;

	while (begin < end)
	{
		while (end > begin && arr[end] >= arr[key])
			end--;

		while (end > begin && arr[begin] <= arr[key])
			begin++;

		Swap(&arr[begin], &arr[end]);

	}
	Swap(&arr[begin], &arr[key]);

	return begin;
}


int PartSort3(int* arr, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int index = GetMidIndix(arr, left, right);
	Swap(&arr[left], &arr[index]);
	int key = left;
	while (cur <= right)
	{
		while (arr[cur] < arr[key] && ++prev!=cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
		
	}
	Swap(&arr[key], &arr[prev]);
	return prev;
}


void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int keyIndex = PartSort2(arr, left, right);

	if (keyIndex - 1 - left > 10)
	{
		QuickSort(arr, left, keyIndex - 1);
	}
	else
	{
		InsertSort(arr + left, keyIndex - 1 - left + 1);
	}

	if (right - keyIndex - 1 > 10)
	{
		QuickSort(arr, keyIndex + 1, right);
	}
	else
	{
		InsertSort(arr + keyIndex + 1, right - keyIndex - 1 + 1);
	}

}



void QuickSortNonR(int* arr, int num)
{
	ST st;
	StackInit(&st);

	StackPush(&st, num - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int KeyIndex = PartSort1(arr, left, right);

		if (KeyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, KeyIndex + 1);
		}

		if (left < KeyIndex - 1)
		{
			StackPush(&st, KeyIndex - 1);
			StackPush(&st, left);
		}
	}

	StackDestory(&st);
}


void TestQuickSort()
{
	int arr[] = { 6,1,2,7,9,11,4,5,10,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr,0, size-1);
	Print(arr, size);
}


//归并
void _MergeSort(int* arr, int left, int right,int* arr2)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	_MergeSort(arr, left, mid, arr2);
	_MergeSort(arr, mid + 1, right, arr2);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 < end1 && begin2 < end2)
	{
		
		if (arr[begin1] < arr[begin2])
		{
			arr2[i++] = arr[begin1++];
		}
		else
		{
			arr2[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		arr2[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		arr2[i++] = arr[begin2++];
	}
	for (i = left; i < right; i++)
	{
		arr[i] = arr2[i];
	}
}


void MergeSort(int* arr, int num)
{
	int* arr2 = (int*)malloc(sizeof(int) * num);
	if (arr2 == NULL)
		return;
	_MergeSort(arr, 0, num - 1, arr2);

	free(arr2);
}



void MergeSortNonR(int* arr, int num)
{
	if (arr == NULL || num <= 0)
		return;

	int* arr2 = (int*)malloc(sizeof(int) * num);
	if (arr2 == NULL)
		return;



	free(arr2);
}


int main()
{
	TestQuickSort();

	return 0;
}