#include<stdio.h>
#include<assert.h>

//��һ������������Ǽ�λ��
int GetBitCount(int* array, int size)
{
	int count = 1;
	int radix = 10; //���õĻ���
	int i = 0;

	for (i = 0; i < size; i++)
	{
		while (array[i] >= radix)
		{
			count++;
			radix *= 10;
		}
	}
	return count;
}

#if 0
int getdigit(int x, int d)
{
	int a[] = { 1, 1, 10, 100 };   //�����λ������������ֻҪ��λ�������ˡ�  
	return (x / a[d]) % 10;
}
#endif


void RadixSort(int array[], int size)
{
	int bitCount = GetBitCount(array, size);
	int bitIdx = 0;
	int radix = 1;
	int *tmp = (int*)malloc(sizeof(array[0])* size);
	if (NULL == tmp)
	{
		assert(0);

		return;
	}

	//�м�λ������Ҫѭ������
	for (bitIdx = 0; bitIdx < bitCount; ++bitIdx)
	{
		int count[10] = { 0 };
		int i = 0;
		int StartAddr[10] = { 0 };

		//ͳ��ÿ��Ͱ��Ԫ�ظ���
		for (i = 0; i < size; i++)
			count[array[i] / radix % 10]++;

		//ͳ��ÿ��Ͱ����ʼ��ַ,���ﲻ��i<size,��ΪͰ�ĸ�����10����
		for (i = 1; i < 10; i++)
			StartAddr[i] = StartAddr[i - 1] + count[i - 1];

		//�����ݷŵ���ӦͰ��
		for (i = 0; i < size; i++)
		{
			int bucketNo = (array[i] / radix) % 10;
			tmp[StartAddr[bucketNo]] = array[i];
			StartAddr[bucketNo]++;
		}

		//��������(��Ͱ��Ŵ�С����ÿ��Ͱ���Ƚ��ȳ�)
		memcpy(array, tmp, sizeof(array[0]) * size);

		radix *= 10;
	}

	free(tmp);
}

