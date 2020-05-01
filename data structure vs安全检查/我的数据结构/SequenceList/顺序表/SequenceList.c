
#include "SequenceList.h"

void InitSequenceList(SequenceList *sequenceList)
{
	sequenceList->length = 0;
}

void InsertElement(SequenceList *sequenceList, Skill *skill, int index)
{
	//判断数组是否已满
	if (sequenceList->length == HERO_MAX)
	{
		printf("数组已满,插入失败！\n");
		return;
	}
	//判断index是否在 [ 0, HERO_MAX - 1 ] 内
	if (index < 0 || index > HERO_MAX - 1)
	{
		printf("超出数组最大范围，插入失败！\n");
		return;
	}
	//index应在 [ 0, length ] 之间
	if (index > sequenceList->length)
	{
		printf("当前只能在[ 0, %d ]内插入元素!,插入失败！\n", sequenceList->length);
		return;
	}
	//前一个覆盖后一个，第 index 个被插入元素覆盖，达到后移效果
	for (int cursor = sequenceList->length - 1; cursor >= index; cursor--)
	{
		sequenceList->heroes[cursor + 1] = sequenceList->heroes[cursor];
	}
	sequenceList->heroes[index] = *skill;
	//总长度++ ！！！
	sequenceList->length++;
}

Skill DeleteElement(SequenceList *sequenceList, int index)
{
	//index应在 [ 0, length - 1 ] 之间
	if (index > sequenceList->length)
	{
		printf("当前只能删除[ 0, %d ]内的元素，删除失败！\n", sequenceList->length - 1);
		Skill unfound = { 0,"0" };
		return unfound;
	}
	Skill deletedElement = sequenceList->heroes[index];
	//被删除的元素被覆盖,后一个元素覆盖前一个元素，达到前移效果
	for (int cursor = index; cursor < sequenceList->length - 1; cursor++)
	{
		sequenceList->heroes[cursor] = sequenceList->heroes[cursor + 1];
	}
	//总长度-- !!!
	sequenceList->length--;
	return deletedElement;
}

int GetSequenceLength(SequenceList *sequenceList)
{
	return sequenceList->length;
}

_Bool IsEmpty(SequenceList *sequenceList)
{
	if (sequenceList->length == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void ClearList(SequenceList *sequenceList)
{
	sequenceList->length = 0;
}

void PrintSequenceList(SequenceList *sequenceList)
{
	if (sequenceList->length)
	{
		for (int cursor = 0; cursor < sequenceList->length; cursor++)
		{
			printf("%d %s \n", sequenceList->heroes[cursor].id, sequenceList->heroes[cursor].name);
		}
	}
	else
	{
		printf("顺序表为空！");
	}
}