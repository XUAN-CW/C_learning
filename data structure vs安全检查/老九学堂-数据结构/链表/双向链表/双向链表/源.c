#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"
#include "DoublyLinkList.h"

//��������
ElementType dataArray[] = 
{
    {1, "���첩ʿ"},
    {2, "�����ӳ�"},
    {3, "̫���Ͼ�"},
    {4, "��������"}
};

int main()
{
	DoublyLinkList * dlList = (DoublyLinkList*)malloc(sizeof(DoublyLinkList));
	dlList->length = 0;
	dlList->next = NULL;
	InsertDoublyLinkList(dlList, 1, dataArray[0]);
	InsertDoublyLinkList(dlList, 2, dataArray[1]);
	PrintDoublyLinkList(dlList);
	printf("ɾ���ڶ���λ�õ�Ԫ�أ�\n");
	DeleteDoubyLinkList(dlList, 2);
	PrintDoublyLinkList(dlList);
	system("pause");
    return 0;
}
