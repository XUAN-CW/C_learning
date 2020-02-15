#pragma once
#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/***************************************************
 * �ļ�����GameLib.h
 * ��  ��������������Ϸ�г��õ�ϵͳ����������������ɫ�������ȣ�
 * �����ˣ��Ͼ�ѧ�á���ͷ
 * ��  �ڣ�2016-11-10
 * ��  ����1.0
 * ��  ����http://www.xuetang9.com
 * �ٷ�QQ��614940318���Ͼž���
 *
 **************************************************/
#include <stdio.h>
#include <windows.h>


/* �������ֵ�ǰ��ɫ�ͱ���ɫ */
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(int foreColor, int backColor);
/* ���ù���λ�� */
void SetPosition(int x, int y);
/* ��x��y���꿪ʼ����rowCount�� */
void Clear(int x, int y, int rowCount);

void ShowWelcome();

#define SEP "------------------------------------------------------------------------------"
#define COL 78                  //��Ϸ������ܿ��
#define MARGIN_X 20             //��߾�
#define MAP_START_Y 3           //��ͼ��ʼ��Y����
#define MAP_END_Y   11          //��ͼ������Y����
#define INFO_START_Y 12         //��Ϣ���濪ʼ��Y����
#define INFO_END_Y 19           //��Ϣ����Ľ���Y����
#define MAINMENU_START_Y 20     //���˵���ʼ��Y����

void ShowInfomation();
void ShowMainMenu();
void Show();//��ʾȫ������
void ShowMap();

#endif // GAMELIB_H_INCLUDED
