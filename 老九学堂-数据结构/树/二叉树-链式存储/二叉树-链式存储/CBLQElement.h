#pragma once

#include "CBTreeElement.h"


/** ���ӽ�� */
typedef struct 
{
	CBNode * data;					//������
	CBNode * next;					//ָ����
}CBLQueueNode;

/** ������ */
typedef struct
{
	CBLQueueNode * Front;         //��ͷָ��
	CBLQueueNode * Rear;          //��βָ��
}CBLQueue;