
#include "ElementType.h"

typedef struct cBNode 
{
	ElementType data;               //������
	struct cBNode * firstChild;     //���ӽ��
	struct cBNode * nextSibling;    //�ֵܽ��
}CBNode, CBTree;