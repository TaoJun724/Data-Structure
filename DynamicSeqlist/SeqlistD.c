#include  "SeqlistD.h"  


void InitSeqlist(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	pSeq->data = (DataType *)malloc(SZ*sizeof(DataType));
	if (pSeq->data == NULL)
	{
		perror("use malloc");
		exit(EXIT_FAILURE);
	}
	pSeq->sz = 0;
	pSeq->capacitance = SZ;
}
void PrintSeqlist(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
	printf("\n");
}
void Pushback(pSeqlist pSeq, DataType d)
{
	assert(pSeq != NULL);
	CheckCapciaty(pSeq);
	pSeq->data[pSeq -> sz] = d;
	pSeq->sz++;
}
void CheckCapciaty(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == pSeq->capacitance)
	{
		DataType * tmp = (DataType *)realloc(pSeq->data, (pSeq->capacitance + 2)*sizeof(DataType));
		if (tmp != NULL)
		{
			pSeq->data = tmp;
		}
		pSeq->capacitance += 2;
		printf("增容成功\n");
	}
	
}

void DestorySeqlist(pSeqlist  pSeq)
{
	assert(pSeq != NULL);
	free(pSeq->data);
	pSeq->data = NULL;
	pSeq->sz = 0;
	pSeq->capacitance = 0;
}
void Popback(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	/*if (pSeq->sz == 0)
	{
		printf("顺序表为空，无法删除");
		return;
	}*/
	if (Empty(pSeq))
	{
		printf("顺序表为空，无法删除");
	}
	pSeq->sz--;
}

int Empty(pSeqlist pSeq)
{
	return  pSeq->sz == 0;
}