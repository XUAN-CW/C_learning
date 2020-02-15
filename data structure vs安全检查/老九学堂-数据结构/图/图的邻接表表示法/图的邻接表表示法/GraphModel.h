#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OK 1
#define ERROR 0
#define MAX_VERTEX 4
#define VISITED 1
#define UNVISITED 0
#define UNFOUND -1

 /** ͼ������ö�� */
typedef enum 
{
	DG,     //����ͼ   0
	UDG,    //����ͼ   1
	DN,     //������   2
	UDN     //������   3
}GraphKind;

/** ���ö������������Ϊ�ַ����� - ʹ��ʱ�ǵ÷����ڴ� */
typedef char * VerTexType;

/** ����Ȩֵ����Ϊ�������� */
typedef int ArcType;

/** ���ص�״̬���� */
typedef int Status;

/** ����ÿ������ķ���״̬[0-δ���ʣ�1-�ѷ��� */
int visited[MAX_VERTEX];


#endif // GRAPHMODEL_H_INCLUDED
