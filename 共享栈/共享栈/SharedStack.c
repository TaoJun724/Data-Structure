#include "SharedStack.h"


void SharedStackInit(SharedStack* s)
{
	assert(s);
	s->top1 = 0;//Å¼Êý
	s->top2 = 1;//ÆæÊý
}
void SharedStackDestory(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if (1 == which)
	{
		assert(s);
		s->top1 = 0;
		free(s);
		s = NULL;
	}
	else if (2 == which)
	{
		assert(s);
		s->top2 = 0;
		free(s);
		s = NULL;
	}
}
void SharedStackPush(SharedStack* s, int which, DataType x)
{
	assert(1 == which || 2 == which);
	if (1 == which)
	{
		assert(s);
		if (s->top1 < MAX)
		{
			s->a[s->top1] = x;
			s->top1 += 2;
		}
	}
	else if (2 == which)
	{
		assert(s);
		if (s->top2 < MAX)
		{
			s->a[s->top2] = x;
			s->top2 += 2;
		}
	}
}
void SharedStackPop(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if (1 == which)
	{
		assert(s);
		assert(s->top1 > 0);
		s->top1 -= 2;
	}
	else if (2 == which)
	{
		assert(s);
		assert(s->top2 > 0);
		s->top2 -= 2;
	}
}
DataType SharedStackTop(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if (1 == which)
	{
		assert(s);
		assert(s->top1 > 0);
		return s->a[s->top1 - 2];
	}
	else if (2 == which)
	{
		assert(s);
		assert(s->top2 > 0);
		return s->a[s->top2 - 2];
	}
}
size_t SharedStackSize(SharedStack* s, int which)
{
	assert(s);
	assert(1 == which || 2 == which);
	return which == 1 ? (s->top1) / 2 : (s->top2 - 1) / 2;
}
int SharedStackEmpty(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if (1 == which)
	{
		assert(s);
		return s->top1 == 0 ? 0 : 1;
	}
	else if (2 == which)
	{
		assert(s);
		return  s->top2 == 1 ? 0 : 1;
	}

}
