/*************************************************************
	date: July 2017
	copyright: Zhu En��ף����
	DO NOT distribute this code.
**************************************************************/
// ���е����Ӵ洢ʵ���ļ�
// ����ѭ���������и���ͷ�ڵ㣬ʹ��β���ָ��
// CLQ_   Circularly Linked Queue
////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "CLnkQueue.h"

LNode* CLQ_Create()
// ����һ������
{
	LNode* rear = (LNode*)malloc(sizeof(LNode));
	rear->data = 0;
	rear->next = rear;
	return rear;
}
void CLQ_Free(LNode* rear)
// rearָ��β���
{
	CLQ_MakeEmpty(rear);
	free(rear);
}

void CLQ_MakeEmpty(LNode*& rear)
// rearָ��β���
// �����б�Ϊ�ն���
{
	T item;
	while (!CLQ_IsEmpty(rear))
		CLQ_Out(rear, item);
}

bool CLQ_IsEmpty(LNode* rear)
// �ж϶����Ƿ�Ϊ��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	return rear->next->data == 0 ? true : false;
	/********** End **********/
}

int CLQ_Length(LNode* rear)
// ���ض��г��ȣ�rearָ��β���
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	//int length = 0;
	//for (LNode* temp = rear->next; temp != rear; length++, temp = temp->next) {}
	return rear->next->next->data;
	/********** End **********/
}

void CLQ_In(LNode*& rear, T x)
// �����, �½���������β����rearָ��β���
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	newNode->data = x;
	newNode->next = NULL;

	newNode->next = rear->next;
	rear->next = newNode;
	rear = newNode;
	
	rear->next->data++;
	/********** End **********/
}

bool CLQ_Out(LNode*& rear, T& item)
// �����С��ն���ʱ������ֵΪfalse��rearָ��β���
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/

	if (CLQ_IsEmpty(rear))
	{
		return false;
	}
	else
	{
		item = rear->next->next->data;
		(rear->next)->next = (rear->next->next)->next;
		if (rear->next->data==1)
		{
			rear = rear->next;
		}
		
		rear->next->data--;
		return true;
	}
	/********** End **********/
}

bool CLQ_Head(LNode* rear, T& item)
// rearָ��β���
// ��ȡ����ͷ���ն���ʱ����ֵΪfalse��
{
	if (CLQ_IsEmpty(rear))
		return false;

	item = rear->next->next->data;
	return true;
}
void CLQ_Print(LNode* rear)
// ��ӡ����
{
	if (CLQ_IsEmpty(rear)) {
		printf("The queue is: empty. \n");
		return;
	}
	LNode* node = rear->next->next;
	do {
		printf("%d  ", node->data);
		node = node->next;
	} while (node != rear->next);
	//printf("\n");
}
