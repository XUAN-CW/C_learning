#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "DoublyLinkList.h"

//测试数据
ElementType dataArray[] = 
{
    {1, "奇异博士"},
    {2, "美国队长"},
    {3, "太上老君"},
    {4, "菩提老祖"}
};

int main()
{
	DoublyLinkList * dlList = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
	dlList->length = 0;
	dlList->next = NULL;
	InsertDoublyLinkList(dlList, 1, dataArray[0]);
	InsertDoublyLinkList(dlList, 2, dataArray[1]);
	PrintDoublyLinkList(dlList);
	printf("删除第二个位置的元素：\n");
	DeleteDoubyLinkList(dlList, 2);
	PrintDoublyLinkList(dlList);
	system("pause");
    return 0;
}
