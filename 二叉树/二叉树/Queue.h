#ifndef __QUEUE_H__
#define __QUEUE_H__


#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>

struct BinaryTreeNode;
typedef  struct BinaryTreeNode* QEDataType;


typedef  struct QueueNode
{
	struct QueueNode* _next;
	QEDataType _data;
}QueueNode;


typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);
void QueuePush(Queue* q, QEDataType x);
void QueuePop(Queue* q);
QEDataType QueueFront(Queue* q);
QEDataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);
#endif