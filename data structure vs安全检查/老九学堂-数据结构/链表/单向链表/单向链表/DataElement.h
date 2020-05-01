#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

 #define MAX_SIZE 5
#define NAME 20
 #define TRUE 1
 #define FALSE 0

 //定义数据元素
 typedef struct{
    int id;
    char name[NAME];
 }ElementType;

 /** 定义链表的结点 */
 typedef struct Node {
	 ElementType data;   //数据域
	 struct Node * next; //指针域，指向下个结点
 }Node;

 /**
  * 头结点
  * 注意：我们在定义链表时，习惯性的会定义头结点，以便统一链表结点的插入和删除操作
  * 头结点也可以称为首元结点，最后一个结点叫做尾元结点
  */
 typedef struct LinkList {
	 Node * next;        //头指针（如果链表有头结点，next就指向头结点；没有就指向第一个结点）
	 int length;         //链表的长度，初始值为0
 }LinkList;

#endif // DATAELEMENT_H_INCLUDED
