#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** ʹ���ڽӾ����ʾ����������ͼ */
Status CreateUDG(MatrixGraph * G);

/** ����ĳ�������ڶ��㼯���е��±꣨��0��ʼ���������ڷ���UNFOUND */
int LocateVex_UDG(MatrixGraph * G, VerTexType vex);

