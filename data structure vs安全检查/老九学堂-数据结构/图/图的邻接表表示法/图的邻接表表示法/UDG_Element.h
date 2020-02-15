#pragma once

#include "GraphModel.h"


/** 边的结点 */
typedef struct node
{
	int adjVex;                     //该边指向这条边邻接点的下标
	struct node * nextEdge;         //指向下一条边结点的指针
}EdgeNode;

/** 顶点结点 */
typedef struct vexNode
{
	VerTexType vex;                 //顶点数据
	EdgeNode * firstEdge;           //指向第一条边的指针
}VNode, AdjList;

/** 邻接表实现的图结构 */
typedef struct adjGraph
{
	AdjList vexes[MAX_VERTEX];		//顶点数组
	int vexCount;                   //顶点数量
	int edgeCount;                  //图的边数
	GraphKind kind;                 //图的类型
}AdjListGraph;
