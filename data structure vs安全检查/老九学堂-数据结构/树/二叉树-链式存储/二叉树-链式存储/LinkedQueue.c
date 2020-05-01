#include "LinkedQueue.h"

void InitLinkedQueue(LinkedQueue * linkedQueue) 
{
	linkedQueue->qFront = (QueueNode *)malloc(sizeof(QueueNode));
	linkedQueue->qFront->next = NULL;
	linkedQueue->qRear = linkedQueue->qFront;
}

void enQueue(LinkedQueue * linkedQueue, TreeNode * data) 
{
	QueueNode * node = (QueueNode *)malloc(sizeof(QueueNode));
	node->data = data;
	node->next = NULL;
	linkedQueue->qRear->next = node;
	linkedQueue->qRear = node;
}

TreeNode * deQueue(LinkedQueue * linkedQueue) 
{
	TreeNode * data = NULL;//ÓÃÀ´·µ»Ø
	if (linkedQueue->qFront == linkedQueue->qRear) return data;
	QueueNode * node = linkedQueue->qFront->next;
	data = node->data;
	linkedQueue->qFront->next = node->next;
	if (linkedQueue->qRear == node) 
	{
		linkedQueue->qRear = linkedQueue->qFront;
	}
	free(node);
	return data;
}

int IsLinkedQueueEmpty(LinkedQueue * linkedQueue) 
{
	if (linkedQueue->qFront == linkedQueue->qRear) 
	{
		return 1;
	}
	return 0;
}
