#include"BloomFilter.h"



size_t HashFunc1(char* p)
{
	assert(p);
	size_t hash = 0;
	while (*p)
	{
		hash = hash * 131 + (size_t)*p;
		p++;
	}
	return hash;
}


size_t HashFunc2(char* p)
{
	assert(p);
	size_t hash = 0;
	while (*p)
	{
		hash = hash * 31 + (size_t)*p;
		p++;
	}
	return hash;
}



size_t HashFunc3(char* p)
{
	assert(p);
	size_t hash = 0;
	while (*p)
	{
		hash = hash * 1313  + (size_t)*p;
		p++;
	}
	return hash;
}
void BloomFilterInit(BloomFilter* p ,size_t n)
{
	assert(p);
	BitSetInit(&(p->b),n );
}
void  BloomFilterDestory(BloomFilter* p)
{
	assert(p);
	BitSetDestory(&(p->b));
}
void  BloomFilterSet1(BloomFilter* p, char* x)
{
	assert(p);
	size_t index1 = HashFunc1(x);
	size_t index2 = HashFunc2(x);
	size_t index3 = HashFunc3(x);



	BitSetSet1(&(p->b), index1);
	BitSetSet1(&(p->b), index2);
	BitSetSet1(&(p->b), index3);


}
int  BloomFilterHaveNumber(BloomFilter* p, char* x)
{
	assert(p);
	size_t index1 = HashFunc1(x);
	if (HaveNumber(&(p->b), index1))
	{
		size_t index2 = HashFunc2(x);
		if (HaveNumber(&(p->b), index2))
		{
			size_t index3 = HashFunc3(x);
			if (HaveNumber(&(p->b), index3))
			{
				return 1;
			}
		}
	}
	return 0;
}