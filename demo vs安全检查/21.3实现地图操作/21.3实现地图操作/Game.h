#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
/***************************************************
 * 文件名：Game.h
 * 描  述：用来定义游戏的一些核心结构和函数
 * 创建人：老九学堂·窖头
 * 日  期：2016-11-10
 * 版  本：1.0
 * 官  网：http://www.xuetang9.com
 * 官方QQ：614940318（老九君）
 *
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

 /*********************  游戏的结构类型定义   *******************************/

 //玩家、地图、装备、怪物
 /* 游戏地图结构 游戏地图
   编号、名称、介绍、玩家的进入等级 */
typedef struct _map {
	int id;         //地图编号
	char name[50];  //地图名称
	int minLevel;   //玩家进入的最低等级
	//坐标结构
	COORD coord;    //地图的坐标
	char desc[500]; //地图的介绍
}Map;



#endif // GAME_H_INCLUDED
