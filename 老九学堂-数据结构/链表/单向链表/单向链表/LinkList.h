#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"

void InitLinkList(LinkList * linkList, ElementType * dataArray, int length);

void InsertLinkList(LinkList * linkList, int pos, ElementType insertElement);

ElementType GetLinkListElement(LinkList * linkList, int pos);

void ClearLinkList(LinkList * linkList);

ElementType DeleteLinkListElement(LinkList * linkList, int pos);

int IsLinkListEmpty(LinkList * linkList);

void PrintLinkList(LinkList * linkList);

#endif // LINKLIST_H_INCLUDED


