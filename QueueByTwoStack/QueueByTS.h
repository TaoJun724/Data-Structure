#ifndef __QUEUEBYTS_H__
#define __QUEUEBYTS_H__

#include "Queue.h"
#include "Stack.h"

typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);
void QueueByTwoStackPop(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);

int QueueByTwoStackSize(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);

void TestQueueByTwoStack();

#endif