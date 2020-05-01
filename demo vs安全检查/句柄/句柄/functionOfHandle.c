#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "functionOfHandle.h"

void Test_SetConsoleScreenBufferSize()
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 10,10 };
	SetConsoleScreenBufferSize(std_win_handle, coord);
}

void Test_SetConsoleWindowInfo()
{
	SMALL_RECT rectangle = { 10,10,30,30 };		//窗体的大小的区域 （起点-终点）
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(std_win_handle, TRUE, &rectangle);		//设置窗体大小

}

void Test_SetConsoleCursorPosition()
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { 10,10 };
	SetConsoleCursorPosition(std_win_handle, position);
	
}

void Test_FillConsoleOutputAttribute()
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = 0x87;						//颜色属性
	DWORD nLength = 15;						//上色的字符串长度
	COORD dwWriteCoord = { 10,10 };			//上色坐标
	DWORD NumberOfAttrsWritten;				//用DWORD型的指针，带出成功上色的长度
	FillConsoleOutputAttribute(std_win_handle, color, nLength, dwWriteCoord, &NumberOfAttrsWritten);

	/*** 设置文字颜色 **
	 * 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝
	 * 10-淡绿 11-淡浅绿  12-淡红 13-淡紫 14-淡黄 15-亮白
	 */
}

void Test_FillConsoleOutputCharacter()
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 0x9F;
	char character = 'A';
	int width = 5;
	COORD coord = { 10,10 };
	DWORD relen;
	FillConsoleOutputCharacter(std_win_handle, character, width, coord, &relen);
}

void disableCurrsor() 
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}







