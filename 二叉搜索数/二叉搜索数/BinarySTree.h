#ifndef __BINARYSTREE_H__
#define __BINARYSTREE_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>



typedef int BSDataType;


typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSDataType _key;
}BSTreeNode;

int BSTreeInsert(BSTreeNode** ppTree, BSDataType x);
int BSTreeRemove(BSTreeNode** ppTree, BSDataType x);
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSDataType x);
void BSTreeInOrder(BSTreeNode** ppTree);
void TestBSTreeR();
void TestBSTree();

#endif