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
	//1.确定循环躺数
	for (; i < len - 1; i++)
	{
		int minindex = i;
		int j = i + 1;
		//2.找到无序区的最小值
		for (; j < len; j++)
		{
			if (num[minindex] > num[j])
			{
				minindex = j;
			}
		}
		//与无序区第一个元素交换
		if (minindex != i)
			Swap(&num[minindex], &num[i]);
	}
}


void Select_OP(int arr[], int len)
{
	int i = 0;
	int k = 0;//保存无序区第一个元素下标，方便比较
	//一趟确定一个有序区元素，最后一次不用确定，总共len-1次
	for (i = 0; i < len - 1; i++)
	{
		k = i;
		int j = 0;
		//确定无序区最小元素下标
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		//如果无序区第一个元素为最小，则没有必要交换
		if (i != k)
		{
			int tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}



