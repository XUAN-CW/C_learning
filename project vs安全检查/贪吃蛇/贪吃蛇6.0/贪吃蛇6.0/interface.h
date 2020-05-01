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

/*** 画出一块用传入字符填充矩形区域 **/
void DrawRectangleWithChar(COORD topLeft,COORD lowRight, int color, char character);

/*** 画出游戏界面框架 **/
void DrawInterfaceFrame();

/*** 画出信息栏 **/
void DrawInformationBar(Snake *snake);

/*** 游戏开始/游戏模式设置 **/
void Game_and_ModeSetting(Snake *snake, char key);

/*** 进入选中选项 **/
void IntoCurrentSelected(Snake *snake, char currentSelected);

/*** 获取当前信息栏选中选项 **/
int CurrentSelected_InformationBar();

/*** 画出游戏界面 **/
void DrawStartGame(Snake *snake);

/*** 画出模式设置 **/
void DrawModeSetting(Snake *snake);

/*** 设置游戏背景色 **/
void SetGameBackgroundColor();

/*** 设置模式选择背景色 **/
void SetModeSettingBackgroundColor();

