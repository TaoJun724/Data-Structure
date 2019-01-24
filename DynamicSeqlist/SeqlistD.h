#ifndef __SEQLISTD_H__
#define __SEQLISTD_H__



#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef  int DataType;
#define SZ 3
typedef struct Seqlist
{
	DataType*  data;
	int sz;
	int  capacitance;
}Seqlist,*pSeqlist;

int Empty(pSeqlist pSeq);
void Popback(pSeqlist pSeq);
void DestorySeqlist(pSeqlist  pSeq);
void CheckCapciaty(pSeqlist pSeq);
void InitSeqlist(pSeqlist pSeq);
void PrintSeqlist(pSeqlist pSeq);
void Pushback(pSeqlist pSeq, DataType d);
#endif