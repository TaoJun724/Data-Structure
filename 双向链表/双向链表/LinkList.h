#ifndef __LINKLIST_H__
#define __LINKLIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	DataType data;
}ListNode;

typedef struct List
{
	struct ListNode* head;
}List;

void ListInit(List* lt);
void ListPushFront(List* lt, DataType x);
void ListPopBack(List* lt);
void ListPushBack(List* lt, DataType x);
void ListPrint(List* lt);
ListNode* BuyListNode(DataType x);
void ListPopFront(List* lt);
void ListInsert(ListNode* pos, DataType x);
void ListErase(ListNode* pos);
void ListDestory(List* lt);
ListNode* ListFind(List* lt, DataType x);
int ListSize(List* lt);




#endif