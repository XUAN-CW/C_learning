#include <stdio.h>
#include <stdlib.h>
#include "DN_adjMatrix.h"
int main()
{
	Map map;
	if (0 == CreateMap(&map))
	{
		printf("´´½¨Ê§°Ü\n");
	}
	else
	{
		PrintMapAdjacency(&map);
	}

	system("pause");
	return 0;
}
