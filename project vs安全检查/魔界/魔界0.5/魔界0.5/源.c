#include "Game.h"
int main()
{
	char key;   //接收到的用户按键
	SetConsoleTitle(L"魔界");
	SetColor(10, 0);
	Init();
	ShowWelcome();
	ShowMap();
	ShowMainMenu();

	while (1)
	{
		fflush(stdin);
		key = _getch();
		fflush(stdin);
		/** 菜单 */
		switch (key)
		{
		case '1':	//自我欣赏
			Player_Equipment();
			continue;
		case '2':	//查找怪物
			ShowMonsters();
			continue;
		case '3':	//回家
			Move(4, 3);
			continue;
		case'4':
			Store();
			continue;
		default:
			break;
		}
		walk(key);
		ShowMap();	//重新显示地图
		Clear(MARGIN_X, MAINMENU_START_Y, 7);
		ShowMainMenu();
	}
	return 0;
}