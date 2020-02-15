#include <conio.h>
#include "DN_adjMatrix.h"

_Bool CreateMap(Map *map)
{
	
	InputInformationOfVertex(map);
	InitAdjacentMatrix(map);
	if (ERROR == ConstructTheAdjacencyMatrix(map))
	{
		return 0;
	}
	return 1;
}

void InitAdjacentMatrix(Map *map)
{
	for (int i = 0; i < VERTEXES; i++)
	{
		for (int j = 0; j < VERTEXES; j++)
		{
			map->fare[i][j] = 0;
		}
	}
}

void InputInformationOfVertex(Map *map)
{
	printf("输入顶点信息，回车结束输入\n");
	for (int index = 0;;index++)
	{
		map->places[index].name = _getch();
		printf(" %c ", map->places[index].name);
		if ('\r' == map->places[index].name)
		{
			map->vertexCount = index;
			break;
		}
	}
}

_Bool ConstructTheAdjacencyMatrix(Map *map)
{
	Place from;
	Place to;
	for ( map->arcCount = 0; ; map->arcCount++)
	{
		printf("\n出发点：");
		from.name = _getch();
		printf("%c", from.name);
		if ('\r' == from.name)
		{
			break;
		}
		printf("\n终  点：");
		to.name = _getch();
		printf("%c", to.name);
		int x = IndexOfVertexInVertexArray(map, from);
		int y = IndexOfVertexInVertexArray(map, to);
		if (UNFOUND == x || UNFOUND == y)
		{
			return ERROR;
		}
		printf("\n票  价：");
		map->fare[x][y] = _getch() - '0';		//偷个懒，差不多行了
		printf("%d", map->fare[x][y]);
	}
	return OK;
}

int IndexOfVertexInVertexArray(Map *map, Place place)
{
	int i = 0;
	for (; i < map->vertexCount; i++)
	{
		if (place.name == map->places[i].name)
		{
			break;
		}
	}
	if (i == map->vertexCount)
	{
		i = UNFOUND;
	}
	return i;
}

void PrintMapAdjacency(Map *map)
{
	printf("\n打印地图的邻接矩阵：\n");
	printf("   ");
	for (int i = 0; i < map->vertexCount; i++)
	{
		printf("%-3c", map->places[i].name);
	}
	for (int i = 0; i < map->vertexCount; i++)
	{
		printf("\n");
		printf("%-3c", map->places[i].name);
		for (int j = 0; j < map->vertexCount; j++)
		{
			printf("%-3d", map->fare[i][j]);
		}
		
	}
}