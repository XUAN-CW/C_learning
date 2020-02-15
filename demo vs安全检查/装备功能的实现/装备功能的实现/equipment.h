#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/*********************   游戏的结构类型定义   *******************************/

//玩家、地图、装备、怪物
/* 游戏地图结构 游戏地图
  编号、名称、介绍、玩家的进入等级 */

/* 游戏道具类型枚举 - 武器、道具、消耗品、卡片、碎片 */
typedef enum _proptype {
	Weapon, Armor, Con, card, Frag
}PropType;

/* 游戏道具 - 武器、防具、消耗品、卡片 */
typedef struct _prop 
{
	int id;         //道具编号
	char name[50];  //道具名称
	PropType type;  //道具的类型
	union {//联合 - 多选1
		int minAttack; //如果是武器，就对应攻击力
		int minDefence;//如果是防具，就对应防御力
		int minPower;  //如果是血瓶等消耗品，就对应增加的能量值
	};
	union {//联合 - 多选1
		int maxAttack; //如果是武器，就对应攻击力
		int maxDefence;//如果是防具，就对应防御力
		int maxPower;  //如果是血瓶等消耗品，就对应增加的能量值
	};
}Prop;


typedef struct _player 
{
	int id;
	char name[50];
	int Attack;         //玩家的攻击力
	Prop weapon[5];    //玩家装备的武器
	int A;
	//玩家的背包
}Player;


int equip(int player_Attack ,int weapon_maxAttack);
int equip(int player_Attack, int weapon_maxAttack)
{
	player_Attack += weapon_maxAttack;
	return player_Attack;
}

void equip_ptr(Player * player_ptr);
void equip_ptr(Player * player_ptr)
{
	player_ptr->Attack += player_ptr->weapon[0].maxAttack;
}