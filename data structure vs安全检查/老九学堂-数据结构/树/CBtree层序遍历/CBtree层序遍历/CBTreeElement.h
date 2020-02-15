
#include "ElementType.h"

typedef struct cBNode 
{
	ElementType data;               //数据域
	struct cBNode * firstChild;     //长子结点
	struct cBNode * nextSibling;    //兄弟结点
}CBNode, CBTree;