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

 //˫������Ľ��
 typedef struct DoublyNode {
	 ElementType data;
	 struct DoublyNode * prev;   //ָ��ǰ׺���
	 struct DoublyNode * next;   //ָ���̽��
 }DoublyNode;

 //˫������ͷ���
 typedef struct DoublyLinkList {
	 int length;
	 DoublyNode * next;
 }DoublyLinkList;


#endif // DATAELEMENT_H_INCLUDED
