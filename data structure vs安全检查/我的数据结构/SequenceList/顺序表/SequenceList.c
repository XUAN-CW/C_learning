
#include "SequenceList.h"

void InitSequenceList(SequenceList *sequenceList)
{
	sequenceList->length = 0;
}

void InsertElement(SequenceList *sequenceList, Skill *skill, int index)
{
	//�ж������Ƿ�����
	if (sequenceList->length == HERO_MAX)
	{
		printf("��������,����ʧ�ܣ�\n");
		return;
	}
	//�ж�index�Ƿ��� [ 0, HERO_MAX - 1 ] ��
	if (index < 0 || index > HERO_MAX - 1)
	{
		printf("�����������Χ������ʧ�ܣ�\n");
		return;
	}
	//indexӦ�� [ 0, length ] ֮��
	if (index > sequenceList->length)
	{
		printf("��ǰֻ����[ 0, %d ]�ڲ���Ԫ��!,����ʧ�ܣ�\n", sequenceList->length);
		return;
	}
	//ǰһ�����Ǻ�һ������ index ��������Ԫ�ظ��ǣ��ﵽ����Ч��
	for (int cursor = sequenceList->length - 1; cursor >= index; cursor--)
	{
		sequenceList->heroes[cursor + 1] = sequenceList->heroes[cursor];
	}
	sequenceList->heroes[index] = *skill;
	//�ܳ���++ ������
	sequenceList->length++;
}

Skill DeleteElement(SequenceList *sequenceList, int index)
{
	//indexӦ�� [ 0, length - 1 ] ֮��
	if (index > sequenceList->length)
	{
		printf("��ǰֻ��ɾ��[ 0, %d ]�ڵ�Ԫ�أ�ɾ��ʧ�ܣ�\n", sequenceList->length - 1);
		Skill unfound = { 0,"0" };
		return unfound;
	}
	Skill deletedElement = sequenceList->heroes[index];
	//��ɾ����Ԫ�ر�����,��һ��Ԫ�ظ���ǰһ��Ԫ�أ��ﵽǰ��Ч��
	for (int cursor = index; cursor < sequenceList->length - 1; cursor++)
	{
		sequenceList->heroes[cursor] = sequenceList->heroes[cursor + 1];
	}
	//�ܳ���-- !!!
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
		printf("˳���Ϊ�գ�");
	}
}