#include "ElementType.h"

/** �����ֵܱ�ʾ��������� */
typedef struct _CBNode
{
	int j;
	int k;
	int l;
	int i;
	ElementType data;               //������
	struct _CBNode * firstChild;     //���ӽ��
	struct _CBNode * nextSibling;    //�ֵܽ��
}CBNode, CBTree;

///** ���ӽ�� */
//typedef struct 
//{
//	CBNode * data;					//������
//	CBNode * next;					//ָ����
//}CBLQueueNode;
//
///** ������ */
//typedef struct
//{
//	CBLQueueNode * Front;         //��ͷָ��
//	CBLQueueNode * Rear;          //��βָ��
//}CBLQueue;