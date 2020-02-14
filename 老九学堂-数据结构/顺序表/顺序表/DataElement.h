#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 5


//1、定义数据元素
typedef struct
{
   int id;
   char name[30];
}ElementType;

//2、定义顺序表结构
typedef struct{
   ElementType datas[MAX_SIZE];    //顺序表中的数据元素集合
   int length;                     //当前顺序表中的元素个数
}SeqList;

#endif // DATAELEMENT_H_INCLUDED

