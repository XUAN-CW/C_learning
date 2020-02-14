#include "LinkedStack.h"

void InitLinkedStack(LinkedStack * linkedStack) 
{
	linkedStack->top = NULL;
	linkedStack->length = 0;
}

/** ѹջ�����ؽ�� */
int PushLinkedStack(LinkedStack * linkedStack, ElementType pushElement) 
{
	//����һ���½��
	StackNode * newNode = (StackNode *)malloc(sizeof(StackNode));
	newNode->data = pushElement;
	//�½���nextָ��ǰ��ջ��
	newNode->next = linkedStack->top;
	linkedStack->top = newNode;
	linkedStack->length++;
	return TRUE;
}

int PopLinkedStack(LinkedStack * linkedStack, ElementType * popElement) 
{
	if (linkedStack->top == NULL) 
	{
		printf("��ջ����ջ����ʧ�ܣ�\n");
		return FALSE;
	}
	//����ջ��Ԫ��
	*popElement = linkedStack->top->data;
	//��¼��ջ����ǰ��ջ��ָ��
	StackNode * popNode = linkedStack->top;
	//ջ��ָ������һλ
	linkedStack->top = linkedStack->top->next;
	//�ͷ�ԭջ���ռ�
	free(popNode);
	linkedStack->length--;
	return TRUE;
}

void printLinkedStack(LinkedStack * linkedStack)
{
	StackNode *currentNode = linkedStack->top;
	if (currentNode)
	{
		printf("ջ��Ԫ���У�\n");
		while (currentNode)
		{
			printf("%d\t%s\n",currentNode->data.id,currentNode->data.name);
			currentNode = currentNode->next;
		}
	}
	else
	{
		printf("ջΪ�գ�");
	}

}

/** ���ջ-����ջ�е�ÿ��Ԫ�ز��ͷŽ��ռ� */
void ClearLinkedStack(LinkedStack * linkedStack) 
{
	StackNode * tempNode;
	while (linkedStack->top) 
	{
		tempNode = linkedStack->top;
		//ջ��ָ���¸�Ԫ��
		linkedStack->top = linkedStack->top->next;
		free(tempNode);
		linkedStack->length--;
	}
}

/** ����ջ */
void DestroyLinkedStack(LinkedStack * linkedStack) 
{
	//�����ջ
	ClearLinkedStack(linkedStack);
	free(linkedStack);
	linkedStack = NULL;
}

