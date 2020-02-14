#include "SeqStack.h"

void InitSeqStack(SeqStack * seqStack) 
{
	seqStack->top = -1; //栈顶指向-1的下标
	seqStack->length = 0;
}

int PushSeqStack(SeqStack * seqStack, ElementType element) 
{
	if (seqStack->top == MAX_SIZE - 1) 
	{
		printf("满栈，压栈操作失败！");
		return FALSE;
	}
	else
	{
		seqStack->top++;        //栈顶指针+1，以便加入新的元素
		//将新插入的元素赋值给栈顶
		seqStack->elements[seqStack->top] = element;
		seqStack->length++;
		return TRUE;
	}
}

int PopSeqStack(SeqStack * seqStack, ElementType * element)
{
	if (seqStack->top == -1) 
	{
		printf("空栈，出栈失败！\n");
		return FALSE;
	}
	else
	{
		//返回栈顶指向的元素
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
		printf("空栈，栈顶元素为空！\n");
		element = NULL;
		return;
	}
	*element = seqStack->elements[seqStack->top];
}
