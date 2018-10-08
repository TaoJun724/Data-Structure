#include<stdio.h>
#include<assert.h>



void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//����ȡ���Ż���(������ֵ�м����Ǹ�)
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
	//����ȡ���Ż�
	int index = GetMidKey(num, begin, end);
	//��Ҫѡ�Ļ�׼����
	Swop(&num[index], &num[end]);
	int key = num[end];
	int last = end;
	while (begin < end)
	{
		//1.����ҵ����ڻ�׼ֵ��Ԫ��
		while ((begin < end) && (num[begin] <= key))
			begin++;
		//2.�ұ��ҵ�С�ڻ�׼ֵ��Ԫ��
		while ((begin < end) && (num[end] >= key))
			end--;
		//3.��������ֵ
		Swap(&num[begin], &num[end]);
	}
	//�����±��ߵ�һ���ʱ�򣬰ѻ�׼ֵ��������
	Swap(&num[begin], &num[last]);
	//���ػ�׼ֵ��λ��
	return begin;
}


//�ڿ�
int PartSort2(int* num, int begin, int end)
{
	int key = num[end];//�ѻ�׼ֵ�ó���(��һ����)
	while (begin < end)
	{
		//1.����ҵ����ڻ�׼ֵ��Ԫ�أ����������
		while ((begin < end) && (num[begin] <= key))
			begin++;
		num[end] = num[begin];
		//2.�ұ��ҵ�С�ڻ�׼ֵ��Ԫ�أ����������
		while ((begin < end) && (num[end] >= key))
			end--;
		num[begin] = num[end];
	}
	//3.���ó�����׼ֵ�������
	num[begin] = key;
	//���ػ�׼ֵ��λ��
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int* num, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int key = num[end];
	while (cur < end)
	{
		//++prev=cur˵�����Ԫ��ʱ��һ��Ԫ�ػ�������һ��������С�ڻ�׼������
		if ((num[cur] < key) && (++prev != cur))
			Swap(&num[cur], &num[prev]);
		cur++;
	}
	//�ѻ�׼Ԫ�ط�������С�ڻ�׼Ԫ�صĽ��ں�ߣ����Դﵽ��׼�����С�ڻ�׼���ұߴ��ڻ�׼
	Swap(&num[++prev], &num[end]);
	return prev;
}


void QuickSort(int* num, int left, int right)
{
	if (num == NULL)
		return;
	//�ݹ����
	if (left >= right)
		return;
	//���ջ�׼ֵ�����������仮��Ϊ����������
	int div = PartSort1(num, left, right);
	//������������������
	QuickSort(num, left, div - 1);
	//������������������
	QuickSort(num, div + 1, right);
}



//void QuickSort1(int* num, int left, int right)
//{
//	if (num == NULL)
//		return;
//	//�ݹ����
//	if (left >= right)
//		return;
//	//С�����Ż�(�滻����߼���ĵݹ�)
//	if (right - left + 1 < 10)
//		InsertSort(num, right - left + 1);
//	//���ջ�׼ֵ�����������仮��Ϊ����������
//	int div = PartSort1(num, left, right);
//	//������������������
//	QuickSort1(num, left, div - 1);
//	//������������������
//	QuickSort1(num, div + 1, right);
//}







//
////���ŷǵݹ�(���յݹ�����ǰ��·����)
//void QuickSortNonR(int* num, int left, int right)
//{
//	if (num == NULL || right <= left)
//		return;
//	Stack st;
//	StackInit(&st);
//	//�Ƚ���������ѹջ
//	StackPush(&st, left);
//	StackPush(&st, right);
//	while (StackEmpty(&st) != 0)
//	{
//		//ȡջ�����ҳ�ջ
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//		//�Ȼ��������䣬�̶���һ����׼
//		int div = PartSort1(num, begin, end);
//		//����������л��д���1��Ԫ�أ�����ѹջ
//		if (begin < div - 1)
//		{
//			StackPush(&st, begin);
//			StackPush(&st, div - 1);
//		}
//		//����������л��д���1��Ԫ�أ�����ѹջ
//		if (div + 1 < end)
//		{
//			StackPush(&st, div + 1);
//			StackPush(&st, end);
//		}
//	}
//	StackDestroy(&st);
//}
