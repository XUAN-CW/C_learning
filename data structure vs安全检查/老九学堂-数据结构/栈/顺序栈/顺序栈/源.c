#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

ElementType datas[] = {
	{1, "一"},
	{2, "二"},
	{3, "三"},
	{4, "四"},
};

int main()
{
	SeqStack * stack = (SeqStack *)malloc(sizeof(SeqStack));
	ElementType * element = (ElementType *)malloc(sizeof(ElementType));
	InitSeqStack(stack);
	for (int i = 0; i < 4; i++) 
	{
		printf("当前入栈：%d\t%s\n", datas[i].id, datas[i].name);
		PushSeqStack(stack, datas[i]);
	}
	PopSeqStack(stack, element);
	printf("当前出栈元素：%d\t%s\n", element->id, element->name);
	for (int i = 0; i < stack->length; i++) 
	{
		printf("当前栈内元素：%d\t%s\n", stack->elements[i].id, stack->elements[i].name);
	}
	free(stack);
	system("pause");
	return 0;
}

