#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

ElementType datas[] = 
{
	{1, "Ò¼"},
	{2, "·¡"},
	{3, "Èþ"},
	{4, "ËÁ"},
};

int main()
{
	LinkedStack *linkedStack = (LinkedStack*)malloc(sizeof(LinkedStack));
	InitLinkedStack(linkedStack);
	PushLinkedStack(linkedStack, datas[0]);
	PushLinkedStack(linkedStack, datas[1]);
	printLinkedStack(linkedStack);
	printf("\n\n");

	ElementType * popElement = (ElementType *)malloc(sizeof(ElementType));
	PopLinkedStack(linkedStack, popElement);
	printf("³öÕ»ÔªËØ£º%d\t%s\n",popElement->id,popElement->name);
	printLinkedStack(linkedStack);
	printf("\n\n");

	ClearLinkedStack(linkedStack);
	printLinkedStack(linkedStack);
	printf("\n\n");



	system("pause");
}
