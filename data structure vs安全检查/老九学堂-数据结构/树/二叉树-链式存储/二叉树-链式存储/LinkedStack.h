#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

#include "LinkedStackElement.h"

/** 初始化链栈 */
void InitLinkedStack(LinkedStack * linkedStack);

/** 入栈 */
int Push(LinkedStack * linkedStack, TreeNode * node);

/** 出栈 */
int Pop(LinkedStack * linkedStack, TreeNode ** node);

int IsLinkedStackEmpty(LinkedStack * linkedStack);


#endif // LINKEDSTACK_H_INCLUDED