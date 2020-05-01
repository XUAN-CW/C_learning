#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "interface.h"
#include "foundation.h"
extern Option mode[4];

void  StartGame(Snake *snake)
{
	//printf(" StartGame ");
	char direction = '\0';
	_Bool hittingWall = 0;
	_Bool eatSelf = 0;
	SnakeNode *food = NULL;
	while (1)
	{
		ProduceFood(snake, &food);

		PrintFood(food);

		ReadSnakeDirection(snake, &direction);

		if ('\r' == direction)
			break;

		if (0 == IsSnakeDirectionChange(snake, direction))
			continue;

		ClearPrintSnake(snake);

		SnakeMoveBaseOnDirection(snake, direction);

		hittingWall = IsThroughWall(snake->head);
		
		eatSelf = IsEatSelf(snake);

		if (0 == IsSnakeAlive(snake, hittingWall, eatSelf))
		{
			ClearFood(&food);
			PartialInitializationOfSnake(snake);
			DrawStartGame(snake);
			DrawInformationBar(snake);
			break;
		}

		EatFood(snake, &food);

		IsThroughWall(LastSnakeNode(snake));

		PrintSnake(snake);

		IsRapidSnake(snake);
	}

}

void ReadSnakeDirection(Snake *snake, char *direction)
{
	*direction = ReadChar();
	for (int i = 0; i < snake->speed / 10; i++)
	{
		
		if (*direction != NO_OPERATION)
		{
			break;
		}
		Sleep(10);
	}
}

void ProduceFood(Snake *snake, SnakeNode **food)
{
	if (NULL == *food)
	{
		do
		{
			free(*food);
			*food = NULL;
			*food = InitFood();
		} while (IsFoodOnSnake(snake, *food));		//直至while()为假-->食物不在蛇上
		PrintFood(*food);
	}
}

_Bool IsFoodOnSnake(Snake *snake, SnakeNode *food)
{
	_Bool foodOnSnake = 0;
	SnakeNode *currentNode = snake->head;
	while (currentNode)
	{
		if (currentNode->coord.X == food->coord.X && currentNode->coord.Y == food->coord.Y)
		{
			foodOnSnake = 1;
			break;
		}
		currentNode = currentNode->nextNode;
	}
	return foodOnSnake;
}

void EatFood(Snake *snake, SnakeNode **food)
{
	if (snake->head->coord.X == (*food)->coord.X && snake->head->coord.Y == (*food)->coord.Y)
	{
		AddNodeForSnake(snake, (*food));
		free((*food));
		(*food) = NULL;
		snake->speed -= 2; 
		DrawInformationBar(snake);
	}
}

_Bool IsSnakeDirectionChange(Snake *snake, char direction)
{
	char snakeNegativeDirection = GetSnakeNegativeDirection(snake);
	switch (direction)
	{
	case UP:
		//若小蛇不可以折叠且输入方向与小蛇方向相反，就当做没有读取到方向键
		if (0 == snake->mode.eatSelf && snakeNegativeDirection == direction)
		{
			return 0;
		}
		snake->direction = UP;
		return 1;
		break;
	case DOWN:
		if (0 == snake->mode.eatSelf && snakeNegativeDirection == direction)
		{
			return 0;
		}
		snake->direction = DOWN;
		return 1;
		break;
	case LEFT:
		if (0 == snake->mode.eatSelf && snakeNegativeDirection == direction)
		{
			return 0;
		}
		snake->direction = LEFT;
		return 1;
		break;
	case RIGHT:
		if (0 == snake->mode.eatSelf && snakeNegativeDirection == direction)
		{
			return 0;
		}
		snake->direction = RIGHT;
		return 1;
		break;
	default:
		return 1;
		break;
	}
}

char GetSnakeNegativeDirection(Snake *snake)
{
	char negativeDirection;
	switch (snake->direction)
	{
	case UP:
		negativeDirection = DOWN;
		break;
	case DOWN:
		negativeDirection = UP;
		break;
	case LEFT:
		negativeDirection = RIGHT;
		break;
	case RIGHT:
		negativeDirection = LEFT;
		break;
	default:
		break;
	}
	return negativeDirection;
}

void SnakeMoveBaseOnDirection(Snake *snake, char direction)
{
	if (direction == NO_OPERATION )	
	{
		switch (snake->mode.motionless)
		{
		case 0:			//小蛇不是静止模式且没有操作，小蛇移动
			SnakeMoveWithInvisible(snake);
			break;
		case 1:			//小蛇是静止模式且没有操作，小蛇不动
			return;
			break;
		default:
			break;
		}
	}
	if (UP == direction || DOWN == direction || LEFT == direction || RIGHT == direction)
	{
		SnakeMoveWithInvisible(snake);
	}
}

void PrintFood(SnakeNode *food)
{
	SetCurrsorPosition(food->coord.X, food->coord.Y);
	SetColor(food->color);
	printf("●");
}

_Bool IsEatSelf(Snake *snake)
{
	_Bool eatSelf = 0;
	if (0 == snake->mode.eatSelf)		//小蛇不能吃自己
	{
		SnakeNode *currentNode = snake->head->nextNode;
		for (; currentNode;)
		{
			if (snake->head->coord.X == currentNode->coord.X && snake->head->coord.Y == currentNode->coord.Y)
			{
				eatSelf = 1;
				break;
			}
			currentNode = currentNode->nextNode;
		}
	}
	return eatSelf;
}

_Bool IsSnakeAlive(Snake *snake, _Bool hittingWall, _Bool eatSelf)
{
	if (0 == snake->mode.throughWall && hittingWall == 1)
	{
		snake->alive = 0;
	}
	if (0 == snake->mode.eatSelf && eatSelf == 1)
	{
		snake->alive = 0;
	}
	return snake->alive;
}

void IsRapidSnake(Snake *snake)
{
	if (0 == snake->mode.rapid)			//不是极速贪吃蛇
	{
		for (int i = 0; i < snake->speed / 10; i++)
		{
			Sleep(10);
			i++;							//没有本语句会有卡顿感
		}
	}
	Sleep(20);								//没有本句的极速贪吃蛇会按一个键走两格
}

void PartialInitializationOfSnake(Snake *snake)
{
	SnakeNode *currentNode = snake->head;
	if (currentNode)
	{
		SnakeNode *currentNode_nextNode = currentNode->nextNode;
		for (; currentNode;)
		{
			free(currentNode);
			currentNode = currentNode_nextNode;
			if (currentNode)
			{
				currentNode_nextNode = currentNode->nextNode;
			}
		}
	}
	snake->head = NULL;
	snake->alive = 1;
	snake->length = 0;
	snake->speed = 300;
	snake->direction = RIGHT;
	SnakeNode initialSnakeNode = { 0x7A,RIGHT,{40,10},NULL,NULL };
	for (int i = 0; i < 3; i++)
	{
		AddNodeForSnake(snake, &initialSnakeNode);
		initialSnakeNode.coord.X -= 2;
	}
}

void ClearFood(SnakeNode **food)
{
	SetCurrsorPosition((*food)->coord.X, (*food)->coord.Y);
	SetColor(0xFF);
	printf("  ");
	free((*food));
	(*food) = NULL;
}

void ModeSetting(Snake *snake)
{
	//printf(" ModeSetting ");
	char key;
	int currentSelected = 0;
	mode[0].selected = 1;
	DrawModeSetting(snake);
	while (1)
	{
		key = _getch();

		if (LEFT == key)
		{
			mode[currentSelected % (sizeof(mode) / sizeof(mode[0]))].selected = 0;
			break;
		}
		switch (key)
		{
		case UP:
			mode[currentSelected % (sizeof(mode) / sizeof(mode[0]))].selected = 0;
			currentSelected--;
			if (currentSelected < 0)
			{
				currentSelected = sizeof(mode) / sizeof(mode[0]) - 1;
			}
			mode[currentSelected % (sizeof(mode) / sizeof(mode[0]))].selected = 1;
			break;
		case DOWN:
			mode[currentSelected % (sizeof(mode) / sizeof(mode[0]))].selected = 0;
			currentSelected++;
			mode[currentSelected % (sizeof(mode) / sizeof(mode[0]))].selected = 1;
			break;
		case '\r':
			switch (currentSelected)
			{
			case 0:
				snake->mode.throughWall = !(snake->mode.throughWall);
				break;
			case 1:
				snake->mode.rapid = !(snake->mode.rapid);
				break;
			case 2:
				snake->mode.motionless = !(snake->mode.motionless);
				break;
			case 3:
				snake->mode.eatSelf = !(snake->mode.eatSelf);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		//保存游戏模式设置，将游戏模式放入文件中
		FILE *modeTxtFile = NULL;
		fopen_s(&modeTxtFile, "mode.txt", "w");
		fprintf(modeTxtFile, "%d", snake->mode.throughWall);
		fprintf(modeTxtFile, "%d", snake->mode.rapid);
		fprintf(modeTxtFile, "%d", snake->mode.motionless);
		fprintf(modeTxtFile, "%d", snake->mode.eatSelf);
		fclose(modeTxtFile);
		DrawModeSetting(snake);
	}

}
