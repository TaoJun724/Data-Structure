#include<stdio.h>


void ShellSort(int arr[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i += gap)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end]>key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}