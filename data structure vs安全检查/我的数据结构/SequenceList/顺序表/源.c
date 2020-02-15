#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"

int main()
{
	Skill skill[]=
	{
		{0,"��������"},	
		{1,"��������ն"},
		{2,"��ջ���ȭ��"},
		{3,"���������"},
	};

	SequenceList sequenceList;
	//printf("��ʼ��ǰ\n");
	//printf("sequenceList.length == %d", sequenceList.length);
	InitSequenceList(&sequenceList);
	printf("��ʼ����\n");
	printf("sequenceList.length == %d\n", sequenceList.length);
	PrintSequenceList(&sequenceList);
	printf("\n\n");


	printf("����Ԫ�أ�\n");
	InsertElement(&sequenceList, &skill[0], 0);
	InsertElement(&sequenceList, &skill[1], 1);
	PrintSequenceList(&sequenceList);
	InsertElement(&sequenceList, &skill[2], 3);
	InsertElement(&sequenceList, &skill[3], 4);
	InsertElement(&sequenceList, &skill[2], 2);
	InsertElement(&sequenceList, &skill[3], 3);
	PrintSequenceList(&sequenceList);
	InsertElement(&sequenceList, &skill[3], 1);
	printf("\n\n");

	Skill deletedElement = DeleteElement(&sequenceList, 2);
	printf("ɾ����\n");
	PrintSequenceList(&sequenceList);
	printf("��ɾ����Ԫ�أ�%d %s\n",deletedElement.id, deletedElement.name);
	system("pause");
	return 0;
}
