#include<stdio.h>


void  AdjustDown(int* num, int n, int parent)
{
	if (num == NULL || n <= 0)
		return;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//处理让child指向左右孩子中较大的哪一个
		if ((child + 1 < n) && (num[child] < num[child + 1]))
			child++;
		//比较交换并调整
		if (num[child]>num[parent])
		{
			Swap(&num[child], &num[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//堆排序
void HeapSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//1.建堆(升序->大堆,降序->小堆)
	for (int i = (2 * len - 2) / 2; i >= 0; i--)
	{
		AdjustDown(num, len, i);
	}
	//2.交换最后一个元素和第一个元素
	int end = len - 1;
	while (end > 0)
	{
		Swap(&num[0], &num[end]);
		AdjustDown(num, end, 0);
		--end;
	}
}

