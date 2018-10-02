#include  "StackByTQ.h"

void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);
}

int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueEmpty(&stq->q1) | QueueEmpty(&stq->q2);
}
int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
	{
		QueuePush(&stq->q1, x);
	}
	else
	{
		QueuePush(&stq->q2, x);
	}
}


DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
	{
		return stq->q1._back->_data;
	}
	else
	{
		return stq->q2._back->_data;
	}
}


void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue*empty = &stq->q1, *nonempty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		nonempty = &stq->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	QueuePop(nonempty);
}