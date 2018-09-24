#include "MinStack.H"



void text()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 1);
	StackPush(&s, 6);
	StackPush(&s, 5);
	StackPush(&s, 4);
	StackPush(&s, 0);
	printf("Mindata: %d\n", StackMindata(&s));
}



int main()
{
	text();
	system("pause");
	return 0;
}