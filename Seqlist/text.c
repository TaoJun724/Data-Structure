#define _CRT_SECURE_NO_WARNINGS 1


#include"Seqlist.h"


//
//int  main()
//{
//	Seqlist seq;
//	InitSeqlist(&seq);
//	Pushback(&seq, 1);
//	Pushback(&seq, 2);
//	Pushback(&seq, 3);
//	Pushback(&seq, 4);
//	PrintSeqlist(&seq);
//	Popback(&seq);
//	PrintSeqlist(&seq);
//	system("pause");
//	return 0;
//}

void TestPushBack()
{
	Seqlist seq;
	InitSeqlist(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	Pushback(&seq, 4);
	PrintSeqlist(&seq);
	Popback(&seq);
	PrintSeqlist(&seq);
	system("pause");
	return ;
}
void TestPushFront()
{
	Seqlist seq;
	InitSeqlist(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqlist(&seq);
	Popfront(&seq);
	PrintSeqlist(&seq);	
}
void Testfind()
{
    int pos = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqlist(&seq);
	pos = Find(&seq, 3);
	if (pos == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标为：  %d\n", pos);
	}
}
void TestInsert()
{
	int pos = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqlist(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		Insert(&seq, pos, 5);
	}
	PrintSeqlist(&seq);
}
void TestDel()
{
	int pos = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqlist(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		Del(&seq, pos );
	}
	PrintSeqlist(&seq);
}
void TestRemove()
{
	int pos = 0;
	Seqlist seq;
    InitSeqlist(&seq);
    PushFront(&seq, 1);
	PushFront(&seq, 2);
    PushFront(&seq, 3);
    PushFront(&seq, 4);
    PrintSeqlist(&seq);
    Remove(&seq, 6);
	PrintSeqlist(&seq);		
}
void TestRemoveall()
{
	int pos = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	if (!Empty(&seq))
	   printf("大小为%d\n", Size(&seq));
	PrintSeqlist(&seq);
	Removeall(&seq, 1);
	PrintSeqlist(&seq);
}
void Testbubblesort()
{
	int i = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	PrintSeqlist(&seq);
	Bubblesort(&seq);
	PrintSeqlist(&seq);
}
void TestSelectsort()
{
	int i = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	PrintSeqlist(&seq);
	Selectsort2(&seq);
	PrintSeqlist(&seq);
}

void TestBinarysearch()
{
	int i = 0;
	int pos = 0;
	Seqlist seq;
	InitSeqlist(&seq);
	for (i = 0; i < 10; i++)
	{
		PushFront(&seq, i);
	}
	PrintSeqlist(&seq);
	Selectsort2(&seq);
	PrintSeqlist(&seq);
	pos = Binarysearch2(&seq,0,seq.sz-1,7);
	if (pos != -1)
	{
		printf("找到了下标为 %d\n", pos);
	}
	else
	{
		printf("找不到\n");
	}
}
int main()
{

	/*TestPushBack();*/
	/*TestPushFront();*/
     /* Testfind();*/
	/*TestInsert();*/
	/*TestDel();*/
	//TestRemove();
	/*TestRemoveall();*/
	/*Testbubblesort();*/
	//TestSelectsort();
	TestBinarysearch();
	system("pause");

}