#include <stdio.h>
#include <stdlib.h>
#include "UDG.h"
#include "DN.h"
#include "DN2.h"
void UDGMatrixGraph();
void DNMatrixGraph();

int main()
{
	//UDGMatrixGraph();
	DNMatrixGraph();
	system("pause");
    return 0;
}

void UDGMatrixGraph()
{
	MatrixGraph G;
	//创建无向图
	Status status = CreateUDG(&G);
	if(status == ERROR)
	{
	    printf("创建图失败，请检查后重试！\n");
	}
	else
	{
		printf("打印图的邻接矩阵：\n");

		printf("\t");
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
		}

		printf("\n");

		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
			for (int j = 0; j < G.verTexCount; j++)
			{
					printf("\t%d", G.arcs[i][j]);
			}
			printf("\n");
		}
	}
    
}

void DNMatrixGraph()
{
	MatrixGraph G;
	//创建无向图
	//Status status = CreateDN(&G);
	Status status = CreateDN2(&G);
	/*** 
	 * 问题：
		Status status = CreateDN(&G);		-------无法解析的外部符号 _CreateDN
		Status status = CreateDN2(&G);		-------可行
	 * 解决方法：新建一个 .c和.h文件，换个函数名，复制粘贴函数里的内容即可
	   另：查看文件是否为同类型文件，如 main.cpp、DN.c  需将 main.cpp 改成 main.c
	 */

	if (status == ERROR)
	{
		printf("创建图失败，请检查后重试！\n");
	}
	else
	{
		printf("打印图的邻接矩阵：\n");
	
		printf("\t");
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
		}
	
		printf("\n");
	
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
			for (int j = 0; j < G.verTexCount; j++)
			{
				if (G.arcs[i][j] == INT_MAX) 
				{
					printf("\t∞");
				}
				else 
				{
					printf("\t%d", G.arcs[i][j]);
				}
			}
			printf("\n");
		}
	}
}