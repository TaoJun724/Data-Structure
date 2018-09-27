#define  _CRT_SECURE_NO_WARNINGS 0

#include "BinarySTree.h"

BSTreeNode* BuyBSTreeNode(BSDataType x)
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_key = x;
	return node;
}

int BSTreeInsert(BSTreeNode** ppTree, BSDataType x)
{
	assert(ppTree);
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}
	BSTreeNode* cur = *ppTree;
	BSTreeNode* parent = NULL;
	while (cur)
	{
		if (cur->_key > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_key < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return 0;
		}
	}
	cur = BuyBSTreeNode(x);
	if (parent->_key < x)
	{
		parent->_right = BuyBSTreeNode(x);
	}
	else
	{
		parent->_left = BuyBSTreeNode(x);
	}

	return 1;
}

int BSTreeRemove(BSTreeNode** ppTree, BSDataType x)
{
	BSTreeNode* cur = *ppTree;
	BSTreeNode* parent = NULL;
	while (cur)
	{
		if (cur->_key < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (cur->_key > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			// 开始删除
			//只有右孩子
			if (cur->_left == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->_right;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
			}
			//只有左海子或者无孩子
			else if (cur->_right == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->_left;
				}
				else
				{
					if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
			}
			//无孩子 
			else
			{
				BSTreeNode* replace = cur->_right;
				while (replace->_left)
				{
					replace = replace->_left;
				}

				cur->_key = replace->_key;

				return BSTreeRemove(&cur->_right, replace->_key);
			}

			free(cur);
			return 1;
		}
	}

	return 0;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSDataType x)
{
	BSTreeNode* cur = *ppTree;
	while (cur)
	{
		if (cur->_key < x)
		{
			cur = cur->_right;
		}
		else if (cur->_key > x)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}

	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	if (*ppTree == NULL)
	{
		return;
	}

	BSTreeInOrder(&(*ppTree)->_left);
	printf("%d ", (*ppTree)->_key);
	BSTreeInOrder(&(*ppTree)->_right);
}

void TestBSTree()
{
	int i = 0;
	BSTreeNode* pTree = NULL;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (; i < sizeof(a) / sizeof(int); ++i)
	{
		BSTreeInsert(&pTree, a[i]);
	}
	BSTreeInOrder(&pTree);
	printf("\n");

	BSTreeRemove(&pTree, 2);
	BSTreeRemove(&pTree, 1);
	BSTreeRemove(&pTree, 8);
	BSTreeRemove(&pTree, 5);

	BSTreeInOrder(&pTree);
	printf("\n");

	//BSTreeRemove(&pTree, 6);
	//BSTreeRemove(&pTree, 5);


	/*BSTreeRemove(&ppTree, 0);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 1);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 2);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 3);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 4);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 5);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 6);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 7);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 8);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 9);
	BSTreeInOrder(&ppTree);
	printf("\n");

	BSTreeRemove(&ppTree, 10);
	BSTreeInOrder(&ppTree);
	printf("\n");*/

	//BSTreeInOrder(&ppTree);
	//printf("\n");
}

int BSTreeInsertR(BSTreeNode** ppTree, BSDataType x)
{
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}

	if ((*ppTree)->_key > x)
		return BSTreeInsertR(&(*ppTree)->_left, x);
	else if ((*ppTree)->_key < x)
		return BSTreeInsertR(&(*ppTree)->_right, x);
	else
		return 0;
}

int BSTreeRemoveR(BSTreeNode** ppTree, BSDataType x)
{
	if (*ppTree == NULL)
	{
		return -1;
	}

	if ((*ppTree)->_key < x)
	{
		return BSTreeRemoveR(&((*ppTree)->_right), x);
	}
	else if ((*ppTree)->_key > x)
	{
		return BSTreeRemoveR(&((*ppTree)->_left), x);
	}
	else
	{
		BSTreeNode* del = *ppTree;

		if ((*ppTree)->_left == NULL)
		{
			*ppTree = (*ppTree)->_right;

			free(del);
		}
		else if ((*ppTree)->_right == NULL)
		{
			*ppTree = (*ppTree)->_left;

			free(del);
		}
		else
		{
			BSTreeNode* replace = (*ppTree)->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}

			(*ppTree)->_key = replace->_key;

			return BSTreeRemoveR(&(*ppTree)->_right, replace->_key);
		}
	}

	return 1;
}

BSTreeNode* BSTreeFindR(BSTreeNode** ppTree, BSDataType x)
{
	if (*ppTree == NULL)
	{
		return NULL;
	}

	if ((*ppTree)->_key > x)
	{
		return BSTreeFindR(&((*ppTree)->_left), x);
	}
	else if ((*ppTree)->_key < x)
	{
		return BSTreeFindR(&((*ppTree)->_right), x);
	}
	else
	{
		return *ppTree;
	}
}

void TestBSTreeR()
{
	int i = 0;
	BSTreeNode* pTree = NULL;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (; i < sizeof(a) / sizeof(int); ++i)
	{
		BSTreeInsertR(&pTree, a[i]);
	}

	/*BSTreeRemoveR(&pTree, 0);
	BSTreeRemoveR(&pTree, 1);
	BSTreeRemoveR(&pTree, 2);
	BSTreeRemoveR(&pTree, 3);
	BSTreeRemoveR(&pTree, 4);
	BSTreeRemoveR(&pTree, 5);
	BSTreeRemoveR(&pTree, 6);
	BSTreeRemoveR(&pTree, 7);
	BSTreeRemoveR(&pTree, 8);
	BSTreeRemoveR(&pTree, 9);
	BSTreeRemoveR(&pTree, 10);*/

	BSTreeInOrder(&pTree);
	printf("\n");
}