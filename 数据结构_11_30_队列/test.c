#include "Queue.h"

//���У�ֻ������һ�ν��в������ݲ���������һ�˽���ɾ�����ݲ������������Ա����������Ƚ��ȳ�
//����У����в��������һ�˳�Ϊ��β
//�����У�����ɾ��������һ�˳�Ϊ��ͷ


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