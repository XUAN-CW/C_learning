#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

 #define MAX_SIZE 5
 #define NAME 20
 #define TRUE 1
 #define FALSE 0

 typedef struct{
    int id;
    char name[NAME];
 }ElementType;

 //双向链表的结点
 typedef struct DoublyNode {
	 ElementType data;
	 struct DoublyNode * prev;   //指向前缀结点
	 struct DoublyNode * next;   //指向后继结点
 }DoublyNode;

 //双向链表头结点
 typedef struct DoublyLinkList {
	 int length;
	 DoublyNode * next;
 }DoublyLinkList;


#endif // DATAELEMENT_H_INCLUDED
