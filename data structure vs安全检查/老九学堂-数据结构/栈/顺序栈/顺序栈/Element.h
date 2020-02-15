#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0
#define WHITE 1
#define BLACK 2

//����ջ��Ԫ��
typedef struct {
	int id;
	char name[20];
}ElementType;


//����ջ��˳��洢��ʽ 
typedef struct SeqStack {
	ElementType elements[MAX_SIZE]; //˳��ջ�������������Ԫ�ص�����
	int top;                        //ջ���������е��±꣩�����Ϊ-1��֤��ջΪ��
	int length;                     //��ǰջ��Ԫ�ظ���
}SeqStack;


#endif // ELEMENT_H_INCLUDED
