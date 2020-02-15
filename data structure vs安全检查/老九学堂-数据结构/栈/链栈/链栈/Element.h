#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0

//����ջ��Ԫ��
typedef struct {
	int id;
	char name[20];
}ElementType;

//��ջ�Ľ�� 
typedef struct StackNode {
	ElementType data;           //����б����Ԫ��
	struct StackNode * next;    //ָ���¸�����ָ��
}StackNode;

//
typedef struct LinkedStack {
	StackNode * top;            //ջ��ָ��
	int length;                 //��ջ�ĳ��ȣ�Ԫ�ظ�����
}LinkedStack;

#endif // ELEMENT_H_INCLUDED
