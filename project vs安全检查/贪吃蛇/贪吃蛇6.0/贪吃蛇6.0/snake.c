#include <time.h>

#include "snake.h"
#include "foundation.h"

extern COORD snakeCoordLeftTop;
extern COORD snakeCoordRightLow;

void InitSnake(Snake *snake)
{
	//��Ϸ��ʼʱ��������,��������
	//����ֵ
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
	//����txt�ļ���ʼ��С��ģʽ
	ModeSettingByLastModeSetting(snake);
}

void ModeSettingByLastModeSetting(Snake *snake)
{
	FILE *modeTxtFile = NULL;
	//�ж�ģʽ�����ı��ڲ���,�ı����ڣ�openFileFalse == 0 --> ���ļ��ɹ�
	errno_t openFileFalse = fopen_s(&modeTxtFile, "mode.txt", "r");
	switch (openFileFalse)
	{
	case 0:				//�ļ����ڣ����ļ��ɹ��������ļ�������Ϸģʽ
		//˳������
		snake->mode.throughWall = fgetc(modeTxtFile) - '0';
		snake->mode.rapid = fgetc(modeTxtFile) - '0';
		snake->mode.motionless = fgetc(modeTxtFile) - '0';
		snake->mode.eatSelf = fgetc(modeTxtFile) - '0';
		fclose(modeTxtFile);	//�ļ��򿪣���Ҫ�ر�
		break;
	default:			//�ļ������ڣ����ļ�ʧ�ܣ�����ԭ�е����ݴ����ı�
						//�ļ���ʧ�ܣ�����Ҫ�ر�
		//fgetc�� '\0' ֹͣ����%c��ӡ�ᵼ�� '\0' ������ݶ�ȡʧ��
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
	//��ͷ��ӡ����β����ͷ���ܻᱻ����
	//SnakeNode *currentNode = snake->head;
	//if (currentNode)
	//{
	//	for (int i = 0; currentNode; i++)
	//	{
	//		SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
	//		SetColor(currentNode->color);
	//		printf("��");
	//		currentNode = currentNode->nextNode;
	//	}
	//}

	//��β��ӡ����ͷ����ͷ���ᱻ����
	SnakeNode *currentNode = LastSnakeNode(snake);
	if (currentNode)
	{
		for (; currentNode;)
		{
			SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
			SetColor(currentNode->color);
			printf("��");
			currentNode = currentNode->previousNode;
		}
	}
	disableCurrsor();
}

void ClearPrintSnake(Snake *snake)
{
	//����С��ȫ�����
	//SnakeNode *currentNode = snake->head;
	//if (currentNode)
	//{
	//	for (int i = 0; currentNode; i++)
	//	{
	//		SetCurrsorPosition(currentNode->coord.X, currentNode->coord.Y);
	//		SetColor(0xF0);
	//		//�������ո�ռ�����ֽ�
	//		printf("  ");
	//		/*** ��Ӱ **
	//		 * printf("--");
	//		**/
	//		currentNode = currentNode->nextNode;
	//	}
	//}

	//С��ǰ��һ��ֻ�踲��סС�����һ�ڼ��ɣ���Ϊǰ�������ᱻ��һ�ڸ���
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
	if (lastSnakeNode == NULL)			//��û�н��
	{
		snake->head = newSnakeNode;
	}
	else								//���н��
	{
		lastSnakeNode->nextNode = newSnakeNode;
		newSnakeNode->previousNode = lastSnakeNode;
		//С��β����������
		newSnakeNode->coord = lastSnakeNode->coord;
		//������β�ķ������½��
		switch (newSnakeNode->direction)
		{
			//����'��'ÿ��ռ�����ֽڣ����Լ���
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
	//������ͷ����
	snake->head->direction = snake->direction;
	//����ǰ���Ϊ�����ҵ�ǰ����ǰ�ý��Ϊ�գ���˵����ǰ���Ϊ��һ�����
	for (; currentNode && currentNode->previousNode;)
	{
		//ǰһ�������긳����һ������ͷ��������
		currentNode->coord = currentNode->previousNode->coord;
		currentNode->direction = currentNode->previousNode->direction;
		currentNode = currentNode->previousNode;
	}
	//�����ߵķ�������ͷ
	switch (snake->direction)
	{
		//����'��'ÿ��ռ�����ֽڣ����Լ���
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
	food->color = (rand() % 16) * 10;	//���ñ���ɫ
	food->color += rand() % 16;			//����ǰ��ɫ
	food->coord.X = (rand() % 17) * 2 + snakeCoordLeftTop.X;
	food->coord.Y = (rand() % 17) + snakeCoordLeftTop.Y;
	food->direction = RIGHT;
	food->nextNode = NULL;
	food->previousNode = NULL;
	return food;
}

