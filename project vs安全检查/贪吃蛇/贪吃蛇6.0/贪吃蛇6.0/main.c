#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "interface.h"
#include "foundation.h"
int main()
{
	Snake snake;
	char key;
	InitSnake(&snake);
	SetWindowSize(56, 20);
	SetConsoleTitle(L"Ä§ÐÔÌ°³ÔÉß3.0");
	DrawInterfaceFrame();
	DrawInformationBar(&snake);
	DrawStartGame(&snake);

	while (1)
	{
		key = ReadChar();
		Game_and_ModeSetting(&snake, key);
	}
	return 0;
}