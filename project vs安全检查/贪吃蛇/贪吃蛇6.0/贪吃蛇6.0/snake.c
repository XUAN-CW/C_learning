#include <time.h>

#include "snake.h"
#include "foundation.h"

extern COORD snakeCoordLeftTop;
extern COORD snakeCoordRightLow;

void InitSnake(Snake *snake)
{
	//游戏开始时蛇有三节,方向向右
	//赋初值
	snake->length = 0;
	snake->head = NULL;
	snake->direction = RIGHT;
	snake->alive = 1;
	snake->speed = 300;
	snake->mode.throughWall = 1;
	snake->mode.rapid = 1;
	snake->mode.motionless = 0;
	snake->mode.eatSelf = 1;
	SnakeNode initialSnakeNode = { 0x7A,RIGHT,{40,10},NULL,NULL };
	for (int i = 0; i < 3; i++)
	{
		AddNodeForSnake(snake, &initialSnakeNode);
		initialSnakeNode.coord.X -= 2;
	}
	//根据txt文件初始化小蛇模式
	ModeSettingByLastModeSetting(snake);
}

void ModeSettingByLastModeSetting(Snake *snake)
{
	FILE *modeTxtFile = NULL;
	//判断模式设置文本在不在,文本存在，openFileFalse == 0 --> 打开文件成功
	errno_t openFileFalse = fopen_s(&modeTxtFile, "mode.txt", "r");
	switch (openFileFalse)
	{
	case 0:				//文件存在，打开文件成功，根据文件设置游戏模式
		//顺序不能乱
		snake->mode.throughWall = fgetc(modeTxtFile) - '0';
		snake->mode.rapid = fgetc(modeTxtFile) - '0';
		snake->mode.motionless = fgetc(modeTxtFile) - '0';
		snake->mode.eatSelf = fgetc(modeTxtFile) - '0';
		fclose(modeTxtFile);	//文件打开，需要关闭
		break;
	default:			//文件不存在，打开文件失败，根据原有的数据创建文本
						//文件打开失败，不需要关闭
		//fgetc遇 '\0' 停止，以%c打印会导致 '\0' 后的数据读取失败
		fopen_s(&modeTxtFile, "mode.txt", "w");
		fprintf(modeTxtFile, "%d", snake->mode.throughWall);
		fprintf(modeTxtFile, "%d", snake->mode.rapid);
		fprintf(modeTxtFile, "%d", snake->mode.motionless);
		fprintf(modeTxtFile, "%d", snake->mode.eatSelf);
		fclose(modeTxtFile);
		break;
	}
}

SnakeNode* LastSnakeNode(Snake *snake)
{
	SnakeNode *currentNode = snake->head;
	if (currentNode)
	{
		for (; currentNode->nextNode;)
		{
			currentNode = currentNode->nextNode;
		}
	}
	return currentNode;
}

void PrintSnake(Snake *snake)
{
	//蛇头打印到蛇尾，蛇头可能会被覆盖
	//SnakeNode *currentNode = snake->head;
	//if (currentNode)
	//{
	//	for (int i = 0; currentNode; i++)
	//	{
	//		SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
	//		SetColor(currentNode->color);
	//		printf("●");
	//		currentNode = currentNode->nextNode;
	//	}
	//}

	//蛇尾打印到蛇头，蛇头不会被覆盖
	SnakeNode *currentNode = LastSnakeNode(snake);
	if (currentNode)
	{
		for (; currentNode;)
		{
			SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
			SetColor(currentNode->color);
			printf("●");
			currentNode = currentNode->previousNode;
		}
	}
	disableCurrsor();
}

void ClearPrintSnake(Snake *snake)
{
	//覆盖小蛇全部结点
	//SnakeNode *currentNode = snake->head;
	//if (currentNode)
	//{
	//	for (int i = 0; currentNode; i++)
	//	{
	//		SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
	//		SetColor(0xF0);
	//		//打两个空格，占两个字节
	//		printf("  ");
	//		/*** 残影 **
	//		 * printf("--");
	//		**/
	//		currentNode = currentNode->nextNode;
	//	}
	//}

	//小蛇前进一格，只需覆盖住小蛇最后一节即可，因为前面的身体会被后一节覆盖
	SnakeNode *currentNode = LastSnakeNode(snake);
	SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
	SetColor(0xF0);
	printf("  ");
}

void AddNodeForSnake(Snake *snake, SnakeNode *food)
{
	SnakeNode *lastSnakeNode = LastSnakeNode(snake);
	SnakeNode *newSnakeNode = (SnakeNode*)malloc(sizeof(SnakeNode));
	*(newSnakeNode) = *(food);
	if (lastSnakeNode == NULL)			//蛇没有结点
	{
		snake->head = newSnakeNode;
	}
	else								//蛇有结点
	{
		lastSnakeNode->nextNode = newSnakeNode;
		newSnakeNode->previousNode = lastSnakeNode;
		//小蛇尾结点坐标调整
		newSnakeNode->coord = lastSnakeNode->coord;
		//根据蛇尾的方向处理新结点
		switch (newSnakeNode->direction)
		{
			//横向'●'每节占两个字节，所以减二
		case DOWN:
			newSnakeNode->coord.X += 0;
			newSnakeNode->coord.Y -= 1;
			break;
		case UP:
			newSnakeNode->coord.X += 0;
			newSnakeNode->coord.Y += 1;
			break;
		case RIGHT:
			newSnakeNode->coord.X -= 2;
			newSnakeNode->coord.Y += 0;
			break;
		case LEFT:
			newSnakeNode->coord.X += 2;
			newSnakeNode->coord.Y += 0;
			break;
		default:
			break;
		}
	}
	snake->length++;
}

void SnakeMoveWithInvisible(Snake *snake)
{
	SnakeNode *currentNode = LastSnakeNode(snake);
	//处理蛇头方向
	snake->head->direction = snake->direction;
	//若当前结点为存在且当前结点的前置结点为空，则说明当前结点为第一个结点
	for (; currentNode && currentNode->previousNode;)
	{
		//前一个的坐标赋给后一个，蛇头不做处理
		currentNode->coord = currentNode->previousNode->coord;
		currentNode->direction = currentNode->previousNode->direction;
		currentNode = currentNode->previousNode;
	}
	//根据蛇的方向处理蛇头
	switch (snake->direction)
	{
		//横向'●'每节占两个字节，所以减二
	case UP:
		snake->head->coord.X += 0;
		snake->head->coord.Y -= 1;
		break;
	case DOWN:
		snake->head->coord.X += 0;
		snake->head->coord.Y += 1;
		break;
	case LEFT:
		snake->head->coord.X -= 2;
		snake->head->coord.Y += 0;
		break;
	case RIGHT:
		snake->head->coord.X += 2;
		snake->head->coord.Y += 0;
		break;
	default:
		break;
	}
}

_Bool IsThroughWall(SnakeNode *snakeNode)
{
	_Bool hittingWall = 0;
	if (snakeNode->coord.X < snakeCoordLeftTop.X)
	{
		snakeNode->coord.X = snakeCoordRightLow.X ;
		hittingWall = 1;
	}
	else if (snakeNode->coord.X > snakeCoordRightLow.X)
	{
		snakeNode->coord.X = snakeCoordLeftTop.X;
		hittingWall = 1;
	}
	else if (snakeNode->coord.Y < snakeCoordLeftTop.Y)
	{
		snakeNode->coord.Y = snakeCoordRightLow.Y;
		hittingWall = 1;
	}
	else if (snakeNode->coord.Y > snakeCoordRightLow.Y)
	{
		snakeNode->coord.Y = snakeCoordLeftTop.Y;
		hittingWall = 1;
	}
	return hittingWall;
}

SnakeNode *InitFood()
{
	SnakeNode *food = (SnakeNode*)malloc(sizeof(SnakeNode));
	srand((unsigned int)time(NULL));
	food->color = (rand() % 16) * 10;	//设置背景色
	food->color += rand() % 16;			//设置前景色
	food->coord.X = (rand() % 17) * 2 + snakeCoordLeftTop.X;
	food->coord.Y = (rand() % 17) + snakeCoordLeftTop.Y;
	food->direction = RIGHT;
	food->nextNode = NULL;
	food->previousNode = NULL;
	return food;
}

