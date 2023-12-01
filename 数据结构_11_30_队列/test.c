#include "Queue.h"

//队列：只允许在一段进行插入数据操作，在另一端进行删除数据操作的特殊线性表，对流具有先进先出
//入队列：进行插入操作的一端称为队尾
//出队列：进行删除操作的一端称为队头


void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	

	QueueDestory(&q);
}


int main()
{
	TestQueue();

	return 0;
}