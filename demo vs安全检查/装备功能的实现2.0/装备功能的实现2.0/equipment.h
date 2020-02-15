#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>



typedef struct _prop
{
	int id;         //道具编号
	char name[50];  //道具名称
	int attack;         //玩家的攻击力
	int defense;
	int hp;				//health point
	int mp;				//magic point
}Prop;


typedef struct _player
{
	int id;
	char name[50];
	int attack;         //玩家的攻击力
	int defense;
	int hp;				//health point
	int mp;				//magic point
	Prop weapon;    //玩家装备的武器
	Prop armor;		//玩家装备的防具
	Prop bag[20];
}Player;

void equit(Player*players);
