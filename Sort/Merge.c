#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>



//�鲢����ϲ�����
void Merge(int* num, int start1, int end1, int start2, int end2, int* tmp)
{
	assert(num&&tmp);
	int begin = start1;
	int index = start1;//��start1�ĵط��ϲ�
	//��������������ĺϲ��Ĺ�������
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
	//��ʣ��ĺϲ���tmp��
	while (start1 <= end1)
		tmp[index++] = num[start1++];
	while (start2 <= end2)
		tmp[index++] = num[start2++];
	//tmp�Ǹ���ʱ�ռ䣬��󵽰Ѻϲ������ݿ�����num��
	memcpy(num + begin, tmp + begin, sizeof(int)*(end2 - begin + 1));
}



//�鲢����ֿ�����(�ݹ�������ǰ��·��չ��)
void _MergeSort(int* num, int begin, int end, int* tmp)
{
	assert(num&&tmp);
	int mid = begin + (end - begin) / 2;
	//ֻ��һ��Ԫ�أ�˵����������Ѿ�����
	if (begin == end)
		return;
	//�����⻮����������
	_MergeSort(num, begin, mid, tmp);
	//�����⻮����������
	_MergeSort(num, mid + 1, end, tmp);
	//�ϲ�������������
	Merge(num, begin, mid, mid + 1, end, tmp);
}


//

void MergeSort(int* num, int len)
{
	if (num == NULL || len <= 0)
		return;
	//������ʱ�ռ䣬�������ÿ�κϲ����������
	int* tmp = (int*)malloc(sizeof(int)*len);
	_MergeSort(num, 0, len - 1, tmp);
	//�ͷſռ�
	free(tmp);
	tmp = NULL;
}
