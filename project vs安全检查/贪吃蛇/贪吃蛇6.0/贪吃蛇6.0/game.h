#pragma once
#include "snake.h"

/*** 开始游戏 **/
void  StartGame(Snake *snake);

/*** 读取蛇的方向 **/
void ReadSnakeDirection(Snake *snake,char *direction);

/*** 生成食物 **/
void ProduceFood(Snake *snake,SnakeNode **food);

/*** 判断生成的食物在不在蛇身上 **/
_Bool IsFoodOnSnake(Snake *snake, SnakeNode *food);

/** 改变小蛇方向，若小蛇不可折叠且方向为当前方向的反方向，则返回 0（表示没有读取到方向键） */
_Bool IsSnakeDirectionChange(Snake *snake, char direction);

/*** 获取当前蛇方向的反方向 **/
char GetSnakeNegativeDirection(Snake *snake);

/*** 小蛇捕食 **/
void EatFood(Snake *snake, SnakeNode **food);

/*** 判断小蛇是否处于急速状态 **/
void IsRapidSnake(Snake *snake);

/*** 判断小蛇是否还活着 **/
_Bool IsSnakeAlive(Snake *snake,_Bool hittingWall,_Bool eatSelf);

/** 判断小蛇有没有咬到自己，若有，返回 1 ，否则，返回 0 */
_Bool IsEatSelf(Snake *snake);

/*** 根据小蛇移动方向移动小蛇 **/
void SnakeMoveBaseOnDirection(Snake *snake, char direction);

/*** 打印食物 **/
void PrintFood(SnakeNode *food);

/** 小蛇死亡后保留原来的模式设置，初始化小蛇其他属性 */
void PartialInitializationOfSnake(Snake *snake);

/*** 清空食物 **/
void ClearFood(SnakeNode **food);

/*** 模式设置 **/
void ModeSetting(Snake *snake);