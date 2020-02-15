#include "UDG.h"

Status CreateUDG_AdjList(AdjListGraph * G) 
{
	G->kind = UDG;

	printf("请输入顶点数量：");
	scanf_s("%d", &G->vexCount);
	printf("请输入边的数量：");
	scanf_s("%d", &G->edgeCount);

	printf("请依次输入顶点信息\n");
	for (int i = 0; i < G->vexCount; i++) 
	{
		G->vexes[i].vex = (VerTexType)malloc(sizeof(char) * 10);
		//初始化邻接表，把边置空
		G->vexes[i].firstEdge = NULL;
		printf("顶点%d：", i + 1);
		scanf_s("%s", G->vexes[i].vex,sizeof(G->vexes[i].vex));
	}

	printf("请输入顶点和邻接点信息，构建邻接表\n");
	for (int i = 0; i < G->edgeCount; i++) 
	{
		//给顶点数据域分配空间
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);

		printf("顶点：");
		scanf_s("%s", vex1,sizeof(vex1));
		printf("邻接点：");
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
		//边结点E指向顶点V
		edgeNode->adjVex = vertexIndex;
		//边结点E指向邻接A的第一条边
		edgeNode->nextEdge = G->vexes[adjVexIndex].firstEdge;
		//邻接点A第一条边指向边结点E
		G->vexes[adjVexIndex].firstEdge = edgeNode;

		//边结点E重新分配空间，为了区别上面的边结点，称为新的边结点为Ed
		edgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
		//边结点Ed指向邻接点A
		edgeNode->adjVex = adjVexIndex;
		//边结点Ed指向顶点A的第一条边
		edgeNode->nextEdge = G->vexes[vertexIndex].firstEdge;
		//顶点A第一条边指向边结点Ed
		G->vexes[vertexIndex].firstEdge = edgeNode;

		free(vex1);
		free(vex2);
	}
	//边结点可能重复，可增加一个查重函数
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
