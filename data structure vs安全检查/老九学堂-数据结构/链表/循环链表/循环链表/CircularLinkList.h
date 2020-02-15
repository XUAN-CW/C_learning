
#ifndef CIRCULARLINKLIST_H_INCLUDED
#define CIRCULARLINKLIST_H_INCLUDED

/************************************************************************
 *  Project: 数据结构第二章循环链表示例
 *  Function: 循环链表最大的特点是尾结点的指针域指向第一个结点
 *  Description:优点是能够通过任意结点遍历整个链表结构
 *  Author: 窖头
 ************************************************************************
 *  Copyright 2018 by 老九学堂
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/** 在循环链表的指定位置插入元素 */
void InsertCircularLinkList(CircularLinkList * clList, int position, ElementType element);

void InitCircularLinkList(CircularLinkList * clList, ElementType * dataArray, int length);

/** 根据元素内容返回对应的结点指针 */
CircularNode * GetCircularLinkListNode(CircularLinkList * clList, ElementType element);

/** 删除并返回循环链表中指定位置的元素 */
ElementType DeleteCircularLinkList(CircularLinkList * clList, int position);

/** 通过给定的某个结点，循环遍历出链表中的每个元素 */
void PrintCircularLinkListByNode(CircularLinkList * clList, CircularNode * node);

void PrintCircularLinkList(CircularLinkList * clList);


#endif // CIRCULARLINKLIST_H_INCLUDED
