#include "HashTable.h"

//闭散列

void HTInit(HashTable* ht, size_t len)
{
	size_t i;
	assert(len > 0);
	assert(ht);

	len = GetNextPrime(len);
	ht->len = len;
	ht->size = 0;
	ht->tables = (HashNode*)malloc(sizeof(HashNode)*ht->len);
	memset(ht->tables, 0, sizeof(HashNode)*len);
	for (i = 0; i < ht->len; i++)
	{
		ht->tables[i]._state = EMPTY;
	}
}

void HTDestory(HashTable* ht)
{
	assert(ht);
	free(ht->tables);
	ht->tables = NULL;
	ht->len = 0;
	ht->size = 0;
}

size_t HashTableFunc(HTKeyType key, size_t len)
{
	return  StrHash(key) % len;
}

void ExpendCapacity(HashTable *ht)//给数组增容变为新数组
{
	if ((ht->size * 10) / (ht->len) > 7)//如果当前的元素个数>数组长度的0.7增容减少哈希冲突
	{
		HashTable newht;
		HTInit(&newht, GetNextPrime(ht->len));
		for (unsigned int i = 0; i <ht->len; i++)
		{
			if (ht->tables[i]._state == EXITS)
			{
				HTInsert(&newht, ht->tables[i]._key, ht->tables[i]._value);
			}
		}
		HTDestory(ht);
		ht->len = newht.len;
		ht->size = newht.size;
		ht->tables = newht.tables;
	}
}

int HTInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	// 增容
	int i = 0;
	size_t index;
	size_t start;
	ExpendCapacity(ht);

	start = HashTableFunc(key, ht->len);
	index = start;
	while (ht->tables[index]._state == EXITS)
	{
		if (ht->tables[index]._key == key)
		{
			return 0;
		}
		else
		{
			/*++index;
			if (index == ht->_len){
			index = 0;
			}*/

			++i;
			index = start + i*i;
			index %= ht->len;
		}
	}
	ht->tables[index]._state = EXITS;
	ht->tables[index]._key = key;
	ht->tables[index]._value = value;
	ht->size++;
	return 1;
}
int HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	HashNode* cur = HTFind(ht, key);//先查找位置
	if (cur == NULL)
	{
		return 0;
	}
	else
	{
		cur->_state = DELETE;//直接把状态置为删除
		ht->size--;
		return 1;
	}

}

HashNode* HTFind(HashTable* ht, HTKeyType key)
{
	assert(ht);
	int index = HashTableFunc(key, ht->len);
	int i = 1;
	while (ht->tables[index]._state != EMPTY)
	{
		if (ht->tables[index]._key == key)
		{
			if (ht->tables[index]._state == EXITS)
			{
				return &(ht->tables[index]);
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			++index;
			if (index == ht->len)
			{
				index = 0;
			}
		}
	}
	return NULL;
}
int HTSize(HashTable* ht)
{
	assert(ht);
	return ht->size;
}
int HTEmpty(HashTable* ht)
{
	assert(ht);
	return ht->size == 0 ? 0 : 1;
}

//
//void HashPrint(HashTable *ht)//打印数组
//{
//	unsigned int i = 0;
//	for (i = 0; i < ht->len; i++)
//	{
//		if (ht->tables[i]._state == EXITS)
//			printf("[%d]->Exits->%d\n", i, ht->tables[i]._key);
//		else  if (ht->tables[i]._state == EMPTY)
//		{
//			printf("[%d]->Empty\n", i);
//		}
//		else
//		{
//			printf("[%d]->Delte\n", i);
//		}
//	}
//	printf("\n");
//}

void HashPrint(HashTable *ht)//打印数组
{
	int i = 0;
	char* strState[3] = { "EMPTY", "EXIST", "DELETE" };
	assert(ht);
	for (; i < ht->len; ++i)
	{
		printf("%s->table[%d]%s:%d\n", strState[ht->tables[i]._state], i,
			ht->tables[i]._key, ht->tables[i]._value);
	}
	printf("\n");
}