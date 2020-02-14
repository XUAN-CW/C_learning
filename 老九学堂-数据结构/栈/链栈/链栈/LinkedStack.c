#include "LinkedStack.h"

void InitLinkedStack(LinkedStack * linkedStack) 
{
	linkedStack->top = NULL;
	linkedStack->length = 0;
}

/** 压栈并返回结果 */
int PushLinkedStack(LinkedStack * linkedStack, ElementType pushElement) 
{
	//创建一个新结点
	StackNode * newNode = (StackNode *)malloc(sizeof(StackNode));
	newNode->data = pushElement;
	//新结点的next指向当前的栈顶
	newNode->next = linkedStack->top;
	linkedStack->top = newNode;
	linkedStack->length++;
	return TRUE;
}

int PopLinkedStack(LinkedStack * linkedStack, ElementType * popElement) 
{
	if (linkedStack->top == NULL) 
	{
		printf("空栈，出栈操作失败！\n");
		return FALSE;
	}
	//返回栈顶元素
	*popElement = linkedStack->top->data;
	//记录出栈操作前的栈顶指针
	StackNode * popNode = linkedStack->top;
	//栈顶指针下移一位
	linkedStack->top = linkedStack->top->next;
	//释放原栈顶空间
	free(popNode);
	linkedStack->length--;
	return TRUE;
}

void printLinkedStack(LinkedStack * linkedStack)
{
	StackNode *currentNode = linkedStack->top;
	if (currentNode)
	{
		printf("栈中元素有：\n");
		while (currentNode)
		{
			printf("%d\t%s\n",currentNode->data.id,currentNode->data.name);
			currentNode = currentNode->next;
		}
	}
	else
	{
		printf("栈为空！");
	}

}

/** 清空栈-遍历栈中的每个元素并释放结点空间 */
void ClearLinkedStack(LinkedStack * linkedStack) 
{
	StackNode * tempNode;
	while (linkedStack->top) 
	{
		tempNode = linkedStack->top;
		//栈顶指向下个元素
		linkedStack->top = linkedStack->top->next;
		free(tempNode);
		linkedStack->length--;
	}
}

/** 销毁栈 */
void DestroyLinkedStack(LinkedStack * linkedStack) 
{
	//先清空栈
	ClearLinkedStack(linkedStack);
	free(linkedStack);
	linkedStack = NULL;
}

