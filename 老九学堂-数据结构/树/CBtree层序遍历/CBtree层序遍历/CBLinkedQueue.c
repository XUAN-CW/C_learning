#include "CBLinkedQueue.h"


//void InitLinkedQueue(CBLQueue * linkedQueue) 
//{
//	linkedQueue->Front = (CBLQueueNode *)malloc(sizeof(CBLQueueNode));
//	linkedQueue->Front->next = NULL;
//	linkedQueue->Rear = linkedQueue->Front;
//}
//
//void enCBLQueue(CBLQueue * linkedQueue, CBNode * data)
//{
//	CBLQueueNode * newNode = (CBLQueueNode *)malloc(sizeof(CBLQueueNode));
//	newNode->data = data;
//	newNode->next = NULL;
//	linkedQueue->Rear->next = newNode;
//	linkedQueue->Rear = newNode;
//}
//
//CBNode * deCBLQueue(CBLQueue * linkedQueue)
//{
//	CBNode * data = NULL;//��������
//	if (linkedQueue->Front == linkedQueue->Rear)
//	{
//		return data;
//	}
//	CBLQueueNode * newFrontNode = linkedQueue->Front->next;
//	data = newFrontNode->data;
//	linkedQueue->Front->next = newFrontNode->next;
//	if (linkedQueue->Rear == newFrontNode) 
//	{
//		linkedQueue->Rear = linkedQueue->Front;
//	}
//	free(newFrontNode);
//	return data;
//}
//
//int IsLinkedQueueEmpty1(CBLQueue * linkedQueue)
//{
//	if (linkedQueue->Front == linkedQueue->Rear) 
//	{
//		return 1;
//	}
//	return 0;
//}
