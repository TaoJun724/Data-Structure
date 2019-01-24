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




void SelectSort(int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		int max = left;//记录无序区最大元素下标
		int min = left;//记录无序区最小元素下标
		int j = 0;
		for (j = left + 1; j <= right; j++)
		{
			//找最大元素下标
			if (arr[j] < arr[min])
			{
				min = j;
			}
			//找最小元素下标
			if (arr[j]>arr[max])
			{
				max = j;
			}
		}
		//最小值如果是第一个则没有必要交换
		if (min != left)
		{
			int tmp = arr[left];
			arr[left] = arr[min];
			arr[min] = tmp;
		}
		//这里很重要，如果最大元素下标是left,前面已经和最小元素交换了，此时最大元素下标应该是min
		if (max == left)
		{
			max = min;
		}
		//最大值如果是最后一个则没必要交换
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
