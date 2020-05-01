#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "CircularLinkList.h"

//��������
ElementType dataArray[] = 
{
    {1, "һ"},
    {2, "��"},
    {3, "��"},
    {4, "��"}
};

int main()
{
	CircularLinkList * clList = (CircularLinkList *)malloc(sizeof(CircularLinkList));
	clList->length = 0;
	clList->next = NULL;
	printf("��ʼ��������:\n");
	InitCircularLinkList(clList, dataArray, 4);
	InsertCircularLinkList(clList, 5, dataArray[3]);
	PrintCircularLinkList(clList);
	printf("\n\n");

	ElementType deletedElement = DeleteCircularLinkList(clList, 5);
	printf("ɾ���Ľ�㣺%d\t%s\n", deletedElement.id, deletedElement.name);
	PrintCircularLinkList(clList);
	printf("\n\n");

	printf("���Ŀ�ʼ������\n");
	CircularNode * node = GetCircularLinkListNode(clList, dataArray[3]);
	PrintCircularLinkListByNode(clList, node);
	printf("\n\n");

	system("pause");
    return 0;
}



