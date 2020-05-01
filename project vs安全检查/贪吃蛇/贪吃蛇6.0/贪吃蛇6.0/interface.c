#include "interface.h"
#include "foundation.h"
#include "game.h"

COORD interfaceLeftTop = { 2,1 };
COORD interfaceRightLow = { 54,19 };
COORD interfaceRightTop = { 54,1 };
COORD interfaceLeftLow = { 2,19 };

COORD boundaryLeftTop = { 18,2 };
COORD boundaryRightLow = { 19,19 };

COORD snakeCoordLeftTop = { 20,2 };
COORD snakeCoordRightLow = { 52,18 };

COORD gameScopeRightLow = { 53,18 };

COORD informationBarFristOption = { 5,4 };
COORD snakeModelFristOption = { 22,4 };

Option informationBar[]=
{
	{"游戏", 0x0F,0x79,1},
	{"模式", 0x0F,0x79,0},
};

Option mode[] =
{
	{" 「穿  墙」           ", 0x0F,0x79,0},
	{" 「极  速」           ", 0x0F,0x79,0},
	{" 「静  止」           ", 0x0F,0x79,0},
	{" 「折  叠」           ", 0x0F,0x79,0},
};

void DrawRectangleWithChar(COORD topLeft, COORD lowRight, int color, char character)
{
		SetCurrsorPosition(topLeft.X, topLeft.Y);
		SetColor(color);
		int x = topLeft.X;
		int y = topLeft.Y;
		for (y; y <= lowRight.Y; )
		{
			for (; x <= lowRight.X; x++)
			{
				printf("%c", character);
			}
			y++;
			x = topLeft.X;
			SetCurrsorPosition(x, y);
		}
		disableCurrsor();
}

void DrawInterfaceFrame()
{
	DrawRectangleWithChar(boundaryLeftTop, boundaryRightLow, 0x74, '|');
	DrawRectangleWithChar( interfaceLeftTop, interfaceLeftLow,0x74 ,'|' );
	DrawRectangleWithChar(interfaceRightTop, interfaceRightLow, 0x74, '|');
	DrawRectangleWithChar(interfaceLeftTop, interfaceRightTop, 0x74, '-');
	DrawRectangleWithChar(interfaceLeftLow, interfaceRightLow, 0x74, '-');
}

void DrawInformationBar(Snake *snake)
{
	SetColor(0x0F);
	SetCurrsorPosition(informationBarFristOption.X, informationBarFristOption.Y + 0);
	printf("分数:%-5d", (snake->length - 3) * 10);
	SetCurrsorPosition(informationBarFristOption.X, informationBarFristOption.Y + 3);
	printf("长度:%-5d", snake->length);
	SetCurrsorPosition(informationBarFristOption.X, informationBarFristOption.Y + 6);
	if (snake->mode.motionless)
	{
		printf("秒/格:∞   ");
	}
	else
	{
		if (snake->mode.rapid)
		{
			printf("秒/格:0.%d", snake->speed - 50);
		}
		else
		{
			printf("秒/格:0.%d", snake->speed);
		}
		
	}

	SetCurrsorPosition(informationBarFristOption.X, informationBarFristOption.Y + 9);
	if (informationBar[0].selected)
	{
		SetColor(informationBar[0].selectedColor);
	}
	else
	{
		SetColor(informationBar[0].defaultColor);
	}
	printf(" 游     戏 ");

	SetCurrsorPosition(informationBarFristOption.X, informationBarFristOption.Y + 12);
	if (informationBar[1].selected)
	{
		SetColor(informationBar[1].selectedColor);
	}
	else
	{
		SetColor(informationBar[1].defaultColor);
	}
	printf(" 模     式 ");

	disableCurrsor();
}

void Game_and_ModeSetting(Snake *snake,char key)
{
	int currentSelected = CurrentSelected_InformationBar();
	switch (key)
	{
	case UP:
		informationBar[currentSelected].selected = 0;
		informationBar[(currentSelected + 1) % (sizeof(informationBar) / sizeof(informationBar[0]))].selected = 1;
		DrawInformationBar(snake);
		switch ((currentSelected + 1) % (sizeof(informationBar) / sizeof(informationBar[0])))
		{
		case 0:
			DrawStartGame(snake);
			break;
		case 1:
			SetModeSettingBackgroundColor();
			DrawModeSetting(snake);
			break;
		default:
			break;
		}
		break;
	case DOWN:
		informationBar[currentSelected].selected = 0;
		if (currentSelected == 0)
		{
			currentSelected = sizeof(informationBar) / sizeof(informationBar[0]);
		}
		informationBar[currentSelected - 1].selected = 1;
		DrawInformationBar(snake);
		switch (currentSelected - 1)
		{
		case 0:
			
			DrawStartGame(snake);
			break;
		case 1:
			SetModeSettingBackgroundColor();
			DrawModeSetting(snake);
			break;
		default:
			break;
		}
		break;
	case '\r':
		IntoCurrentSelected(snake, currentSelected);
		break;
	case RIGHT:
		IntoCurrentSelected(snake, currentSelected);
		break;
	default:
		break;
	}
}

void IntoCurrentSelected(Snake *snake, char currentSelected)
{
	switch (currentSelected)
	{
	case 0:
		StartGame(snake);
		break;
	case 1:
		SetModeSettingBackgroundColor();
		DrawModeSetting(snake);
		ModeSetting(snake);
		DrawModeSetting(snake);
		break;
	default:
		break;
	}
}

int CurrentSelected_InformationBar()
{
	int currentSelected = 0;
	for (; currentSelected < sizeof(informationBar)/sizeof(informationBar[0]); currentSelected++)
	{
		if (informationBar[currentSelected].selected)
		{
			break;
		}
	}
	return currentSelected;
}

void DrawStartGame(Snake *snake)
{
	SetGameBackgroundColor();
	PrintSnake(snake);
}

void DrawModeSetting(Snake *snake)
{
	char status[2][5] = { "关","开" };
	char *snakeStatus = NULL;
	
	SetCurrsorPosition(snakeModelFristOption.X, snakeModelFristOption.Y + 0);
	switch (mode[0].selected)
	{
	case 0:
		SetColor(mode[0].defaultColor);
		break;
	case 1:
		SetColor(mode[0].selectedColor);
		break;
	default:
		break;
	}
	switch (snake->mode.throughWall)
	{
	case 0:
		snakeStatus = status[0];
		break;
	case 1:
		snakeStatus = status[1];
		break;
	default:
		break;
	}
	printf("%s[%s]", mode[0].name, snakeStatus);

	SetCurrsorPosition(snakeModelFristOption.X, snakeModelFristOption.Y + 4);
	switch (mode[1].selected)
	{
	case 0:
		SetColor(mode[1].defaultColor);
		break;
	case 1:
		SetColor(mode[1].selectedColor);
		break;
	default:
		break;
	}
	switch (snake->mode.rapid)
	{
	case 0:
		snakeStatus = status[0];
		break;
	case 1:
		snakeStatus = status[1];
		break;
	default:
		break;
	}
	printf("%s[%s]", mode[1].name, snakeStatus);

	SetCurrsorPosition(snakeModelFristOption.X, snakeModelFristOption.Y + 8);
	switch (mode[2].selected)
	{
	case 0:
		SetColor(mode[2].defaultColor);
		break;
	case 1:
		SetColor(mode[2].selectedColor);
		break;
	default:
		break;
	}
	switch (snake->mode.motionless)
	{
	case 0:
		snakeStatus = status[0];
		break;
	case 1:
		snakeStatus = status[1];
		break;
	default:
		break;
	}
	printf("%s[%s]", mode[2].name, snakeStatus);

	SetCurrsorPosition(snakeModelFristOption.X, snakeModelFristOption.Y + 12);
	switch (mode[3].selected)
	{
	case 0:
		SetColor(mode[3].defaultColor);
		break;
	case 1:
		SetColor(mode[3].selectedColor);
		break;
	default:
		break;
	}
	switch (snake->mode.eatSelf)
	{
	case 0:
		snakeStatus = status[0];
		break;
	case 1:
		snakeStatus = status[1];
		break;
	default:
		break;
	}
	printf("%s[%s]", mode[3].name, snakeStatus);

	disableCurrsor();
}

void SetGameBackgroundColor()
{
	
	DrawRectangleWithChar(snakeCoordLeftTop, gameScopeRightLow, 0xFF, ' ');
}

void SetModeSettingBackgroundColor()
{
	DrawRectangleWithChar(snakeCoordLeftTop, gameScopeRightLow, 0x00, ' ');
}