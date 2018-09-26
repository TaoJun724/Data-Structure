#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef  char  BTDataType;

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>




//typedef struct TreeNode 
//{ 
// BTDataType _data; 
// struct TreeNode* _firstChild; 
// struct TreeNode* _nextBrother; 
//}TreeNode; 



typedef  struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;



BTNode* BuyBTNode(BTDataType x);
//a是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
//遍历   递归非递归
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeKlevelSize(BTNode* root, int k);
void BinaryTreeDestory(BTNode** root);
BTNode*  BinaryTreeFind(BTNode* root, BTDataType x);
int BTreeHeight(BTNode* root);
void BinaryTreeLevelOrder(BTNode* root);
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void Test();










#endif