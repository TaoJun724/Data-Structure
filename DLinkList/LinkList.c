#include"LinkList.h"




ListNode* BuyListNode(DataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));//开辟新节点
	if (NULL == newNode)
	{
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}




void ListInit(List* lt)
{
	assert(lt);
	ListNode* head = BuyListNode(0);
	lt->head = head;
	lt->head->next = lt->head;
	lt->head->prev = lt->head;
}

void ListDestory(List* lt)
{
	assert(lt);
	ListNode*  cur = lt->head->next;
	ListNode* del = NULL;
	while (cur->next != lt->head)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	free(cur);
	cur = NULL;
}

void ListPushBack(List* lt, DataType x)
{
	assert(lt);
	ListNode* cur = lt->head->next;
	ListNode* NewNode = BuyListNode(x);
	while (cur->next != lt->head->next)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
	NewNode->next = lt->head;
	NewNode->prev = cur;
	lt->head->prev = NewNode;
}
void ListPopBack(List* lt)
{
	assert(lt);
	ListNode* del = lt->head->next;
	ListNode* prev = lt->head;
	while (del->next != lt->head)
	{
		prev = del;
		del = del->next;
	}
	prev->next = lt->head;
	lt->head = prev;
}
void ListPushFront(List* lt, DataType x)
{
	assert(lt);
	ListNode*   NewNode = BuyListNode(x);
	NewNode->next = lt->head->next;
	NewNode->prev = lt->head;
	lt->head->next->prev = NewNode;
	lt->head->next = NewNode;
}
void ListPopFront(List* lt)
{
	assert(lt);
	if (lt->head->next == lt->head)
	{
		return;
	}
	ListNode*  del = lt->head->next;
	lt->head->next = del->next;
	del->next->prev = lt->head;
	free(del);
}


void ListPrint(List* lt)
{
	ListNode* cur = lt->head->next;
	while (cur != lt->head)
	{
		printf("%d->\n", cur->data);
		cur = cur->next;
	}
}



void ListInsert(ListNode* pos, DataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	newnode->data = x;
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
void ListErase(ListNode* pos)
{
	if (pos->next == pos)
	{
		return;
	}
	ListNode* del = pos->next;
	pos->data = pos->next->data;
	pos->next = del->next;
	del->next->prev = pos;
	free(del);
}


int ListSize(List* lt)
{
	ListNode* cur = lt->head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
ListNode* ListFind(List* lt, DataType x)
{
	assert(lt);
	ListNode* cur = lt->head->next;
	while (cur != lt->head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else  cur = cur->next;
	}
	return NULL;
}