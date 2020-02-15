#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"

int main()
{
	Skill skill[]=
	{
		{0,"斗气化马"},	
		{1,"雷霆半月斩"},
		{2,"金刚基础拳法"},
		{3,"神剑御雷真诀"},
	};

	SequenceList sequenceList;
	//printf("初始化前\n");
	//printf("sequenceList.length == %d", sequenceList.length);
	InitSequenceList(&sequenceList);
	printf("初始化后\n");
	printf("sequenceList.length == %d\n", sequenceList.length);
	PrintSequenceList(&sequenceList);
	printf("\n\n");


	printf("插入元素：\n");
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
	printf("删除后\n");
	PrintSequenceList(&sequenceList);
	printf("被删除的元素：%d %s\n",deletedElement.id, deletedElement.name);
	system("pause");
	return 0;
}
