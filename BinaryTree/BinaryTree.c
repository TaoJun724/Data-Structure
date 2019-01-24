#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->data = x;
	return node;
}


BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = BuyBTNode(a[*pi]);
		++(*pi);
		root->left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, n, pi);
		return root;
	}
	else
	{
		return  NULL;
	}
}

//int BinaryTreeSize(BTNode* root)
//{
//	int size = 0;
//	if (root == NULL)
//	{
//		return  0;
//	}
//	++size;
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//}


int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}


void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c", root->data);
	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c", root->data);
}

BTNode*  BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL || root->data == x)
	{
		return  root;
	}
	ret = BinaryTreeFind(root->left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}


int BTreeHeight(BTNode* root)
{
	int leftHeight;
	int rightHeight;
	if (root == NULL)
	{
		return 0;
	}
	leftHeight = BTreeHeight(root->left);
	rightHeight = BTreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void BinaryTreeDestory(BTNode** pptree)
{
	BTNode* root = *pptree;
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&root->left);
	BinaryTreeDestory(&root->right);
	free(root);
	pptree = NULL;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeKlevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeKlevelSize(root->left, k - 1) + BinaryTreeKlevelSize(root->right, k - 1);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	BTNode *p = NULL;
	if (root == NULL)
		return;
	QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		p = QueueFront(&q);
		QueuePop(&q);
		printf("%c", p->data);
		if (p->left)
		{
			QueuePush(&q, p->left);
		}
		if (p->right)
		{
			QueuePush(&q, p->right);
		}
	}
	QueueDestory(&q);
}


int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;
		}
	}
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		if (front)
		{
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	QueueDestory(&q);
	return 0;
}
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		//访问左路节点，左路节点进栈
		while (cur)
		{
			printf("%c", cur->data);
			StackPush(&s, cur);
			cur = cur->left;
		}
		//栈里面出来节点，表示左树已经访问过
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//子问题访问有树
		cur = top->right;
	}
}
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		//左树已经访问过了
		//还剩根及右树
		BTNode* top = StackTop(&s);
		StackPop(&s);
		printf("%c", top->data);
		cur = top->right;
	}
}
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* prev = NULL;
	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		BTNode* top = StackTop(&s);
		if (top->right == NULL || top->right == prev)
		{
			printf("%c", top->data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->right;
		}
	}
}
