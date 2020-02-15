#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define NAME 30
#define TRUE 1
#define FALSE 0

typedef struct {
	int id;
	char name[NAME];
}ElementType;


// 循环链表的结点 
typedef struct CircularNode{
    ElementType data;           //数据域
    struct CircularNode * next; //指向下个结点的指针域
}CircularNode;

// 循环链表结构 
typedef struct CircularLinkList{
    CircularNode * next;        //指向第一个结点的指针，头指针
    int length;
}CircularLinkList;



#endif // DATAELEMENT_H_INCLUDED
