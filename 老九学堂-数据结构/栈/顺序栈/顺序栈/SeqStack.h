#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

/** 初始化栈 */
void InitSeqStack(SeqStack * seqStack);

/** 向栈中压入元素，返回压入的结果(true/false) */
int PushSeqStack(SeqStack * seqStack, ElementType element);

/** 以指针方式返回出栈的元素，返回值为出栈的结果(true/false) */
int PopSeqStack(SeqStack * seqStack, ElementType * element);

/** 清空栈 */
void ClearSeqStack(SeqStack * seqStack);

/** 栈是否为空：top == -1 */

/** 返回栈顶元素 */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element);


#endif // SEQSTACK_H_INCLUDED
