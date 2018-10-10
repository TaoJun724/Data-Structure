#include  "BitSet.h"

void BitSetInit(BitSet* p, size_t n)
{
	assert(p);
	p->N = n;
	//确定需要的字节数，并且+1，比如33/8应该是5个字节
	size_t size = (n >> 3) + 1;
	//动态开辟
	p->a = (char*)malloc(size);
	//初始化
	memset(p->a, 0, size);
}

void BitSetDestory(BitSet* p)
{
	assert(p);
	free(p->a);
	p->a = NULL;
	p->N = 0;
}


void BitSetSet1(BitSet* p, size_t x)
{
	assert(p);
	//计算在第几个char中
	int index = x >> 3;
	//第几位
	int num = x % 8;
	p->a[index] |= (1 << num);
}

void BitSetSet0(BitSet* p, size_t x)
{
	assert(p);
	int index = x >> 3;
	int num = x % 8;
	p->a[index] &=  ~(1 << num);
}

//判断数字是否存在
int HaveNumber(BitSet* p, size_t x)
{
	assert(p);
	int index = x >> 3;
	int num = x % 8;
	int ret = p->a[index] & (1 << num);
	if (0 == ret)
		return 0;
	else
		return 1;
}