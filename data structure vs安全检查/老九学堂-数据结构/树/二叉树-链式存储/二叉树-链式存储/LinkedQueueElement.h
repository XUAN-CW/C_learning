#include "ElementType.h"

/** ���ӽ�� */
typedef struct qNode
{
	TreeNode * data;            //������
	struct qNode * next;        //ָ����
}QueueNode;

/** ������ */
typedef struct
{
	QueueNode * qFront;         //��ͷָ��
	QueueNode * qRear;          //��βָ��
}LinkedQueue;


