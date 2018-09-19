#include "Queue.h"

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueDestory(&q);
	//printf("%d ", QueueFront(&q));
	//printf("%d ", QueueBack(&q));
	/*printf("Stack's size : %d \n", QueueEmpty(& q));*/
	//printf("Stack's size : %d \n", QueueSize(&q));
	while (QueueEmpty(&q) != 0)
	{
		printf("%d ", QueueFront(&q));
        QueuePop(&q);
	}
	printf("\n");
}


int main()
{
	Test();
	system("pause");
}