#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Queue.h"







//1.������ṹ
//1.1���ĸ������һ�ַ����Ե����ݽṹ��������n(n>=0)�����޽ڵ����һ�����в�ι�ϵ�ļ��ϡ���������������Ϊ��������
//��һ�ŵ��ҵ�����
//��һ������Ľڵ㣬��Ϊ���ڵ㣬���ڵ�û��ǰ�����
//�����ڵ��⣬����ڵ㱻�ֳ�M(M>0)�������ཻ�ļ���T1��T2....Tm������ÿһ���Ti(1<=i<=m)����һ�Žṹ�������Ƶ�������
//ÿ�������ĸ��ڵ����ҽ���һ��ǰ��������0���������
//��ˣ����ǵݹ鶨���


////���Ľṹ���巽�������� ���ֵ�
//typedef int DataTypde;
//struct Node
//{
//	struct Node* firstChild;   //��һ�����ӽڵ�
//	struct Node* pNextBrother; //ָ������һ���ֵܽڵ�
//	DataTypde data;            //�ڵ��е�����
//};


//˫�ױ�ʾ���������漰˫�׵Ĳ�������ڵ�ĺ���ʱ����Ҫ����������

//����ʵ��Ӧ�ã��ļ�ϵͳ��Ŀ¼���ṹ


//������
//һ�ö������ǽ���һ�����޼��ϣ��ü���:1. ����Ϊ�� 2. ��һ�����ڵ�������ñ��Ϊ���������������Ķ��������
//���������ص㣺1. �����������ڶȴ���2�Ľ�� 2. ������������������֮�֣������ܵߵ�����˶�������������
//�κ�һ�����������������ֹ��ɣ�1�����ڵ� 2�������� 3��������
//ǰ���ȸ������� ������ ������ A -> B -> D 
//�����и����������� �� ������
//���������򣩣������� ������ �� 
//ǰ�� ���� ����Ҳ��������ȱ���
//������� ������ȱ���  ��������ʵ�� ���е��Ƚ��ȳ� ����˼·������һ�����һ��


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;


void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c  ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
		
	InOrder(root->left);

	printf("%c  ", root->data);
	
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c  ", root->data);
}


//int TreeSize(BTNode* root)
//{
//	static int num = 0;
//	if (root == NULL)
//	{
//		return;
//	}
//
//	num++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return num;
//}

//void TreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//
//	(*psize)++;
//	TreeSize(root->left,psize);
//	TreeSize(root->right,psize);
//
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->right) + TreeSize(root->left) + 1;
}


////��������Ҷ�ӽ��ĸ���
//int TreeLeafSize(BTNode* root)
//{
//	static int num = 0;
//	if (root == NULL)
//	{
//		return;
//	}
//
//	if ((root->left == NULL) && (root->right == NULL))
//		num++;
//	TreeLeafSize(root->left);
//	TreeLeafSize(root->right);
//	return num;
//}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
		
	if ((root->left == NULL) && (root->right == NULL))
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


void LevelOrder(BTNode* root)
{ 
	//����˼· ��һ�����ʱ�����һ���
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}

	printf("\n");

	QueueDestory(&q);
}



int main()
{
	BTNode* A = (BTNode *)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	/*int num = TreeSize(A);*/
	int Asize = TreeLeafSize(A);
	printf("%d \n", Asize);
	LevelOrder(A);
	return 0;
}



//��������������һ�����������߶���h���ܽ��ĸ�����N 2^h - 1 = N h = log2(N+1)
//��ȫ���������������ĸ߶���h 1.ǰh-1�㶼������ 2.���һ�㲻�����������һ��������Ҷ���������
//�������������κ�һ���������������ȸ�ҪС�����������ȸ�Ҫ�����������в���һ�����������Ҹ߶ȴ�
//ʱ�临�Ӷȣ�O(N)


//�����������ʣ�1. ���涨���ڵ�Ĳ���Ϊ1����һ�÷ǿն������ĵ�i���������2^(i-1) �����.
//2. ���涨���ڵ�Ĳ���Ϊ1�������Ϊh�Ķ����������������2^h-1.
//3. ���κ�һ�ö�����, �����Ϊ0��Ҷ������Ϊn0, ��Ϊ2�ķ�֧������Ϊn2, ����n0��n2��1
//4. ���涨���ڵ�Ĳ���Ϊ1������n������������������ȣ�h =log2(N+1) . (ps��log2(N+1) ��log��2Ϊ�ף�n + 1Ϊ����)
//5. ���ھ���n��������ȫ��������������մ������´������ҵ�����˳������нڵ��0��ʼ��ţ���������Ϊi�Ľ���У�
//   1. ��i>0��iλ�ýڵ��˫����ţ�(i-1)/2��i=0��iΪ���ڵ��ţ���˫�׽ڵ�
//   2. ��2i + 1 < n��������ţ�2i + 1��2i + 1 >= n����������
//   3. ��2i + 2 < n���Һ�����ţ�2i + 2��2i + 2 >= n�������Һ���
//����2n����ȫ�������У�Ҷ�ӽ�����Ϊ n



//144 ��������ǰ�����
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
//����iΪʲô������ȫ�ֱ���������ʱ�úü������������в��ԣ�ȫ�ֱ���ֵ���ۼ�

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	
};
int TreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : TreeSize(root->right) + TreeSize(root->left) + 1;
}

void _prevOrder(struct TreeNode* root, int* a, int* i)
{
	if (root == NULL)
		return;
	a[(*i)] = root->val;
	(*i)++;
	_prevOrder(root->left, a, i);
	_prevOrder(root->right, a, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = TreeSize(root);
	int* arr = (int*)malloc(size * sizeof(int));
	int i = 0;
	_prevOrder(root, arr, &i);
	*returnSize = size;

	return arr;
}


//104  ��������������
//����һ�������� root �������������ȡ��������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
int maxDepth(struct TreeNode* root) {

	if (root == NULL)
	{
		return 0;
	}

	int leftnum = maxDepth(root->left);
	int rightnum = maxDepth(root->right);
	int max = leftnum > rightnum ? leftnum : rightnum;
	return max + 1;
}



