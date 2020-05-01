#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

ElementType datas[] = {
	{1, "һ"},
	{2, "��"},
	{3, "��"},
	{4, "��"},
};

int main()
{
	SeqStack * stack = (SeqStack *)malloc(sizeof(SeqStack));
	ElementType * element = (ElementType *)malloc(sizeof(ElementType));
	InitSeqStack(stack);
	for (int i = 0; i < 4; i++) 
	{
		printf("��ǰ��ջ��%d\t%s\n", datas[i].id, datas[i].name);
		PushSeqStack(stack, datas[i]);
	}
	PopSeqStack(stack, element);
	printf("��ǰ��ջԪ�أ�%d\t%s\n", element->id, element->name);
	for (int i = 0; i < stack->length; i++) 
	{
		printf("��ǰջ��Ԫ�أ�%d\t%s\n", stack->elements[i].id, stack->elements[i].name);
	}
	free(stack);
	system("pause");
	return 0;
}

