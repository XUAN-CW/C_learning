#include <stdio.h>
#include <stdlib.h>
#include "DFS_Function.h"
#include "DN2.h"

int main()
{

	MatrixGraph G;
	//����������
	Status status = CreateDN2(&G);
	//�������������������
	DFSTraverse_AMG(G);

	system("pause");
	return 0;
}