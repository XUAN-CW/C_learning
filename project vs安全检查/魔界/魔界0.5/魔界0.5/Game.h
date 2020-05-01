#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Define.h"
#include <conio.h>
#include <math.h>

typedef struct _map
{
	int id;					//地图编号
	char name[50];			//地图名称
	int level;				//玩家进入的最低等级
	COORD coord;			//地图的坐标
	char desc[500];			//地图的介绍
}Map;

typedef struct _prop
{

	int id;
	char name[50];
	int category;
	int leve;
	int atk;
	int defence;
	int hp;
	double miss;
	double crit;
	int mp;
	int exp;
	int stock;
	int price;
	char desc[200];
	int specificAbility;
	int agility;
}Prop;

typedef struct _bag
{
	int playerId;				//所属玩家的编号
	int count;					//当前背包中，道具的数量
	int capacity;				//背包容量
	Prop props[50];				//当前背包中的道具数组
}Bag;

typedef struct _player
{
	int id;						//编号
	char name[50];				//名称
	int atk;					//攻击力
	int defence;				//防御力
	int hp;						//血量
	double miss;				//闪避率
	double crit;				//暴击率
	int mp;						//魔力值
	int exp;					//经验值
	int level;					//级别
	int gold;					//金币数量
	int agility;				//敏捷
	int luck;					//幸运 (爆装备概率)
	COORD coord;				//当前所在地图的坐标
	Prop weapon;				//装备的武器
	Prop armor;					//装备的防具
	Bag bag;					//背包
}Player;

typedef struct _monster {
	int id;
	char name[50];
	int level;					//怪物的级别
	int hp;						//怪物的生命值
	int atk;					//怪物的攻击力
	int defence;				//怪物的防御力
	int Money;					//杀死怪物后掉落的金币值
	int exp;					//杀死怪物后玩家获得的经验值
	int state;					//怪物当前的状态，0表示怪物已死，非0表示怪物活着
	int agility;				//敏捷
	Prop props[3];				//杀死怪物后掉落的装备
	COORD coord;				//怪物的坐标
	int luck = 1;				//幸运
	double miss;				//闪避率
	double crit;				//暴击率
}Monster;


void ShowWelcome();			//显示游戏的欢迎信息 

void ShowMap();				//显示游戏地图 

void ShowMapInfo();			//在信息界面显示当前地图的信息  

void ShowInfomation();		//显示游戏地图下方的游戏信息 

void ShowMainMenu();		//显示游戏的主菜单 

void ShowPlayerInfo();		//在信息界面显示玩家的个人资料  

void ShowMonsters();		//在信息界面显示当前地图的怪物 

void Move(int x, int y);	// 瞬间移动  


/**
 * 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色    11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
 */
void SetColor(int foreColor, int backColor);

void SetPosition(int x, int y);					// 设置光标的位置 

void Clear(int x, int y, int rowCount);			// 从x、y坐标开始，清rowCount行 

void Init();									//初始化游戏数据

void walk(char);
void Box(int, int, int);

/*商城*/
void Store();
void Trade(Player * palyer, int propId);
void ShowGoods();
void ShowBag();
void BagWalk(char bagWalk);
void PropFlashback(Player * currPlayer);

/*个人信息与装备*/
void Player_Equipment();
void ShowPlayerInformation();
void WearEquipment(Player * currPlayer, int bagY);
void Sell(Player * currPlayer, int bagY);
void TakeOffAllEquipment(Player * currPlayer, int bagY);
void RandBag(Player * currPlayer);
void EquipmentAttribute_add(Prop equipment);
void EquipmentAttribute_minus(Prop equipment);
void SeekRepetition(Bag currPlayerBag);

/*战斗*/
void Fight(int monsterId, Monster  pkMonsters);
