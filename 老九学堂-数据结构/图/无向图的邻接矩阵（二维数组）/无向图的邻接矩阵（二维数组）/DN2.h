#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphModel.h"

/** ʹ���ڽӾ����ʾ������������ */
Status CreateDN2(MatrixGraph * G);

/** ����ĳ�������ڶ��㼯���е��±꣨��0��ʼ���������ڷ���UNFOUND */
int LocateVex_DN2(MatrixGraph * G, VerTexType vex);