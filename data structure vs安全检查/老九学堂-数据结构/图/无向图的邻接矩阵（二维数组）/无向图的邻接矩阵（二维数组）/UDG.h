#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** 使用邻接矩阵表示法创建无向图 */
Status CreateUDG(MatrixGraph * G);

/** 返回某个顶点在顶点集合中的下标（从0开始），不存在返回UNFOUND */
int LocateVex_UDG(MatrixGraph * G, VerTexType vex);

