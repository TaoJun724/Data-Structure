
#include "HashTableBucket.h"

void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	//根据素数表获取哈希表的长度
	int HTB_len = GetNextPrime(len);
	//为哈希桶开辟空间(
	HashNode** table = (HashNode**)malloc(sizeof(HashNode*)*(HTB_len));
	if (table == NULL)
	{
		perror("use malloc of create");
		exit(EXIT_FAILURE);
	}
	htb->_tables = table;
	htb->_size = 0;
	htb->_len = HTB_len;
	//将哈希表中的所有指针初始化为空，否则会对野指针操作
	memset(htb->_tables,0, sizeof(HashNode*)*(htb->_len));
}

		

void HTBDestory(HTB* htb)
{
	unsigned int i = 0;
	assert(htb);

	for (; i < htb->_len; ++i)
	{
		HashNode* cur = htb->_tables[i];
		while (cur)
		{
			HashNode* next = cur->_next;
			free(cur);

			cur = next;
		}

		htb->_tables[i] = NULL;
	}

	free(htb->_tables);
	htb->_tables = NULL;
	htb->_size = 0;
	htb->_len = 0;
}

size_t HTBHashFunc(HTBKeyType key, size_t len)
{
	int count = 0;
	int i = 0;
	while (*(key + i) != '\0')
	{
		count += *(key + i);
		++i;
	}
	return count%len;
	
}


////哈希函数,计算哈希地址(整数)
//static int HTBHashFunc(HTBKeyType key, int len)
//{
//  return key%len;
//}


HashNode* BuyHashNode(HTBKeyType key, HTBValueType value)
{
	HashNode* node = malloc(sizeof(HashNode));
	if (node != NULL)
	{
		node->_key = key;
		node->_value = value;
		node->_next = NULL;
	}
	return node;
}

void HTBCheckCapacity(HTB* htb)
{
	assert(htb);
	if (htb->_size == htb->_len)
	{
		unsigned int i;
		HTB newhtb;
		newhtb._len = GetNextPrime(htb->_len);
		HTBInit(&newhtb, newhtb._len);
		if (htb->_size == htb->_len)
		{
			for (i = 0; i < htb->_len; ++i)
			{
				HashNode* cur = htb->_tables[i];
				while (cur)
				{
					//记录下一个结点的位置
					HashNode* next = cur->_next;
					size_t index = HTBHashFunc(cur->_key, newhtb._len);
					//头插到新的哈希表中
					cur->_next = newhtb._tables[index];
					newhtb._tables[index] = cur;

					cur = next;
				}

				htb->_tables[i] = NULL;
			}
		}

		HTBDestory(htb);

		htb->_tables = newhtb._tables;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}

int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	size_t index;
	HashNode* cur, *newNode;

	HTBCheckCapacity(htb);

	assert(htb);
	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
			return -1;

		cur = cur->_next;
	}

	newNode = BuyHashNode(key, value);
	newNode->_next = htb->_tables[index];
	htb->_tables[index] = newNode;
	htb->_size++;

	return 0;
}

int HTBRemove(HTB* htb, HTBKeyType key)
{
	size_t index;
	HashNode* cur = NULL, *prev = NULL;
	assert(htb);

	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			if (prev == NULL)
				htb->_tables[index] = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			--htb->_size;
			return 0;
		}

		prev = cur;
		cur = cur->_next;
	}

	return -1;
}

HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	size_t index;
	HashNode* cur;
	assert(htb);

	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

int HTBSize(HTB* htb)
{
	assert(htb);
	return htb->_size == 0 ? 0 : 1;
}
int HTBEmpty(HTB* htb)
{
	assert(htb);
	return htb->_size == htb->_len ? 0 : 1;
}

void HTBPrint(HTB* htb)
{
	unsigned int i = 0;
	assert(htb);
	for (i=0; i < htb->_len; ++i)
	{
		int count = 0;
		
		printf("table[%d]->", i);
		HashNode* cur = htb->_tables[i];
		while (cur)
		{
			printf("([key:%s}:{value:%s])->", cur->_key, cur->_value);
			count++;
			cur = cur->_next;
		}

		
		printf("(count=%d)->over\n", count);

	}


}


