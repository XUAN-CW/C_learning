#pragma once
#include "UDG_Element.h"

/** �����ڽӱ��ʾ����������ͼ */
Status CreateUDG_AdjList(AdjListGraph * G);

/** ���ض���vex�ڶ��������е��±꣬û���ҵ�����-1 */
int LocateVex_AdjList(AdjListGraph * G, VerTexType vex);
