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
	SMALL_RECT rectangle = { 10,10,30,30 };		//����Ĵ�С������ �����-�յ㣩
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(std_win_handle, TRUE, &rectangle);		//���ô����С

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
	WORD color = 0x87;						//��ɫ����
	DWORD nLength = 15;						//��ɫ���ַ�������
	COORD dwWriteCoord = { 10,10 };			//��ɫ����
	DWORD NumberOfAttrsWritten;				//��DWORD�͵�ָ�룬�����ɹ���ɫ�ĳ���
	FillConsoleOutputAttribute(std_win_handle, color, nLength, dwWriteCoord, &NumberOfAttrsWritten);

	/*** ����������ɫ **
	 * 0-�� 1-�� 2-�� 3-ǳ�� 4-�� 5-�� 6-�� 7-�� 8-�� 9-����
	 * 10-���� 11-��ǳ��  12-���� 13-���� 14-���� 15-����
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







