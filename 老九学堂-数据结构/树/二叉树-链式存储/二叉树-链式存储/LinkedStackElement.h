#include "ElementType.h"

/** ջ��� */
typedef struct stackNode
{
	TreeNode * data;            //������-��֮ǰʵ�ֵ���ջ������ͬ
	struct stackNode * next;    //ָ����
}StackNode;

typedef struct
{
	StackNode * top;            //ջ��ָ��
	int length;                 //ջ����
}LinkedStack;