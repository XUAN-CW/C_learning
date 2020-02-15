#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

ElementType datas[] = 
{
	{1, "Ҽ"},
	{2, "��"},
	{3, "��"},
	{4, "��"},
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
	printf("��ջԪ�أ�%d\t%s\n",popElement->id,popElement->name);
	printLinkedStack(linkedStack);
	printf("\n\n");

	ClearLinkedStack(linkedStack);
	printLinkedStack(linkedStack);
	printf("\n\n");



	system("pause");
}
