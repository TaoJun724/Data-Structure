#include<stdio.h>


void  AdjustDown(int* num, int n, int parent)
{
	if (num == NULL || n <= 0)
		return;
	int child = 2 * parent + 1;
	while (child < n)
	{
		//������childָ�����Һ����нϴ����һ��
		if ((child + 1 < n) && (num[child] < num[child + 1]))
			child++;
		//�ȽϽ���������
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
//������
void HeapSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//1.����(����->���,����->С��)
	for (int i = (2 * len - 2) / 2; i >= 0; i--)
	{
		AdjustDown(num, len, i);
	}
	//2.�������һ��Ԫ�غ͵�һ��Ԫ��
	int end = len - 1;
	while (end > 0)
	{
		Swap(&num[0], &num[end]);
		AdjustDown(num, end, 0);
		--end;
	}
}

