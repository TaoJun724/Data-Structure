#include "Heap.h"

void test()
{
	Heap p;
	int a[] = { 53, 17, 78, 9, 45 };
	HeapInit(&p, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&p);
	HeapSort(a, sizeof(a) / sizeof(a[0]));
}



int main()
{
	test();
	system("pause");
	return 0;
}