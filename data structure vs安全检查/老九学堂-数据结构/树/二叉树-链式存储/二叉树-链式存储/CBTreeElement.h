#ifndef LINKEDQUEUE1_H_INCLUDED
#define LINKEDQUEUE1_H_INCLUDED


#include "ElementType.h"

typedef struct cBNode 
{
	ElementType data;               //������
	struct cBNode * firstChild;     //���ӽ��
	struct cBNode * nextSibling;    //�ֵܽ��
}CBNode, CBTree;

#endif