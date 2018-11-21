#include<stdio.h>






void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void Select(int num[], int len)
{
	if (num == NULL || len <= 0)
		return;
	int i = 0;
	//1.ȷ��ѭ������
	for (; i < len - 1; i++)
	{
		int minindex = i;
		int j = i + 1;
		//2.�ҵ�����������Сֵ
		for (; j < len; j++)
		{
			if (num[minindex] > num[j])
			{
				minindex = j;
			}
		}
		//����������һ��Ԫ�ؽ���
		if (minindex != i)
			Swap(&num[minindex], &num[i]);
	}
}




void SelectSort(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int max = left;//��¼���������Ԫ���±�
		int min = left;//��¼��������СԪ���±�
		int j = 0;
		for (j = left + 1; j <= right; j++)
		{
			//�����Ԫ���±�
			if (arr[j] < arr[min])
			{
				min = j;
			}
			//����СԪ���±�
			if (arr[j]>arr[max])
			{
				max = j;
			}
		}
		//��Сֵ����ǵ�һ����û�б�Ҫ����
		if (min != left)
		{
			int tmp = arr[left];
			arr[left] = arr[min];
			arr[min] = tmp;
		}
		//�������Ҫ��������Ԫ���±���left,ǰ���Ѿ�����СԪ�ؽ����ˣ���ʱ���Ԫ���±�Ӧ����min
		if (max == left)
		{
			max = min;
		}
		//���ֵ��������һ����û��Ҫ����
		if (max != right)
		{
			int tmp = arr[right];
			arr[right] = arr[max];
			arr[max] = tmp;
		}
		left++;
		right--;
	}
}
