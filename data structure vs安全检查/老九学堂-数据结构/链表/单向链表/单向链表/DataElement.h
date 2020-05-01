#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

 #define MAX_SIZE 5
#define NAME 20
 #define TRUE 1
 #define FALSE 0

 //��������Ԫ��
 typedef struct{
    int id;
    char name[NAME];
 }ElementType;

 /** ��������Ľ�� */
 typedef struct Node {
	 ElementType data;   //������
	 struct Node * next; //ָ����ָ���¸����
 }Node;

 /**
  * ͷ���
  * ע�⣺�����ڶ�������ʱ��ϰ���ԵĻᶨ��ͷ��㣬�Ա�ͳһ������Ĳ����ɾ������
  * ͷ���Ҳ���Գ�Ϊ��Ԫ��㣬���һ��������βԪ���
  */
 typedef struct LinkList {
	 Node * next;        //ͷָ�루���������ͷ��㣬next��ָ��ͷ��㣻û�о�ָ���һ����㣩
	 int length;         //����ĳ��ȣ���ʼֵΪ0
 }LinkList;

#endif // DATAELEMENT_H_INCLUDED
