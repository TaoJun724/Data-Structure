#include "CheckStack.h"



int InOutStackIsValid(int* InOrder, int InSize, int* OutOrder, int OutSize)
{
	assert(InOrder&&OutOrder);
	Stack s;
	int In = 0;
	int Out = 0;
	if (InSize != OutSize)
		return 0;
	StackInit(&s);


	while (Out < OutSize)
	{
		//ջ��Ԫ����Outorder�еĵ�һ��Ԫ�ز�ͬ����ջ
		while (StackTop(&s) != OutOrder[Out] || StackEmpty(&s) == 0)
		{
			if (In < InSize)
				StackPush(&s, InOrder[In++]);
			else
				return 0;
		}
		//ջ��Ԫ�غ�Outorder�ĵ�һ��Ԫ����ͬ�ͳ�ջ
		StackPop(&s);
		Out++;
	}
	return 1;

}

void TestCheckStack()
{
	int InOrder[] = { 1, 2, 3, 4, 5 };
	int InSize = sizeof(InOrder) / sizeof(InOrder[0]);
	int OutOrder[] = { 5, 4, 3, 2, 1 };
	int OutSize = sizeof(OutOrder) / sizeof(OutOrder[0]);
	if (InOutStackIsValid(InOrder, InSize, OutOrder, OutSize))
	{

		printf("����Ϸ�����\n");

	}
	else
	{
		printf("������Ϸ�������\n");
	}
}
int main()
{
	TestCheckStack();
	system("pause");
	return 0;
}