#pragma once

#define NAME 30

/** ��������Ԫ�� */
typedef struct _element_
{
	int id;
	char name[NAME];
}Element;

/** ��������Ľ�� */
typedef struct Node				//_node_ ���� Node ��������Ͳ�����
{
	Element data;				//������
	struct Node *next;			//ָ����
}Node;

/** ����ͷ��� */
typedef struct _linked_list_
{
	Node *firstNode;			//��Ԫ���
	int length;					//������
}LinkedList;



/** ��ʼ������ */
void InitLinkedList(LinkedList *linkedList);

/** �������в���Ԫ��,����ʧ�ܷ��� false */
_Bool InserElementToLinkedList(LinkedList *linkedList, Element element, int position);

/** ɾ�������еĵ� position ��Ԫ��,ɾ��ʧ�ܷ��� false */
_Bool DeleteEelementOfLinkedList(LinkedList *linkedList, int position);

/** ��ȡ�� position ��Ԫ�ز�������ָ�� */
Element *GetLinkedListElement(LinkedList *linkedList, int position);

/** ������� */
void ClearLinkedList(LinkedList *linkedList);

/** �ж������Ƿ�Ϊ�� */
_Bool IsEmptyOfLinkedList(LinkedList *linkedList);

/** ��ȡ���ӳ��� */
int GetLinkedListLength(LinkedList *linkedList);

/** ��ӡ�����е����� */
void PrintLinkedList(LinkedList *linkedList);