#include<stdio.h>
#include<assert.h>



void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//三数取中优化法(找三个值中间大的那个)
int GetMidKey(int* num, int begin, int end)
{
	assert(num);
	int mid = begin + (end - begin) / 2;
	if (num[begin] < num[mid])
	{
		if (num[mid] < num[end])
			return mid;
		else
		{
			if (num[begin]>num[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		if (num[begin] < num[end])
			return begin;
		else
		{
			if (num[mid]>num[end])
				return mid;
			else
				return end;
		}
	}
}


int PartSort1(int* num, int begin, int end)
{
	//三数取中优化
	int index = GetMidKey(num, begin, end);
	//和要选的基准交换
	Swop(&num[index], &num[end]);
	int key = num[end];
	int last = end;
	while (begin < end)
	{
		//1.左边找到大于基准值的元素
		while ((begin < end) && (num[begin] <= key))
			begin++;
		//2.右边找到小于基准值的元素
		while ((begin < end) && (num[end] >= key))
			end--;
		//3.交换两个值
		Swap(&num[begin], &num[end]);
	}
	//两个下标走到一块的时候，把基准值交换过来
	Swap(&num[begin], &num[last]);
	//返回基准值的位置
	return begin;
}


//挖坑
int PartSort2(int* num, int begin, int end)
{
	int key = num[end];//把基准值拿出来(挖一个坑)
	while (begin < end)
	{
		//1.左边找到大于基准值的元素，并放入坑里
		while ((begin < end) && (num[begin] <= key))
			begin++;
		num[end] = num[begin];
		//2.右边找到小于基准值的元素，并放入坑里
		while ((begin < end) && (num[end] >= key))
			end--;
		num[begin] = num[end];
	}
	//3.把拿出来基准值放入坑里
	num[begin] = key;
	//返回基准值的位置
	return begin;
}

//前后指针法
int PartSort3(int* num, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = num[end];
	while (cur < end)
	{
		//++prev=cur说明这个元素时第一个元素或者这是一段连续的小于基准的序列
		if ((num[cur] < key) && (++prev != cur))
			Swap(&num[cur], &num[prev]);
		cur++;
	}
	//把基准元素放在所有小于基准元素的紧邻后边，可以达到基准的左边小于基准，右边大于基准
	Swap(&num[++prev], &num[end]);
	return prev;
}


void QuickSort(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//递归出口
	if (left >= right)
		return;
	//按照基准值将待排序区间划分为两个子区间
	int div = PartSort1(num, left, right);
	//子问题排序左子区间
	QuickSort(num, left, div - 1);
	//子问题排序右子区间
	QuickSort(num, div + 1, right);
}



//void QuickSort1(int* num, int left, int right)
//{
//	if (num == NULL)
//		return;
//	//递归出口
//	if (left >= right)
//		return;
//	//小区间优化(替换掉后边几层的递归)
//	if (right - left + 1 < 10)
//		InsertSort(num, right - left + 1);
//	//按照基准值将待排序区间划分为两个子区间
//	int div = PartSort1(num, left, right);
//	//子问题排序左子区间
//	QuickSort1(num, left, div - 1);
//	//子问题排序右子区间
//	QuickSort1(num, div + 1, right);
//}







//
////快排非递归(按照递归树的前序路线走)
//void QuickSortNonR(int* num, int left, int right)
//{
//	if (num == NULL || right <= left)
//		return;
//	Stack st;
//	StackInit(&st);
//	//先将整个区间压栈
//	StackPush(&st, left);
//	StackPush(&st, right);
//	while (StackEmpty(&st) != 0)
//	{
//		//取栈顶并且出栈
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//		//先划分主区间，固定好一个基准
//		int div = PartSort1(num, begin, end);
//		//如果左子序列还有大于1个元素，继续压栈
//		if (begin < div - 1)
//		{
//			StackPush(&st, begin);
//			StackPush(&st, div - 1);
//		}
//		//如果右子序列还有大于1个元素，继续压栈
//		if (div + 1 < end)
//		{
//			StackPush(&st, div + 1);
//			StackPush(&st, end);
//		}
//	}
//	StackDestroy(&st);
//}
