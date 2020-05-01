#pragma once
#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define NAME 30
#define TRUE 1
#define FALSE 0

//数据元素
typedef struct {
	int id;
	char name[NAME];
}ElementType;


// 链队的结点
typedef struct LinkQueueNode {
	ElementType data;           //数据域
	struct LinkQueueNode * next; //指向下个结点的指针域
}LinkQueueNode;

// 链队的结构
typedef struct CircularLinkList {
	LinkQueueNode * front;        //指向第一个结点的指针，头指针
	LinkQueueNode * rear;        //指向第一个结点的指针，头指针
	int length;
}LinkQueue;



#endif // DATAELEMENT_H_INCLUDED
