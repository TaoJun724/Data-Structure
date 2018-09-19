#ifndef __QUEUE_H__
#define __QUEUE_H__


#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>


typedef int DataType;


typedef  struct QueueNode
{
	struct QueueNode* _next;
	DataType _data;
}QueueNode;


typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _back;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);
void QueuePush(Queue* q,DataType x);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);
#endif