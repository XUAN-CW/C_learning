#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TURE 1
#define FALSE 0
#define HERO_MAX 4

/** 定义数据元素 */
typedef struct
{
	int id;
	char name[30];
}Skill;

/** 定义顺序表结构 */
typedef struct
{
	Skill heroes[HERO_MAX];
	int length;
}SequenceList;

/** 初始化线性表 */
void InitSequenceList(SequenceList *sequenceList);

/** 插入元素 */
void InsertElement(SequenceList *sequenceList, Skill *skill, int index);

/** 删除元素并返回被删除的元素 */
Skill DeleteElement(SequenceList *sequenceList, int index);

/** 获取线性表的长度 */
int GetSequenceLength(SequenceList *sequenceList);

/** 判断线性表是否为空，若是，返回 1 */
_Bool IsEmpty(SequenceList *sequenceList);

/** 清空线性表 */
void ClearList(SequenceList *sequenceList);

/** 打印线性表的内容 */
void PrintSequenceList(SequenceList *sequenceList);



