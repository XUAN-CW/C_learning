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


// ѭ������Ľ�� 
typedef struct CircularNode{
    ElementType data;           //������
    struct CircularNode * next; //ָ���¸�����ָ����
}CircularNode;

// ѭ������ṹ 
typedef struct CircularLinkList{
    CircularNode * next;        //ָ���һ������ָ�룬ͷָ��
    int length;
}CircularLinkList;



#endif // DATAELEMENT_H_INCLUDED
