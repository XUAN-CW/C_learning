#include "Game.h"
int main()
{
	char key;   //���յ����û�����
	SetConsoleTitle(L"ħ��");
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
		/** �˵� */
		switch (key)
		{
		case '1':	//��������
			Player_Equipment();
			continue;
		case '2':	//���ҹ���
			ShowMonsters();
			continue;
		case '3':	//�ؼ�
			Move(4, 3);
			continue;
		case'4':
			Store();
			continue;
		default:
			break;
		}
		walk(key);
		ShowMap();	//������ʾ��ͼ
		Clear(MARGIN_X, MAINMENU_START_Y, 7);
		ShowMainMenu();
	}
	return 0;
}