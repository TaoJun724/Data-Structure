#define _CRT_SECURE_NO_WARNINGS 1

#include"Seqlist.h"

void InitSeqlist(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}
void Pushback(pSeqlist pSeq, DataType d)
{
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已满");
		return ;
	}
    	pSeq->data[pSeq->sz] = d;
		pSeq->sz++;
}
void PrintSeqlist(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		printf("%d  ", pSeq->data[i]);
	}
	printf("\n");
}

void Popback(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空无法删除");
	}
	pSeq->sz--;
}
void PushFront(pSeqlist pSeq, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已经满了");
			return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i+1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->sz++;

}void Popfront(pSeqlist pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空无法删除");
		return;
	}
	for (i = 0; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq -> sz--;
}
int Find(pSeqlist pSeq, DataType   d)
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}


void Insert(pSeqlist pSeq, int pos, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->sz);
	if (pSeq->sz == MAX)
	{
		printf("顺序表已经满了无法插入");
	}
	for (i = pSeq->sz - 1; i >= pos; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}
void Del(pSeqlist pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->sz);
	if (pSeq -> sz == 0)
	{
		printf("顺序表是空的无法删除");
	}
	for (i = pos; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}
void Remove(pSeqlist pSeq, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("顺序表为空");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		if ( pSeq->data[i] == d )
		{
			break;
		}
	} 
	if (i == pSeq->sz)
	{
		printf("删除的元素没有\n");
		return;
	}
	for (; i < pSeq->sz - 1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}



void Removeall(pSeqlist pSeq, DataType d)
{
#if 0
	assert(pSeq!=NULL);
	while ((pos = Find(pSeq, d)) != -1)
	{
		Del(pSeq, pos);
	}
#endif


	/*int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
	printf("该顺序表为空无法删除 ");
	return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
	if (pSeq->data[i] == d)
	{
	for (j = i; j < pSeq->sz - 1; j++)
	{
	pSeq->data[j] = pSeq->data[j + 1];
	}
	pSeq->sz--;
	--i;
	}
	}*/

#if 0
	int i = 0;
	int count = 0;
	DataType* tmp = (DataType*)malloc(sizeof(DataType) * pSeq->sz);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d);
		{
			tmp[count++] = pSeq->data[i];
		}
	}
	memcpy(pSeq->data, tmp, count*sizeof(DataType));
	pSeq->sz = count;
	free(tmp);
	tmp = NULL;
}
#endif 
int i = 0;
int count = 0;
for (i = 0; i < pSeq->sz; i++)
{
	if (pSeq->data[i] != d)
	{
		pSeq->data[count++] = pSeq->data[i];
	}
}
pSeq->sz = count;
}

int Size(pSeqlist  pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}
int Empty(pSeqlist pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz == 0;
}
void Bubblesort(pSeqlist pSeq)
{
	int  i = 0;
	int  j = 0;
	int flag = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz-1; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->sz-1-i; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}
void Swap(DataType* p1, DataType* p2)
{
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;	
}
void Selectsort1(pSeqlist pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz - 1; i++)
	{
		int max = 0;
		for (j = 1; j < pSeq->sz - i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		if (max != pSeq->sz - 1 - i)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->sz - 1 - i);
		}
	}
}

void Selectsort2(pSeqlist pSeq)
{
	int start = 0;
	int end = pSeq->sz - 1;
	assert(pSeq != NULL);
	while(start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i < end; i++)
		{
			if (pSeq->data[i]>pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (min != start)
		{
			Swap(pSeq->data + min, pSeq->data + start);
		}
		if (max == start)
		{
			max = min;
		}
		if (max != end)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		start++;
		end--;
     }
}
int Binarysearch(pSeqlist pSeq, DataType d)
{
#if 0
	int left = 0;
	int right = pSeq->sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] < d)
		{
			left= mid +1;
		}
		else  if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
#endif


}


int Binarysearch2(pSeqlist pSeq, int left, int right, DataType d)
{
	int mid = 0;
	if (left > right)
		return -1;
	mid = left + ((right - left) >> 1);
	if (pSeq->data[mid] > d)
	{
		Binarysearch2(pSeq, left, mid - 1, d);
	}
	else if (pSeq->data[mid] < d)
	{
		Binarysearch2(pSeq, mid + 1, right, d);
	}
	else
		return mid;
}