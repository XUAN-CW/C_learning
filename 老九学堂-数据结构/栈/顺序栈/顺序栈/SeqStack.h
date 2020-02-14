#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

/** ��ʼ��ջ */
void InitSeqStack(SeqStack * seqStack);

/** ��ջ��ѹ��Ԫ�أ�����ѹ��Ľ��(true/false) */
int PushSeqStack(SeqStack * seqStack, ElementType element);

/** ��ָ�뷽ʽ���س�ջ��Ԫ�أ�����ֵΪ��ջ�Ľ��(true/false) */
int PopSeqStack(SeqStack * seqStack, ElementType * element);

/** ���ջ */
void ClearSeqStack(SeqStack * seqStack);

/** ջ�Ƿ�Ϊ�գ�top == -1 */

/** ����ջ��Ԫ�� */
void GetSeqStackTopElement(SeqStack * seqStack, ElementType * element);


#endif // SEQSTACK_H_INCLUDED
