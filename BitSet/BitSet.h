#ifndef __BITSET_H__
#define __BITSET_H__



#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef  struct BitSet
{
	char*  a;
	size_t  N;//开辟的位个数
}BitSet;

void BitSetInit(BitSet* p, size_t n);

void BitSetDestory(BitSet* p);

//置1
void BitSetSet1(BitSet* p, size_t x);
//把1变为0
void BitSetSet0(BitSet* p, size_t x);



//判断数字是否在
int HaveNumber(BitSet* p, size_t x);

#endif


//
////1.给定100亿个整数，设计算法找到只出现一次的整数
//a.由于是整数，所以我们采用位图，100亿个整数，至少有一半相同的，大致就是需要1.25G的内存进行存储，一个数字就是需要2个位来表示状态，比如00表示不存在，01表示存在一次，10表示存在多次这样就可以全部表示出每一个数存在的状态，这里我们需要内存是2.5G
//b.也可以按照bit为分组，每个bit位2有0和1的区分，我们从第一个bit开始分两个支路，然后对第二个bit位进行分组，这样到最后，每个支路末端单独出现的元素就是只出现一次的整数。
////2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集个
//位图，只需要一个比特位来表示一个数字存在与否，将两个文件的数据分别映射到两个位图中，将两个位图按位与得出的结果为两个文件的交集
////3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
//两个比特位来表示状态，比如，01表示存在一次，10表示存在两次，表示多次，将每个数据映射到位图上，最后遍历得出结果
