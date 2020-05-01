#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct _snake_node
{
	int color;
	char direction;
	COORD coord;
	struct _snake_node *nextNode;
	struct _snake_node *previousNode;
}SnakeNode;

typedef struct _snake_attribute
{
	_Bool eatSelf;
	_Bool throughWall;
	_Bool rapid;
	_Bool motionless;
}SnakeAbility;

typedef struct _snake
{
	int length;
	int speed;
	char direction;
	_Bool alive;
	SnakeNode *head;
	SnakeAbility mode;
}Snake;


/*** ��ʼ��һ���� **/
void InitSnake(Snake *snake);

/** �ҳ��ߵ����һ����㲢������ָ�� */
SnakeNode* LastSnakeNode(Snake *snake);

/*** ��������һ���ڵ� **/
void AddNodeForSnake(Snake *snake, SnakeNode *food);

/*** ��ӡһ���� **/
void PrintSnake(Snake *snake);

/** ���������ϴ�ӡ�������� */
void ClearPrintSnake(Snake *snake);

/*** С�����ƶ��ˣ�ֻ��û�д�ӡ���� **/
void SnakeMoveWithInvisible(Snake *snake);

/*** �ж�С���ܷ�ǽ **/
_Bool IsThroughWall(SnakeNode *snakeNode);

/*** ��ʼ��һ��ʳ�� **/
SnakeNode *InitFood();

/** ͨ���������������С��ģʽ,���ݱ�����txt�ļ��� */
void ModeSettingByLastModeSetting(Snake *snake);

