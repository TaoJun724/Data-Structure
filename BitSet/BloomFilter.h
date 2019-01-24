#ifndef  __BLOOMFITER_H__
#define  __BLOOMFILTER_H__





#include"BitSet.h"



typedef struct BlomFilter
{
	BitSet b;
}BloomFilter;


void BloomFilterInit(BloomFilter* p,size_t n);
void  BloomFilterDestory(BloomFilter* p);
void  BloomFilterSet1(BloomFilter* p, char* x);
int  BloomFilterHaveNumber(BloomFilter* p, char* x);

#endif


