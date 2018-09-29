#include "Stack.h"

void text()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);
	StackPush(&s, 1);
	StackPush(&s, 3);
	StackPush(&s, 5);
	StackPush(&s, 7);




	//printf("Stack's size : %d \n", StackSize(&s));
	//printf("Stack's top : %d \n", StackTop(&s));
	//printf("Stack Is Empty Stack?: %d \n", StackEmpty(&s));
	//StackPop(&s);
	//printf("Stack's size : %d \n", StackSize(&s));
	while (StackEmpty(&s) != 0)
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
}






int main()
{
	text();
	system("pause");
	return 0;
}

