#include "HashTableBucket.h"




//void HTBtest1()
//{
//	HTB htb;
//	HTBInit(&htb, 10);
//	HTBInsert(&htb, 6, 0);
//	HTBInsert(&htb, 11, 0);
//	HTBPrint(&htb);
//
//
//	size_t begin, end;
//	size_t i;
//	HTB htb;
//
//	begin = clock();
//	HTBInit(&htb, GetNextPrime(100000));
//	//HTBInit(&htb, 10);
//	srand(time(0));
//	for (i = 0; i < GetNextPrime(100000); ++i)
//	{
//		HTBInsert(&htb, i + rand(), 0);
//	}
//	end = clock();
//
//	printf("%d\n", end - begin);
//
//	/*HTBPrint(&htb);*/
//}

void HTBtest2()
{
	HTB htb;
	HTBInit(&htb, 10);

	HTBInsert(&htb, "insert", "����");
	HTBInsert(&htb, "delete", "ɾ��");
	HTBInsert(&htb, "hash", "��ϣ");
	HTBInsert(&htb, "test", "����");

	HTBPrint(&htb);
}


int  main()
{
	HTBtest2();
	system("pause");
	return 0;
}