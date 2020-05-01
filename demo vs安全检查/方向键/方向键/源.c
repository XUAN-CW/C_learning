#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef enum _direction
{
	UP = 72,			// 上方向
	DOWN = 80,			// 下方向
	LEFT = 75,			// 左方向
	RIGHT = 77			// 右方向
}Direction;

int main()
{
	char key[8];
	//明明有八个位置，为什么按四个方向键就跳出循环了？
	//按下字母或数字键，确实可以按八个键
	for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
	{
		key[i] = _getch();
	}
	for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
	{
		int temp = (char)key[i];
		printf("%d\n", temp);
	}
	system("pause");
	return 0;
}