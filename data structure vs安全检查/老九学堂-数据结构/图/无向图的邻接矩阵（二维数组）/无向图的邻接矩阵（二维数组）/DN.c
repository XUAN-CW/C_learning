//#include "DN.h"
//
//Status CreateDN(MatrixGraph * G) 
//{
//	//设置当前创建图的类型为有向网
//	G->kind = DN;      
//
//	printf("请输入有向网的顶点数：");
//	scanf_s("%d", &G->verTexCount);
//
//	printf("请输入边的数量：");
//	scanf_s("%d", &G->arcCount);
//
//	printf("依次输入顶点信息\n");
//	for (int i = 0; i < G->verTexCount; i++) 
//	{
//		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
//		printf("顶点%d：", i + 1);
//		scanf_s("%s", G->verTexs[i],sizeof(G->verTexs[i]));
//	}
//
//	//初始化邻接矩阵，所有边的权值设置为∞
//	for (int i = 0; i < G->verTexCount; i++) 
//	{
//		for (int j = 0; j < G->verTexCount; j++) 
//		{
//			G->arcs[i][j] = INT_MAX;    //使用int_max常量作为无穷大
//		}
//	}
//
//	printf("请输入顶点和邻接顶点信息，构建邻接矩阵\n");
//	for (int i = 0; i < G->arcCount; i++) 
//	{
//		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
//		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
//		printf("顶点：");
//		scanf_s("%s", vex1,sizeof(vex1));
//		printf("邻接点：");
//		scanf_s("%s", vex2,sizeof(vex2));
//		//分别获得两个顶点在顶点数组中的坐标
//		int x = LocateVex_DN(G, vex1);
//		int y = LocateVex_DN(G, vex2);
//		if (x == UNFOUND || y == UNFOUND)
//		{
//			return ERROR;
//		}
//		int value;
//		printf("请输入权值：");
//		scanf_s("%d", &value);
//		G->arcs[x][y] = value;
//		free(vex1);
//		free(vex2);
//	}
//	return OK;
//}
//
//int LocateVex_DN(MatrixGraph * G, VerTexType vex)
//{
//	int index = 0;
//	while (index < G->verTexCount)
//	{
//		if (strcmp(G->verTexs[index], vex) == 0)
//		{
//			break;
//		}
//		index++;
//	}
//	return index == G->verTexCount ? UNFOUND : index;
//}