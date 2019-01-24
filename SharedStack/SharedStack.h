#ifndef __SHAREDSTACK_H__
#define __SHAREDSTACK_H__



#include<string.h>
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>


typedef int DataType;
#define MAX 10

typedef struct SharedStack
{
	DataType a[MAX];
	int top1;
	int top2;
}SharedStack;

void SharedStackInit(SharedStack* s);//
void SharedStackPush(SharedStack* s, int which, DataType x);//
void SharedStackPop(SharedStack* s, int which);//
size_t SharedStackSize(SharedStack* s, int which);//
int SharedStackEmpty(SharedStack* s, int which);
void SharedStackDestory(SharedStack* s, int which);
DataType SharedStackTop(SharedStack* s, int which);//
void text();//

#endif