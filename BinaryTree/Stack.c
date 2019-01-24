#include "Stack.h"


void StackInit(Stack* s)
{
	assert(s != NULL);
	s->_a = (DataType*)malloc(sizeof(DataType)* 10);
	s->_top = 0;
	s->_capacity = 10;
}
void StackDestory(Stack* s)
{
	assert(s);
	s->_a = NULL;
	s->_top = 0;
	s->_capacity = 0;
	free(s);
	s = NULL;
}
void StackPush(Stack* s, DataType x)
{
	DataType* cur;
	assert(s);
	if (s->_top == s->_capacity)
	{
		cur = (DataType*)realloc(s->_a, sizeof(DataType)* 2 * (s->_capacity));
		if (cur != NULL)
		{
			s->_a = cur;
		}
		s->_capacity *= 2;
	}
	s->_a[s->_top++] = x;
}
void StackPop(Stack* s)
{
	assert(s);
	assert(s->_top > 0);
	s->_top--;
}
DataType StackTop(Stack* s)
{
	assert(s);
	assert(s->_top > 0);
	return s->_a[s->_top - 1];

}
size_t StackSize(Stack* s)
{
	assert(s);
	return s->_top++;
}
int StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0 ? 0 : 1;
}




