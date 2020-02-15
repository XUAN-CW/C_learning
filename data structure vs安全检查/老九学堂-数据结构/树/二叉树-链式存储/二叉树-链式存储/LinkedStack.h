#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

#include "LinkedStackElement.h"

/** ��ʼ����ջ */
void InitLinkedStack(LinkedStack * linkedStack);

/** ��ջ */
int Push(LinkedStack * linkedStack, TreeNode * node);

/** ��ջ */
int Pop(LinkedStack * linkedStack, TreeNode ** node);

int IsLinkedStackEmpty(LinkedStack * linkedStack);


#endif // LINKEDSTACK_H_INCLUDED