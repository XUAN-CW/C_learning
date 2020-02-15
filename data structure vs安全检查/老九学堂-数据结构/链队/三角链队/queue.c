#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitLinkQueue(LinkQueue *linkQueue)
{
	linkQueue->front = NULL;
	linkQueue->rear = NULL;
	linkQueue->length = 0;
}

void OfferLinkQueue(LinkQueue *linkQueue, ElementType *offerElement)
{
	LinkQueueNode *newNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	newNode->next = NULL;
	newNode->data = *offerElement;
	if (IsLinkQueueEmpty(linkQueue))
	{
		linkQueue->front = newNode;
		linkQueue->rear = newNode;
		linkQueue->length++;
	}
	else
	{
		linkQueue->rear->next = newNode;
		linkQueue->rear = newNode;
		linkQueue->length++;
	}
}

void PollLinkQueue(LinkQueue *linkQueue,ElementType *receivePollElement)
{
	// receivePollElement �������ճ��ӵ�Ԫ��
	if (IsLinkQueueEmpty(linkQueue))
	{
		printf("����Ϊ�գ�");
	}
	else
	{
		LinkQueueNode *front = linkQueue->front;
		*receivePollElement = front->data;
		if (linkQueue->front == linkQueue->rear)	//����ֻ��һ�����
		{
			linkQueue->rear = NULL;
		}
			linkQueue->front = linkQueue->front->next;
			linkQueue->length--;
			free(front);
	}
}

void printfLinkQueue(LinkQueue *linkQueue)
{
	LinkQueueNode *currentNode = linkQueue->front;
	if (IsLinkQueueEmpty(linkQueue))
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("����Ԫ���У�\n");
		for (int i = 0; i < linkQueue->length; i++)
		{
			printf("%d\t%s\n", currentNode->data.id, currentNode->data.name);
			currentNode = currentNode->next;
		}
	}
}

void ClearLinkQueue(LinkQueue *linkQueue)
{
	ElementType *tempElement = (ElementType*)malloc(sizeof(ElementType));
	while (linkQueue->rear)
	{
		PollLinkQueue(linkQueue, tempElement);
	}
}

int IsLinkQueueEmpty(LinkQueue *linkQueue)
{
	if (linkQueue->front == NULL && linkQueue->rear == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}