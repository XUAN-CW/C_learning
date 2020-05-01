#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TURE 1
#define FALSE 0
#define HERO_MAX 4

/** ��������Ԫ�� */
typedef struct
{
	int id;
	char name[30];
}Skill;

/** ����˳���ṹ */
typedef struct
{
	Skill heroes[HERO_MAX];
	int length;
}SequenceList;

/** ��ʼ�����Ա� */
void InitSequenceList(SequenceList *sequenceList);

/** ����Ԫ�� */
void InsertElement(SequenceList *sequenceList, Skill *skill, int index);

/** ɾ��Ԫ�ز����ر�ɾ����Ԫ�� */
Skill DeleteElement(SequenceList *sequenceList, int index);

/** ��ȡ���Ա�ĳ��� */
int GetSequenceLength(SequenceList *sequenceList);

/** �ж����Ա��Ƿ�Ϊ�գ����ǣ����� 1 */
_Bool IsEmpty(SequenceList *sequenceList);

/** ������Ա� */
void ClearList(SequenceList *sequenceList);

/** ��ӡ���Ա������ */
void PrintSequenceList(SequenceList *sequenceList);



