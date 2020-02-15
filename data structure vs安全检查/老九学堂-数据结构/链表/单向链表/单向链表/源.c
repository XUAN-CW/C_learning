#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "LinkList.h"

//��������
ElementType dataArray[] = {
    {1, "���첩ʿ"},
    {2, "�����ӳ�"},
    {3, "̫���Ͼ�"},
    {4, "��������"}
};

int main()
{
	LinkList linkList;
	InitLinkList(&linkList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
	PrintLinkList(&linkList);
	printf("\n\n");

	ElementType element;
	element.id = 123;
	strcpy_s(element.name, sizeof(element.name), "ɽˮ�����");
	InsertLinkList(&linkList, 2, element);
	printf("�����\n");
	PrintLinkList(&linkList);
	printf("\n\n");

	ElementType deletedElement;
	printf("ɾ��Ԫ�غ�\n");
	deletedElement = DeleteLinkListElement(&linkList, 6);
	PrintLinkList(&linkList);
	printf("��ɾ����Ԫ���ǣ�%d\t%s\n", deletedElement.id, deletedElement.name);
	printf("\n\n");

	printf("�������\n");
	ClearLinkList(&linkList);
	PrintLinkList(&linkList);
	printf("\n\n");
	system("pause");
    return 0;
}





