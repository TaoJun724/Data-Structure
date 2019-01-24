#include "QueueByTS.h"



void TestQueueByTwoStack()
{
	QueueByTwoStack qts;
	QueueByTwoStackInit(&qts);
	QueueByTwoStackPush(&qts, 1);
	QueueByTwoStackPush(&qts, 2);
	QueueByTwoStackPush(&qts, 3);
	/*QueueByTwoStackPop(&qts);*/
	//printf("%d\n", QueueByTwoStackSize(&qts));
	/*printf("%d\n", QueueByTwoStackEmpty(&qts));*/


	while (QueueByTwoStackEmpty(&qts) != 0)
	{
		printf("%d ", QueueByTwoStackFront(&qts));
		QueueByTwoStackPop(&qts);
	}
	printf("\n");
}


int main()
{
	TestQueueByTwoStack();
	system("pause");
	return 0;
}