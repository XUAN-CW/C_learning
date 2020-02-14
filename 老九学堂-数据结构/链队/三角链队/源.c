#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//��������
ElementType dataArray[] =
{
	{1, "Ҽ"},
	{2, "��"},
	{3, "��"},
	{4, "��"}
};

int main()
{
	LinkQueue *linkQueue = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitLinkQueue(linkQueue);
	printf("\n\n");

	OfferLinkQueue(linkQueue,&dataArray[0]);
	OfferLinkQueue(linkQueue, &dataArray[1]);
	printfLinkQueue(linkQueue);
	printf("\n\n");

	ElementType tempElement;
	PollLinkQueue(linkQueue, &tempElement);
	printf("����Ԫ��Ϊ��%d\t%s\n", tempElement.id, tempElement.name);
	printfLinkQueue(linkQueue);
	PollLinkQueue(linkQueue, &tempElement);
	printf("����Ԫ��Ϊ��%d\t%s\n", tempElement.id, tempElement.name);
	printfLinkQueue(linkQueue);
	printf("\n\n");

	OfferLinkQueue(linkQueue, &dataArray[0]);
	OfferLinkQueue(linkQueue, &dataArray[1]);
	printfLinkQueue(linkQueue);
	printf("��ն��к�\n");
	ClearLinkQueue(linkQueue);
	printfLinkQueue(linkQueue);
	printf("\n\n");

	system("pause");
	return 0;
}



