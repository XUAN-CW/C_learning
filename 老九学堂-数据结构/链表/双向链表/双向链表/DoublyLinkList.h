#ifndef DOUBLYLINKLIST_H_INCLUDED
#define DOUBLYLINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "DataElement.h"

/** 向双向链表中的指定位置插入元素 */
void InsertDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element);

/** 删除并返回双向链表指定位置的元素 */
ElementType DeleteDoubyLinkList(DoublyLinkList * dlList, int pos);

/** 返回双向链表中指定位置的元素值 */
ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos);

/** 返回双向链表中某个结点的前置结点指针 */
DoublyNode * GetDoublyPrveNode(DoublyNode * node);

void PrintDoublyLinkList(DoublyLinkList * dlList);




#endif // DOUBLYLINKLIST_H_INCLUDED
