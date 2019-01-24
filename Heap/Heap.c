#include "Heap.h"

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType  tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)


	{
		//选左右孩子中大的一个及右孩子是否存在
		if (child + 1 < n
			&&a[child + 1] > a[child])
		{
			++child;
		}
		//
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDataType* a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child]>a[parent])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(HPDataType* a, int n)
{
	//建堆
	int  i, end;
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		//调栈选次大的
		AdjustDown(a, end, 0);
		--end;
	}
	int b = 0;
	for (b = 0; b < n; b++)
	{
		printf("%d ", a[b]);
	}
	printf("\n");

}


void HeapInit(Heap* p, HPDataType* a, int n)
{
	assert(p&&a);
	int i;
	p->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	p->size = n;
	p->capacity = n;
	for (int i = 0; i < n; ++i)
	{
		p->a[i] = a[i];
	}
	//建大堆
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(p->a, p->size, i);
	}
}


HPDataType  HeapTop(Heap* p)
{
	assert(p);
	return p->a[0];
}


void HeapPush(Heap* p, HPDataType x)
{
	assert(p);
	if (p->size == p->capacity)
	{
		p->capacity *= 2;
		p->a = (HPDataType*)realloc(p->a, sizeof(HPDataType)*p->capacity);
	}
	p->a[p->size] = x;
	p->size++;
	AdjustUp(p->a, p->size, p->size - 1);
}
void HeapPop(Heap* p)
{
	assert(p);
	Swap(&p->a[0], &p->a[p->size - 1]);
	p->size--;
	AdjustDown(p->a, p->size, 0);
}
int HeapEmpty(Heap* p)
{
	if (p == NULL)
		return 0;
	return 1;
}
void HeapPrint(Heap* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->a[i]);
	}
	printf("\n");
}
int HeapSize(Heap* p)
{
	return p->size;
}
void HeapDestory(Heap* p)
{
	free(p->a);
	p->a = NULL;
	p->size = p->capacity = 0;
}