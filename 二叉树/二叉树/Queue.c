#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_back = NULL;
}
void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur;
	QueueNode* tmp;
	cur = q->_front;
	while (cur)
	{
		tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	q->_front = q->_back = NULL;
}
QueueNode* BuyQueueNode(QEDataType x)
{
	QueueNode* cur;
	cur = (QueueNode*)malloc(sizeof(QueueNode));
	if (cur == NULL)
	{
		perror("use malloc");
	}
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueuePush(Queue* q, QEDataType x)
{
	assert(q);
	QueueNode* cur;
	if (q->_front == NULL)
	{
		cur = BuyQueueNode(x);
		q->_back = cur;
		q->_front = cur;
	}
	else
	{
		cur = BuyQueueNode(x);
		q->_back->_next = cur;
		q->_back = cur;
	}
}
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode*next = q->_front->_next;
	free(q->_front);
	q->_front = next;
}
QEDataType QueueFront(Queue* q)
{
	assert(q);
	if (q->_front != NULL)
		return q->_front->_data;
	else
		return 0;
}
QEDataType QueueBack(Queue* q)
{
	assert(q);
	if (q->_back != NULL)
		return q->_back->_data;
	else
		return 0;
}
size_t QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	if (q->_front == NULL)
		return 0;
	else
	{
		QueueNode* cur;
		cur = q->_front;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}
