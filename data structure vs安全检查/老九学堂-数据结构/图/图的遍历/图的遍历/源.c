#include <stdio.h>
#include <stdlib.h>
#include "DFS_Function.h"
#include "DN2.h"

int main()
{

	MatrixGraph G;
	//创建有向网
	Status status = CreateDN2(&G);
	//有向网的深度优先搜索
	DFSTraverse_AMG(G);

	system("pause");
	return 0;
}