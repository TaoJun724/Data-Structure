#ifndef   __MINSTACK_H__
#define   __MINSTACK_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType;

typedef struct  Stack1
{
	DataType* a;
	size_t top1;
	size_t  capacity1;
}Stack1;

typedef struct  Stack2
{
	DataType* a;
	size_t top2;
	size_t  capacity2;
}Stack2;

typedef struct Stack
{
	Stack1 s1;
	Stack2 s2;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestory(Stack* s);
int StackMindata(Stack* s);
void text();


#endif 