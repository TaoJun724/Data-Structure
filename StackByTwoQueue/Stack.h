#ifndef  __STACK_H__
#define  __STACK_H__



#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

typedef int  DataType;

typedef  struct Stack
{
	DataType* _a;
	size_t  _top;
	size_t  _capacity;
}Stack;



void StackInit(Stack* s);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestory(Stack* s);
void text();




#endif