#include<stdio.h>


//
//void   InsertSort(int arr[], int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int key = arr[i];
//		int end = i - 1;
//
//		while (end >= 0 && key < arr[end])
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//		arr[end + 1] = key;
//	}
//}
//


void   InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = arr[i];
		int end = i - 1;
		int left = 0;
		//二分查找先找到位置
		int right = i - 1;
		while (left <= right)
		{
			int mid = left + ((right - left)>>1);
			if (arr[mid]>key)
				right = mid - 1;
			else
				left = mid + 1;
		}
		while (end >=left)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}