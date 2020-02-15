#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define  NO_OPERATION '\0'

enum direction
{
	UP = 72,			// 上方向
	DOWN = 80,			// 下方向
	LEFT = 75,			// 左方向
	RIGHT = 77			// 右方向
};

/*** 在循环中实时读取字符 **/
char ReadChar();

/** 设置窗体中文字、背景的颜色 */
void SetColor(int color);

/** 设置控制台中光标的位置 */
void SetCurrsorPosition(int x, int y);

/** 设置窗体的大小 */
void SetWindowSize(int width, int height);

/*** 隐藏游标 **/
void disableCurrsor();
