#include "DFS_Function.h"

void DFSTraverse_AMG(MatrixGraph G)
{
	//初始化状态数组
	for (int i = 0; i < G.verTexCount; i++) 
	{
		visited[i] = UNVISITED;     //初始状态设置为未访问
	}

	//DFS遍历
	for (int i = 0; i < G.verTexCount; i++)
	{
		if (!visited[i]) //如果某个顶点未访问
		{
			//调用遍历函数
			DFS_AMG(G, i);
		}
	}
}

void DFS_AMG(MatrixGraph G, int index)
{
	printf(" -> %s", G.verTexs[index]);							//访问顶点A
    visited[index] = VISITED;									//更改顶点A的访问状态
	int currentVex = FirstAdjVex_AMG(G, G.verTexs[index]);		//当前顶点为顶点A的第一个邻接点
	for (currentVex; currentVex;)		//currentVex为0，跳出循环
	{
		if (!visited[currentVex])		//如果没有访问过，就继续递归调用访问
		{
			DFS_AMG(G, currentVex);  
		}
		currentVex = NextAdjVex_AMG(G, G.verTexs[index], G.verTexs[currentVex]);
	}

}

int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex) 
{
	int i = LocateVex(&G, vex);         //找到顶点vex在顶点数组中的下标
	if (i == UNFOUND)
	{
		return ERROR;
	}
	int defaultWeight;									  //默认权重
	defaultWeight = G.kind <= 1 ? 0 : INT_MAX;			  //图/网
	//搜索图的邻接矩阵中与顶点vex的第一个邻接点下标
	for (int j = i + 1; j < G.verTexCount; j++) 
	{
		if (G.arcs[i][j] != defaultWeight)
		{
			return j;
		}
	}
	return 0;
}

int NextAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2) 
{
	int index1 = LocateVex(&G, vex1);
	int index2 = LocateVex(&G, vex2);
	if (index1 == UNFOUND || index2 == UNFOUND)
	{
		return ERROR;
	}
	int defaultWeight;
	defaultWeight = G.kind <= 1 ? 0 : INT_MAX;
	for (int i = index2 + 1; i < G.verTexCount; i++)
	{
		if (G.arcs[index1][i] != defaultWeight) 
		{
			return i;
		}
	}
	return 0;
}

int LocateVex(MatrixGraph * G, VerTexType vex)
{
	int index = UNFOUND;
	for (int i = 0; i < G->verTexCount; i++)
	{
        if(strcmp(G->verTexs[index], vex) == 0)
		{
			index = i;
            break;
        }
	}
	return index;
}

