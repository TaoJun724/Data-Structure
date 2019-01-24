#include "SharedStack.h"


void text()
{
	SharedStack s;
	SharedStackInit(&s);

	//SharedStackPush(&s, 1, 1);
	//SharedStackPush(&s, 1, 2);
	//SharedStackPush(&s, 1, 3);
	//SharedStackPush(&s, 1, 4);

	SharedStackPush(&s, 2, 7);
	SharedStackPush(&s, 2, 8);
	SharedStackPush(&s, 2, 9);
	SharedStackPush(&s, 2, 6);



	/*printf("%d\n", SharedStackEmpty(&s, 1));*/
	printf("%d\n", SharedStackEmpty(&s, 2));

	/* SharedStackDestory(&s, 2);*/

	//printf("%d\n", SharedStackTop(&s, 1));
	//printf("%d\n", SharedStackTop(&s, 2));


	//printf("%d\n", SharedStackSize(&s, 1));
	//printf("%d\n", SharedStackSize(&s, 2));
	//while (SharedStackEmpty(&s, 1) != 0)
	//{
	//	printf("%d ", SharedStackTop(&s,1));
	//	SharedStackPop(&s, 1);
	//}
	//printf("\n");


	while (SharedStackEmpty(&s, 2) != 0)
	{
		printf("%d ", SharedStackTop(&s, 2));
		SharedStackPop(&s, 2);
	}
	printf("\n");
}
int main()
{
	text();
	system("pause");
	return 0;
}