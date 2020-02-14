#include "ElementType.h"

/** 孩子兄弟表示法的树结点 */
typedef struct _CBNode
{
	int j;
	int k;
	int l;
	int i;
	ElementType data;               //数据域
	struct _CBNode * firstChild;     //长子结点
	struct _CBNode * nextSibling;    //兄弟结点
}CBNode, CBTree;

///** 链队结点 */
//typedef struct 
//{
//	CBNode * data;					//数据域
//	CBNode * next;					//指针域
//}CBLQueueNode;
//
///** 链队列 */
//typedef struct
//{
//	CBLQueueNode * Front;         //队头指针
//	CBLQueueNode * Rear;          //队尾指针
//}CBLQueue;