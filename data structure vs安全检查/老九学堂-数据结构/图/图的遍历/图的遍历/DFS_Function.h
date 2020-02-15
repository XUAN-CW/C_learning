#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** 邻接矩阵的深度优先遍历 */
void DFSTraverse_AMG(MatrixGraph G);

/** 深度优先搜索的核心算法，index为深度搜索的某个顶点下标 */
void DFS_AMG(MatrixGraph G, int index);

/** 返回顶点vex所在行中的第一个邻接点下标 */
int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex);

/** 返回与顶点vex1邻接的另一个邻接点，没有就返回0 */
int NextAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2);

/** 返回某个顶点在顶点集合中的下标（从0开始），不存在返回-1 */
int LocateVex(MatrixGraph * G, VerTexType vex);