#include "ElementType.h"

/** 链队结点 */
typedef struct qNode
{
	TreeNode * data;            //数据域
	struct qNode * next;        //指针域
}QueueNode;

/** 链队列 */
typedef struct
{
	QueueNode * qFront;         //队头指针
	QueueNode * qRear;          //队尾指针
}LinkedQueue;


