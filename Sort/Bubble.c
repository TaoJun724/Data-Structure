#include<stdio.h>
void BubbleSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//确定循环躺数
	for (int i = 0; i < len - 1; i++)
	{
		//确定比较次数
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (num[j]>num[j + 1])
				Swap(&num[j], &num[j + 1]);
		}
	}
}

