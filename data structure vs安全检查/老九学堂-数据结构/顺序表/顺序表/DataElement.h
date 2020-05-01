#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 5


//1����������Ԫ��
typedef struct
{
   int id;
   char name[30];
}ElementType;

//2������˳���ṹ
typedef struct{
   ElementType datas[MAX_SIZE];    //˳����е�����Ԫ�ؼ���
   int length;                     //��ǰ˳����е�Ԫ�ظ���
}SeqList;

#endif // DATAELEMENT_H_INCLUDED

