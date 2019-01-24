#include "MinStack.H"

void StackInit(Stack* s)
{
	assert(s);
	s->s1.a = (DataType*)malloc(sizeof(DataType));
	s->s1.top1 = 0;
	s->s1.capacity1 = 10;
	s->s2.a = (DataType*)malloc(sizeof(DataType));
	s->s2.top2 = 0;
	s->s2.capacity2 = 10;
}


void StackDestory(Stack* s)
{
	assert(s);
	s->s1.a = NULL;
	s->s1.top1 = 0;
	s->s1.capacity1 = 0;
	free(s->s1.a);
	s->s1.a = NULL;
	s->s1.top1 = 0;
	s->s1.capacity1 = 0;
	free(s->s1.a);
	s = NULL;
}
void StackPush(Stack* s, DataType x)
{
	assert(s);
	//栈满，开辟新的空间
	DataType* cur1;
	DataType* cur2;
	if (s->s1.top1 == s->s1.capacity1&&s->s2.top2 == s->s2.capacity2)
	{
		cur1 = (DataType*)realloc(s->s1.a, sizeof(s->s1.capacity1) * 2);
		if (cur1 != NULL)
		{
			s->s1.a = cur1;
		}
		s->s1.capacity1 *= 2;

		cur2 = (DataType*)realloc(s->s1.a, sizeof(s->s2.capacity2) * 2);
		if (cur2 != NULL)
		{
			s->s2.a = cur2;
		}
		s->s2.capacity2 *= 2;
	}
	//有空间

	if (s->s1.top1 == 0 && s->s2.top2 == 0)
	{
		//值都入俩个栈
		s->s1.a[s->s1.top1++] = x;
		s->s2.a[s->s2.top2++] = x;
	}

	//如果s2的栈顶元素小于所要入的值则只入到s1
	else if (s->s2.a[s->s2.top2 - 1] >= x)
	{
		s->s1.a[s->s1.top1++] = x;
		s->s2.a[s->s2.top2++] = x;
	}
	else
	{
		s->s1.a[s->s1.top1++] = x;
	}




	//assert(s);
	//StackPush(&s->s1, x);
	//if (StackEmpty(&s->s2 == 0)
	//	|| s->s2.a[s->s2.top2 - 1] >= x)
	//{
	//	StackPush(&s->s1, x);
	//}



}


void StackPop(Stack* s)
{
	assert(s);
	assert(s->s2.top2 > 0);
	if (s->s1.top1 == 0 && s->s2.top2 == 0)
	{
		printf("栈已空！！！");
		return;
	}
	if (s->s1.a[s->s1.top1] == s->s2.a[s->s2.top2 - 1])
	{
		s->s2.top2--;
		s->s1.top1--;
	}
	else
	{
		s->s2.top2--;
	}
}


int StackMindata(Stack* s)
{
	assert(s);
	if (s->s1.top1 == 0 && s->s2.top2 == 0)
	{
		printf("栈已空！！！");
		return 0;
	}
	return (s->s2.a[s->s2.top2 - 1]);

}



size_t StackSize(Stack* s)
{
	assert(s);
	assert(s->s1.top1);
	assert(s->s2.top2);
	s->s1.top1++;
	s->s2.top2++;
	return s->s1.top1 + s->s2.top2;
}



int StackEmpty(Stack* s)
{
	assert(s);
	return (s->s1.top1) || (s->s2.top2) == 0 ? 0 : 1;
}
