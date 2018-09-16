#ifndef  __SEQLIST_H__
#define  __SEQLIST_H__



#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
typedef int DataType;

typedef struct Seqlist
{
	DataType data[MAX];//数据
	DataType sz;//数据个数
}Seqlist,*pSeqlist;


void InitSeqlist(pSeqlist pSeq);//pSeqlist=Seqlist *
void Pushback(pSeqlist pSeq, DataType d);
void PrintSeqlist(pSeqlist pseq);
void PushFront(pSeqlist pSeq, DataType d);
void Popfront(pSeqlist pSeq);
void Popback(pSeqlist pSeq);
int Find(pSeqlist pSeq, DataType   d);
void Insert(pSeqlist pSeq,int pos, DataType d);
void Del(pSeqlist pSeq, int pos);
void Remove(pSeqlist pSeq, DataType d);
void Removeall(pSeqlist pSeq, DataType d);
int Size(pSeqlist pSeq);
int Empty(pSeqlist pSeq);
void Bubblesort(pSeqlist pSeq);
void Swap(DataType* p1, DataType* p2);
void Selectsort1(pSeqlist pSeq);
void Selectsort2(pSeqlist pSeq);
int Binarysearch(pSeqlist pSeq, DataType d);
int Binarysearch2(pSeqlist pSeq,int left,int right, DataType d);
#endif