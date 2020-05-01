#include "UDG.h"


//无向图的特点：
//1、无向图的邻接矩阵是对称
//2、顶点i的度 = 第i行(列)中1的个数
Status CreateUDG(MatrixGraph * G) 
{
	G->kind = UDG;      //设置当前创建图的类型为无向图

	printf("请输入无向图的顶点数：");
	scanf_s("%d", &G->verTexCount);
	printf("请输入边的数量：");
	scanf_s("%d", &G->arcCount);

	printf("依次输入顶点信息\n");
	for (int i = 0; i < G->verTexCount; i++) 
	{
		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
		printf("顶点%d：", i + 1);
		scanf_s("%s", G->verTexs[i],sizeof(G->verTexs[i]));
	}

	//初始化邻接矩阵，所有边的权值设置为0
	for (int i = 0; i < G->verTexCount; i++) 
	{
		for (int j = 0; j < G->verTexCount; j++) 
		{
			G->arcs[i][j] = 0;
		}
	}

	printf("请输入顶点和邻接顶点信息，构建邻接矩阵\n");
	for (int i = 0; i < G->arcCount; i++)
	{
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
		printf("顶点：");
		scanf_s("%s", vex1,sizeof(vex1));
		printf("邻接点：");
		scanf_s("%s", vex2,sizeof(vex2));
		//分别获得两个顶点在顶点数组中的坐标
		int x = LocateVex_UDG(G, vex1);
		int y = LocateVex_UDG(G, vex2);
		if (x == UNFOUND || y == UNFOUND)
		{
			return ERROR;
		}
		G->arcs[x][y] = 1;
		G->arcs[y][x] = G->arcs[x][y];      //无向图的邻接矩阵是对称的

		free(vex1);
		free(vex2);
	}

	return OK;
}



int LocateVex_UDG(MatrixGraph * G, VerTexType vex) 
{
	int index = 0;
	while (index < G->verTexCount) 
	{
		if (strcmp(G->verTexs[index], vex) == 0) 
		{
			break;
		}
		index++;
	}
	return index == G->verTexCount ? UNFOUND : index;
}
