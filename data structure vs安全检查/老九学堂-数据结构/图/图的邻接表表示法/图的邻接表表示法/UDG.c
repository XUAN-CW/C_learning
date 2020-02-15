#include "UDG.h"

Status CreateUDG_AdjList(AdjListGraph * G) 
{
	G->kind = UDG;

	printf("�����붥��������");
	scanf_s("%d", &G->vexCount);
	printf("������ߵ�������");
	scanf_s("%d", &G->edgeCount);

	printf("���������붥����Ϣ\n");
	for (int i = 0; i < G->vexCount; i++) 
	{
		G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
		//��ʼ���ڽӱ��ѱ��ÿ�
		G->vexes[i].firstEdge = NULL;
		printf("����%d��", i + 1);
		scanf_s("%s", G->vexes[i].vex,sizeof(G->vexes[i].vex));
	}

	printf("�����붥����ڽӵ���Ϣ�������ڽӱ�\n");
	for (int i = 0; i < G->edgeCount; i++) 
	{
		//���������������ռ�
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);

		printf("���㣺");
		scanf_s("%s", vex1,sizeof(vex1));
		printf("�ڽӵ㣺");
		scanf_s("%s", vex2,sizeof(vex2));

		int vertexIndex = LocateVex_AdjList(G, vex1);
		int adjVexIndex = LocateVex_AdjList(G, vex2);
		if (vertexIndex == UNFOUND || adjVexIndex == UNFOUND)
		{
			free(vex1);
			free(vex2);
			return ERROR;
		}

		EdgeNode * edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
		//�߽��Eָ�򶥵�V
		edgeNode->adjVex = vertexIndex;
		//�߽��Eָ���ڽ�A�ĵ�һ����
		edgeNode->nextEdge = G->vexes[adjVexIndex].firstEdge;
		//�ڽӵ�A��һ����ָ��߽��E
		G->vexes[adjVexIndex].firstEdge = edgeNode;

		//�߽��E���·���ռ䣬Ϊ����������ı߽�㣬��Ϊ�µı߽��ΪEd
		edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
		//�߽��Edָ���ڽӵ�A
		edgeNode->adjVex = adjVexIndex;
		//�߽��Edָ�򶥵�A�ĵ�һ����
		edgeNode->nextEdge = G->vexes[vertexIndex].firstEdge;
		//����A��һ����ָ��߽��Ed
		G->vexes[vertexIndex].firstEdge = edgeNode;

		free(vex1);
		free(vex2);
	}
	//�߽������ظ���������һ�����غ���
	return OK;
}

int LocateVex_AdjList(AdjListGraph * G, VerTexType vex) 
{
	int index = UNFOUND;
	for (int i = 0; i < G->vexCount; i++) 
	{
		if (strcmp(vex, G->vexes[i].vex) == 0) 
		{
			index = i;
			break;
		}
	}
	return index;
}
