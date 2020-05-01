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


/*** 初始化一条蛇 **/
void InitSnake(Snake *snake);

/** 找出蛇的最后一个结点并返回其指针 */
SnakeNode* LastSnakeNode(Snake *snake);

/*** 给蛇曾加一个节点 **/
void AddNodeForSnake(Snake *snake, SnakeNode *food);

/*** 打印一条蛇 **/
void PrintSnake(Snake *snake);

/** 清空在面板上打印出来的蛇 */
void ClearPrintSnake(Snake *snake);

/*** 小蛇在移动了，只是没有打印出来 **/
void SnakeMoveWithInvisible(Snake *snake);

/*** 判断小蛇能否穿墙 **/
_Bool IsThroughWall(SnakeNode *snakeNode);

/*** 初始化一个食物 **/
SnakeNode *InitFood();

/** 通过保存的数据设置小蛇模式,数据保存于txt文件内 */
void ModeSettingByLastModeSetting(Snake *snake);

