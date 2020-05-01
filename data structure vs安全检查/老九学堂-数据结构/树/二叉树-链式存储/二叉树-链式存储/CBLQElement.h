#pragma once

#include "CBTreeElement.h"


/** 链队结点 */
typedef struct 
{
	CBNode * data;					//数据域
	CBNode * next;					//指针域
}CBLQueueNode;

/** 链队列 */
typedef struct
{
	CBLQueueNode * Front;         //队头指针
	CBLQueueNode * Rear;          //队尾指针
}CBLQueue;