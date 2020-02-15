#pragma once
#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/***************************************************
 * 文件名：GameLib.h
 * 描  述：用来定义游戏中常用的系统操作（更改文字颜色、清屏等）
 * 创建人：老九学堂·窖头
 * 日  期：2016-11-10
 * 版  本：1.0
 * 官  网：http://www.xuetang9.com
 * 官方QQ：614940318（老九君）
 *
 **************************************************/
#include <stdio.h>
#include <windows.h>


/* 设置文字的前景色和背景色 */
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */
void SetColor(int foreColor, int backColor);
/* 设置光标的位置 */
void SetPosition(int x, int y);
/* 从x、y坐标开始，清rowCount行 */
void Clear(int x, int y, int rowCount);

void ShowWelcome();

#define SEP "------------------------------------------------------------------------------"
#define COL 78                  //游戏界面的总宽度
#define MARGIN_X 20             //左边距
#define MAP_START_Y 3           //地图开始的Y坐标
#define MAP_END_Y   11          //地图结束的Y坐标
#define INFO_START_Y 12         //信息界面开始的Y坐标
#define INFO_END_Y 19           //信息界面的结束Y坐标
#define MAINMENU_START_Y 20     //主菜单开始的Y坐标

void ShowInfomation();
void ShowMainMenu();
void Show();//显示全局数据
void ShowMap();

#endif // GAMELIB_H_INCLUDED
