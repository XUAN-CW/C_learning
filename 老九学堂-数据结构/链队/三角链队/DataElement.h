#pragma once
#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define NAME 30
#define TRUE 1
#define FALSE 0

//����Ԫ��
typedef struct {
	int id;
	char name[NAME];
}ElementType;


// ���ӵĽ��
typedef struct LinkQueueNode {
	ElementType data;           //������
	struct LinkQueueNode * next; //ָ���¸�����ָ����
}LinkQueueNode;

// ���ӵĽṹ
typedef struct CircularLinkList {
	LinkQueueNode * front;        //ָ���һ������ָ�룬ͷָ��
	LinkQueueNode * rear;        //ָ���һ������ָ�룬ͷָ��
	int length;
}LinkQueue;



#endif // DATAELEMENT_H_INCLUDED
