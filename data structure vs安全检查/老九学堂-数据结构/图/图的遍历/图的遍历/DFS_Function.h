#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** �ڽӾ����������ȱ��� */
void DFSTraverse_AMG(MatrixGraph G);

/** ������������ĺ����㷨��indexΪ���������ĳ�������±� */
void DFS_AMG(MatrixGraph G, int index);

/** ���ض���vex�������еĵ�һ���ڽӵ��±� */
int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex);

/** �����붥��vex1�ڽӵ���һ���ڽӵ㣬û�оͷ���0 */
int NextAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2);

/** ����ĳ�������ڶ��㼯���е��±꣨��0��ʼ���������ڷ���-1 */
int LocateVex(MatrixGraph * G, VerTexType vex);