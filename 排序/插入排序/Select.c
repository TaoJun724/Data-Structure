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


void Select_OP(int arr[], int len)
{
	int i = 0;
	int k = 0;//������������һ��Ԫ���±꣬����Ƚ�
	//һ��ȷ��һ��������Ԫ�أ����һ�β���ȷ�����ܹ�len-1��
	for (i = 0; i < len - 1; i++)
	{
		k = i;
		int j = 0;
		//ȷ����������СԪ���±�
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		//�����������һ��Ԫ��Ϊ��С����û�б�Ҫ����
		if (i != k)
		{
			int tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}



