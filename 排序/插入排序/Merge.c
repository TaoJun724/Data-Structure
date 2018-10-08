#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>



//归并排序合并过程
void Merge(int* num, int start1, int end1, int start2, int end2, int* tmp)
{
	assert(num&&tmp);
	int begin = start1;
	int index = start1;//从start1的地方合并
	//和两条有序单链表的合并的过程类似
	while ((start1 <= end1) && (start2 <= end2))
	{
		if (num[start1] < num[start2])
		{
			tmp[index++] = num[start1++];
		}
		else
		{
			tmp[index++] = num[start2++];
		}
	}
	//把剩余的合并到tmp上
	while (start1 <= end1)
		tmp[index++] = num[start1++];
	while (start2 <= end2)
		tmp[index++] = num[start2++];
	//tmp是个临时空间，最后到把合并的内容拷贝到num上
	memcpy(num + begin, tmp + begin, sizeof(int)*(end2 - begin + 1));
}



//归并排序分开过程(递归树按照前序路线展开)
void _MergeSort(int* num, int begin, int end, int* tmp)
{
	assert(num&&tmp);
	int mid = begin + (end - begin) / 2;
	//只有一个元素，说明这个序列已经有序
	if (begin == end)
		return;
	//子问题划分左子序列
	_MergeSort(num, begin, mid, tmp);
	//子问题划分右子序列
	_MergeSort(num, mid + 1, end, tmp);
	//合并两个有序数组
	Merge(num, begin, mid, mid + 1, end, tmp);
}


//

void MergeSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//开辟临时空间，用来存放每次合并后的子序列
	int* tmp = (int*)malloc(sizeof(int)*len);
	_MergeSort(num, 0, len - 1, tmp);
	//释放空间
	free(tmp);
	tmp = NULL;
}
