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
	UP = 72,			// �Ϸ���
	DOWN = 80,			// �·���
	LEFT = 75,			// ����
	RIGHT = 77			// �ҷ���
};

/*** ��ѭ����ʵʱ��ȡ�ַ� **/
char ReadChar();

/** ���ô��������֡���������ɫ */
void SetColor(int color);

/** ���ÿ���̨�й���λ�� */
void SetCurrsorPosition(int x, int y);

/** ���ô���Ĵ�С */
void SetWindowSize(int width, int height);

/*** �����α� **/
void disableCurrsor();
