#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

#include "LinkedQueueElement.h"


void InitLinkedQueue(LinkedQueue * linkedQueue);

void enQueue(LinkedQueue * linkedQueue, TreeNode * data);

TreeNode * deQueue(LinkedQueue * linkedQueue);

int IsLinkedQueueEmpty(LinkedQueue * linkedQueue);










#endif // LINKEDQUEUE_H_INCLUDED
