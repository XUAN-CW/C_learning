#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "LinkList.h"

//测试数据
ElementType dataArray[] = {
    {1, "奇异博士"},
    {2, "美国队长"},
    {3, "太上老君"},
    {4, "菩提老祖"}
};

int main()
{
	LinkList linkList;
	InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
	PrintLinkList(&linkList);
	printf("\n\n");

	ElementType element;
	element.id = 123;
	strcpy_s(element.name, sizeof(element.name), "山水有相逢");
	InsertLinkList(&linkList, 2, element);
	printf("插入后：\n");
	PrintLinkList(&linkList);
	printf("\n\n");

	ElementType deletedElement;
	printf("删除元素后：\n");
	deletedElement = DeleteLinkListElement(&linkList, 6);
	PrintLinkList(&linkList);
	printf("被删除的元素是：%d\t%s\n", deletedElement.id, deletedElement.name);
	printf("\n\n");

	printf("清空链表：\n");
	ClearLinkList(&linkList);
	PrintLinkList(&linkList);
	printf("\n\n");
	system("pause");
    return 0;
}





