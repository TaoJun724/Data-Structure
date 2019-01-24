#ifndef  __HEAP_H__
#define  __HEAP_H__

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* p, HPDataType* a, int n);
void HeapDestory(Heap* p);
void HeapPop(Heap* p);
int HeapSize(Heap* p);
int HeapEmpty(Heap* p);
void HeapPrint(Heap* p);
void HeapPush(Heap* p, HPDataType x);
HPDataType  HeapTop(Heap* p);
void HeapSort(HPDataType* a, int n);
void test();



#endif