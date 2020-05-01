#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "snake.h"

typedef struct _control_panel
{
	char name[64];
	int defaultColor;
	int selectedColor;
	_Bool selected;
}Option;

/*** ����һ���ô����ַ����������� **/
void DrawRectangleWithChar(COORD topLeft,COORD lowRight, int color, char character);

/*** ������Ϸ������ **/
void DrawInterfaceFrame();

/*** ������Ϣ�� **/
void DrawInformationBar(Snake *snake);

/*** ��Ϸ��ʼ/��Ϸģʽ���� **/
void Game_and_ModeSetting(Snake *snake, char key);

/*** ����ѡ��ѡ�� **/
void IntoCurrentSelected(Snake *snake, char currentSelected);

/*** ��ȡ��ǰ��Ϣ��ѡ��ѡ�� **/
int CurrentSelected_InformationBar();

/*** ������Ϸ���� **/
void DrawStartGame(Snake *snake);

/*** ����ģʽ���� **/
void DrawModeSetting(Snake *snake);

/*** ������Ϸ����ɫ **/
void SetGameBackgroundColor();

/*** ����ģʽѡ�񱳾�ɫ **/
void SetModeSettingBackgroundColor();

