#include "HashTable.h"
//
//void HTtest1()
//{
//	HashNode* ret;
//	HashTable ht;
//	size_t i;
//	HTInit(&ht, 10);
//	HTInsert(&ht, 7, 0);
//	HTInsert(&ht, 17, 0);
//	HTInsert(&ht, 27, 0);
//	HTInsert(&ht, 8, 0);
//	HashPrint(&ht);
//
//	HTRemove(&ht, 17);
//	ret = HTFind(&ht, 27);
//	ret->_value = 10;
//	HashPrint(&ht);
//	/*for (i = 0; i < 10; ++i)
//	{
//		HTInsert(&ht, rand(), i);
//	}
//	HashPrint(&ht);*/
//}
void HTtest2()
{
	int i = 0;
	HashNode* ret;
	char* strs[] = { "insert", "insert", "insert", "insert", "insert", "sort", "insert", "sort", "find" };
	/*char* strs[] = {"abcd", "bcad", "cbad","cbad", "aad", "abc", "acb"};*/
	HashTable ht;
	HTInit(&ht, 10);
	for (; i < sizeof(strs) / sizeof(char*); ++i)
	{
		ret = HTFind(&ht, strs[i]);
		if (ret)
		{
			ret->_value++;
		}
		else
		{
			HTInsert(&ht, strs[i], 1);
		}
	}

	HashPrint(&ht);
}





int  main()
{
	HTtest2();
	system("pause");
	return 0;
}