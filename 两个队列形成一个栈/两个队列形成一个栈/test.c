#include  "StackByTQ.h"




void TestStackByTwoQueue()
{
	StackByTwoQueue s;
	StackByTwoQueueInit(&s);
	StackByTwoQueuePush(&s, 1);
	StackByTwoQueuePush(&s, 2);
	StackByTwoQueuePush(&s, 3);
	StackByTwoQueuePush(&s, 4);
	StackByTwoQueuePush(&s, 5);
	while (StackByTwoQueueEmpty(&s))
	{
		printf("%d ", StackByTwoQueueTop(&s));
		StackByTwoQueuePop(&s);
	}
}


int main()
{
	TestStackByTwoQueue();
	system("pause");
	return 0;
}