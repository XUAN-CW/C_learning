#pragma once
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define VERTEXES 8		//������Ŀ
#define UNFOUND -1


/** ���嶥������ */
typedef struct _place_
{
	char name;								//͵�������ص�������ABC��ʾ����
	int population;							//��һ���ֲ�¼���ˣ������������Ϊ���� Place ����һ��
}Place;

/** ͼ���ڽӾ���洢��ʾ */
typedef struct _map_
{
	int vertexCount;						//������
	int arcCount;							//����
	Place places[VERTEXES];					//��������
	int fare[VERTEXES][VERTEXES];			//Ȩ���飨�ڽӾ���
}Map;

/** ������ͼ,����ʧ�ܷ��� 0 */
_Bool CreateMap(Map *map);

/** ���붥����Ϣ���س��������� */
void InputInformationOfVertex(Map *map);

/** ��ʼ���ڽӾ��󣬽�����Ԫ������Ϊ 0 */
void InitAdjacentMatrix(Map *map);

/** �����ڽӾ���,����ʧ�ܷ��� ERROR */
_Bool ConstructTheAdjacencyMatrix(Map *map);

/** ���ض����ڶ��������е��±� */
int IndexOfVertexInVertexArray(Map *map, Place place);

/** ��ӡ��ͼ�ڽӾ��� */
void PrintMapAdjacency(Map *map);

