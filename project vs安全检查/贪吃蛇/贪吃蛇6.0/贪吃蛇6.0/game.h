#pragma once
#include "snake.h"

/*** ��ʼ��Ϸ **/
void  StartGame(Snake *snake);

/*** ��ȡ�ߵķ��� **/
void ReadSnakeDirection(Snake *snake,char *direction);

/*** ����ʳ�� **/
void ProduceFood(Snake *snake,SnakeNode **food);

/*** �ж����ɵ�ʳ���ڲ��������� **/
_Bool IsFoodOnSnake(Snake *snake, SnakeNode *food);

/** �ı�С�߷�����С�߲����۵��ҷ���Ϊ��ǰ����ķ������򷵻� 0����ʾû�ж�ȡ��������� */
_Bool IsSnakeDirectionChange(Snake *snake, char direction);

/*** ��ȡ��ǰ�߷���ķ����� **/
char GetSnakeNegativeDirection(Snake *snake);

/*** С�߲�ʳ **/
void EatFood(Snake *snake, SnakeNode **food);

/*** �ж�С���Ƿ��ڼ���״̬ **/
void IsRapidSnake(Snake *snake);

/*** �ж�С���Ƿ񻹻��� **/
_Bool IsSnakeAlive(Snake *snake,_Bool hittingWall,_Bool eatSelf);

/** �ж�С����û��ҧ���Լ������У����� 1 �����򣬷��� 0 */
_Bool IsEatSelf(Snake *snake);

/*** ����С���ƶ������ƶ�С�� **/
void SnakeMoveBaseOnDirection(Snake *snake, char direction);

/*** ��ӡʳ�� **/
void PrintFood(SnakeNode *food);

/** С����������ԭ����ģʽ���ã���ʼ��С���������� */
void PartialInitializationOfSnake(Snake *snake);

/*** ���ʳ�� **/
void ClearFood(SnakeNode **food);

/*** ģʽ���� **/
void ModeSetting(Snake *snake);