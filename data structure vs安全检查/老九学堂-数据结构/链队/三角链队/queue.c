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
	// receivePollElement 用来接收出队的元素
	if (IsLinkQueueEmpty(linkQueue))
	{
		printf("队列为空！");
	}
	else
	{
		LinkQueueNode *front = linkQueue->front;
		*receivePollElement = front->data;
		if (linkQueue->front == linkQueue->rear)	//队中只有一个结点
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
		printf("链队为空！\n");
	}
	else
	{
		printf("队中元素有：\n");
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