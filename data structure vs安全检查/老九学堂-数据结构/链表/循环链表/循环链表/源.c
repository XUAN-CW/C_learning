#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "CircularLinkList.h"

//测试数据
ElementType dataArray[] = 
{
    {1, "一"},
    {2, "二"},
    {3, "三"},
    {4, "四"}
};

int main()
{
	CircularLinkList * clList = (CircularLinkList *)malloc(sizeof(CircularLinkList));
	clList->length = 0;
	clList->next = NULL;
	printf("初始化并插入:\n");
	InitCircularLinkList(clList, dataArray, 4);
	InsertCircularLinkList(clList, 5, dataArray[3]);
	PrintCircularLinkList(clList);
	printf("\n\n");

	ElementType deletedElement = DeleteCircularLinkList(clList, 5);
	printf("删除的结点：%d\t%s\n", deletedElement.id, deletedElement.name);
	PrintCircularLinkList(clList);
	printf("\n\n");

	printf("从四开始遍历：\n");
	CircularNode * node = GetCircularLinkListNode(clList, dataArray[3]);
	PrintCircularLinkListByNode(clList, node);
	printf("\n\n");

	system("pause");
    return 0;
}



