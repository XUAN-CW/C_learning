#include <stdio.h>
#include <stdlib.h>
#include "DN_adjMatrix.h"
int main()
{
	Map map;
	if (0 == CreateMap(&map))
	{
		printf("����ʧ��\n");
	}
	else
	{
		PrintMapAdjacency(&map);
	}

	system("pause");
	return 0;
}
