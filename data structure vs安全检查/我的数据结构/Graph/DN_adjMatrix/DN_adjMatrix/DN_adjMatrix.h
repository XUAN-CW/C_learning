#pragma once
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define VERTEXES 8		//顶点数目
#define UNFOUND -1


/** 定义顶点类型 */
typedef struct _place_
{
	char name;								//偷个懒，地点名字用ABC表示得了
	int population;							//这一部分不录入了，它的意义就是为了让 Place 丰满一点
}Place;

/** 图的邻接矩阵存储表示 */
typedef struct _map_
{
	int vertexCount;						//顶点数
	int arcCount;							//弧数
	Place places[VERTEXES];					//顶点数组
	int fare[VERTEXES][VERTEXES];			//权数组（邻接矩阵）
}Map;

/** 创建地图,构建失败返回 0 */
_Bool CreateMap(Map *map);

/** 输入顶点信息，回车结束输入 */
void InputInformationOfVertex(Map *map);

/** 初始化邻接矩阵，将其中元素设置为 0 */
void InitAdjacentMatrix(Map *map);

/** 构建邻接矩阵,构建失败返回 ERROR */
_Bool ConstructTheAdjacencyMatrix(Map *map);

/** 返回顶点在顶点数组中的下标 */
int IndexOfVertexInVertexArray(Map *map, Place place);

/** 打印地图邻接矩阵 */
void PrintMapAdjacency(Map *map);

