#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "Queue.h"







//1.树概念及结构
//1.1树的概念：树是一种非线性的数据结构，它是由n(n>=0)个有限节点组成一个具有层次关系的集合。把它叫做树是因为它看起来
//像一颗倒挂的数，
//有一个特殊的节点，称为根节点，根节点没有前驱结点
//除根节点外，其余节点被分成M(M>0)个互不相交的集合T1、T2....Tm，其中每一额集合Ti(1<=i<=m)又是一颗结构与树类似的子树，
//每棵子树的根节点有且仅有一个前驱，可有0个或多个后继
//因此，树是递归定义的


////树的结构定义方法：左孩子 右兄弟
//typedef int DataTypde;
//struct Node
//{
//	struct Node* firstChild;   //第一个孩子节点
//	struct Node* pNextBrother; //指向其下一个兄弟节点
//	DataTypde data;            //节点中的数据
//};


//双亲表示法：便于涉及双亲的操作，求节点的孩子时，需要遍历整棵树

//树的实际应用：文件系统的目录树结构


//二叉树
//一棵二叉树是结点的一个有限集合，该集合:1. 或者为空 2. 由一个根节点加上两棵别称为左子树和右子树的二叉树组成
//二叉树的特点：1. 二叉树不存在度大于2的结点 2. 二叉树的子树有左右之分，次序不能颠倒，因此二叉树是有序树
//任何一个二叉树由三个部分构成：1、根节点 2、左子树 3、右子树
//前序（先根）：根 左子树 右子树 A -> B -> D 
//中序（中根）：左子树 根 右子树
//后续（后序）：左子树 右子树 根 
//前序 中序 后序也叫深度优先遍历
//层序遍历 广度优先遍历  借助队列实现 队列的先进先出 核心思路就是上一层带下一层


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


////遍历法求叶子结点的个数
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
	//核心思路 上一层出的时候带下一层进
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



//满二叉树：假设一颗满二叉树高度是h，总结点的个数是N 2^h - 1 = N h = log2(N+1)
//完全二叉树：假设树的高度是h 1.前h-1层都是满的 2.最后一层不满，但是最后一层从左往右都是连续的
//搜索二叉树：任何一棵树，左子树都比根要小，右子树都比根要大，在搜索树中查找一个数，最多查找高度次
//时间复杂度：O(N)


//二叉树的性质：1. 若规定根节点的层数为1，则一棵非空二叉树的第i层上最多有2^(i-1) 个结点.
//2. 若规定根节点的层数为1，则深度为h的二叉树的最大结点数是2^h-1.
//3. 对任何一棵二叉树, 如果度为0其叶结点个数为n0, 度为2的分支结点个数为n2, 则有n0＝n2＋1
//4. 若规定根节点的层数为1，具有n个结点的满二叉树的深度，h =log2(N+1) . (ps：log2(N+1) 是log以2为底，n + 1为对数)
//5. 对于具有n个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有节点从0开始编号，则对于序号为i的结点有：
//   1. 若i>0，i位置节点的双亲序号：(i-1)/2；i=0，i为根节点编号，无双亲节点
//   2. 若2i + 1 < n，左孩子序号：2i + 1，2i + 1 >= n否则无左孩子
//   3. 若2i + 2 < n，右孩子序号：2i + 2，2i + 2 >= n否则无右孩子
//具有2n个完全二叉树中，叶子结点个数为 n



//144 二叉树的前序遍历
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//这里i为什么不能用全局变量，测试时用好几个案例来进行测试，全局变量值会累加

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


//104  二叉树的最大深度
//给定一个二叉树 root ，返回其最大深度。二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
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



