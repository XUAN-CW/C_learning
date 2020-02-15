
#ifndef CIRCULARLINKLIST_H_INCLUDED
#define CIRCULARLINKLIST_H_INCLUDED

/************************************************************************
 *  Project: ���ݽṹ�ڶ���ѭ������ʾ��
 *  Function: ѭ�����������ص���β����ָ����ָ���һ�����
 *  Description:�ŵ����ܹ�ͨ�������������������ṹ
 *  Author: ��ͷ
 ************************************************************************
 *  Copyright 2018 by �Ͼ�ѧ��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"


/** ��ѭ�������ָ��λ�ò���Ԫ�� */
void InsertCircularLinkList(CircularLinkList * clList, int position, ElementType element);

void InitCircularLinkList(CircularLinkList * clList, ElementType * dataArray, int length);

/** ����Ԫ�����ݷ��ض�Ӧ�Ľ��ָ�� */
CircularNode * GetCircularLinkListNode(CircularLinkList * clList, ElementType element);

/** ɾ��������ѭ��������ָ��λ�õ�Ԫ�� */
ElementType DeleteCircularLinkList(CircularLinkList * clList, int position);

/** ͨ��������ĳ����㣬ѭ�������������е�ÿ��Ԫ�� */
void PrintCircularLinkListByNode(CircularLinkList * clList, CircularNode * node);

void PrintCircularLinkList(CircularLinkList * clList);


#endif // CIRCULARLINKLIST_H_INCLUDED
