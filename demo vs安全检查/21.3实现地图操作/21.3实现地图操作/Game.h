#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/***************************************************
 * �ļ�����Game.h
 * ��  ��������������Ϸ��һЩ���Ľṹ�ͺ���
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2016-11-10
 * ��  ����1.0
 * ��  ����http://www.xuetang9.com
 * �ٷ�QQ��614940318���Ͼž���
 *
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

 /*********************  ��Ϸ�Ľṹ���Ͷ���   *******************************/

 //��ҡ���ͼ��װ��������
 /* ��Ϸ��ͼ�ṹ ��Ϸ��ͼ
   ��š����ơ����ܡ���ҵĽ���ȼ� */
typedef struct _map {
	int id;         //��ͼ���
	char name[50];  //��ͼ����
	int minLevel;   //��ҽ������͵ȼ�
	//����ṹ
	COORD coord;    //��ͼ������
	char desc[500]; //��ͼ�Ľ���
}Map;



#endif // GAME_H_INCLUDED
