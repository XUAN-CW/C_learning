#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//测试数据
ElementType dataArray[] =
{
	{1, "壹"},
	{2, "贰"},
	{3, "叁"},
	{4, "肆"}
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
	printf("出队元素为：%d\t%s\n", tempElement.id, tempElement.name);
	printfLinkQueue(linkQueue);
	PollLinkQueue(linkQueue, &tempElement);
	printf("出队元素为：%d\t%s\n", tempElement.id, tempElement.name);
	printfLinkQueue(linkQueue);
	printf("\n\n");

	OfferLinkQueue(linkQueue, &dataArray[0]);
	OfferLinkQueue(linkQueue, &dataArray[1]);
	printfLinkQueue(linkQueue);
	printf("清空队列后：\n");
	ClearLinkQueue(linkQueue);
	printfLinkQueue(linkQueue);
	printf("\n\n");

	system("pause");
	return 0;
}



