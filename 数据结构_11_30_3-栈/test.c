#include "Stack.h"


//ջ��һ����������Ա���ֻ�����ڹ̶���һ�ν��в����ɾ��Ԫ�ز������������ݲ����ɾ��������һ�˳�Ϊջ����
//��һ�˳�Ϊջ�ס�ջ�е�����Ԫ�����غ���ȳ�LIFO(last in first out)��ԭ�� 
//ѹջ��ջ�Ĳ������������ջ��ѹջ����ջ����������ջ��
//��ջ��ջ��ɾ������������ջ��������Ҳ��ջ��



//��������ջ���൱��֮ǰ˳����β��βɾ����βȥ����ջ�����ǳ����ʣ�Ψһȱ�ݾ��ǿռ䲻����Ҫ����
//������ʵ��ջ��1�������β����ջ����ôҪ��˫��������� 2������õ�����ʵ�֣���ô����ͷȥ��ջ�����ã�������ջ��ջЧ�ʶ���O(1)


int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPush(&st, 7);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);

	return 0;
}