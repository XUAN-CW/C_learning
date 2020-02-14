#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/** ��˫�������е�ָ��λ�ò���Ԫ�� */
void InsertDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element);

/** ɾ��������˫������ָ��λ�õ�Ԫ�� */
ElementType DeleteDoubyLinkList(DoublyLinkList * dlList, int pos);

/** ����˫��������ָ��λ�õ�Ԫ��ֵ */
ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos);

/** ����˫��������ĳ������ǰ�ý��ָ�� */
DoublyNode * GetDoublyPrveNode(DoublyNode * node);

void PrintDoublyLinkList(DoublyLinkList * dlList);




#endif // DOUBLYLINKLIST_H_INCLUDED
