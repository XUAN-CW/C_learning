#include "SeqStack.h"

void InitSeqStack(SeqStack * seqStack) 
{
	seqStack->top = -1; //ջ��ָ��-1���±�
	seqStack->length = 0;
}

int PushSeqStack(SeqStack * seqStack, ElementType element) 
{
	if (seqStack->top == MAX_SIZE - 1) 
	{
		printf("��ջ��ѹջ����ʧ�ܣ�");
		return FALSE;
	}
	else
	{
		seqStack->top++;        //ջ��ָ��+1���Ա�����µ�Ԫ��
		//���²����Ԫ�ظ�ֵ��ջ��
		seqStack->elements[seqStack->top] = element;
		seqStack->length++;
		return TRUE;
	}
}

int PopSeqStack(SeqStack * seqStack, ElementType * element)
{
	if (seqStack->top == -1) 
	{
		printf("��ջ����ջʧ�ܣ�\n");
		return FALSE;
	}
	else
	{
		//����ջ��ָ���Ԫ��
		*element = seqStack->elements[seqStack->top];
		seqStack->top--;
		seqStack->length--;
		return TRUE;
	}
	
}

void ClearSeqStack(SeqStack * seqStack) 
{
	seqStack->top = -1;
	seqStack->length = 0;
}

void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element) 
{
	if (seqStack->top == -1) 
	{
		printf("��ջ��ջ��Ԫ��Ϊ�գ�\n");
		element = NULL;
		return;
	}
	*element = seqStack->elements[seqStack->top];
}
