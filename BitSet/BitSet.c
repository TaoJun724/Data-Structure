#include  "BitSet.h"

void BitSetInit(BitSet* p, size_t n)
{
	assert(p);
	p->N = n;
	//ȷ����Ҫ���ֽ���������+1������33/8Ӧ����5���ֽ�
	size_t size = (n >> 3) + 1;
	//��̬����
	p->a = (char*)malloc(size);
	//��ʼ��
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
	//�����ڵڼ���char��
	int index = x >> 3;
	//�ڼ�λ
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

//�ж������Ƿ����
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