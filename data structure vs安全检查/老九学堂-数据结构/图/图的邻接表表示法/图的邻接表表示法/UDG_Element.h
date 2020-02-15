#pragma once

#include "GraphModel.h"


/** �ߵĽ�� */
typedef struct node
{
	int adjVex;                     //�ñ�ָ���������ڽӵ���±�
	struct node * nextEdge;         //ָ����һ���߽���ָ��
}EdgeNode;

/** ������ */
typedef struct vexNode
{
	VerTexType vex;                 //��������
	EdgeNode * firstEdge;           //ָ���һ���ߵ�ָ��
}VNode, AdjList;

/** �ڽӱ�ʵ�ֵ�ͼ�ṹ */
typedef struct adjGraph
{
	AdjList vexes[MAX_VERTEX];		//��������
	int vexCount;                   //��������
	int edgeCount;                  //ͼ�ı���
	GraphKind kind;                 //ͼ������
}AdjListGraph;
