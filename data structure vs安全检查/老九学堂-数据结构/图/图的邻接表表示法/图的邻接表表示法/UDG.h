#pragma once
#include "UDG_Element.h"

/** 采用邻接表表示法创建无向图 */
Status CreateUDG_AdjList(AdjListGraph * G);

/** 返回顶点vex在顶点数组中的下标，没有找到返回-1 */
int LocateVex_AdjList(AdjListGraph * G, VerTexType vex);
