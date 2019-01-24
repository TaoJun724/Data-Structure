#include  "SeqlistD.h" 



void test()
{
	Seqlist seq;
	InitSeqlist(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 4);
	Pushback(&seq, 13);
	Pushback(&seq, 15);
	PrintSeqlist(&seq);
	Popback(&seq);
	PrintSeqlist(&seq);
	DestorySeqlist(&seq);
}



int main()
{
	test();
	system("pause");
}