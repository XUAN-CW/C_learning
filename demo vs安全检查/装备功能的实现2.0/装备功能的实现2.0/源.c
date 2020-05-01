#include "equipment.h"


int main()
{
	int plr = 0;//第plr位玩家
	int eqpm_w = 0;//第eqpm_w+1件武器
	int eqpm_a = 2;//第eqpm_w+1件防具
	Prop weapons[5] =
	{
		//{0,"无装备",0,0,0,0},
		{1,"大宝剑",1,1,1,1},
		{2,"屠龙宝刀",10,10,10,10},

	};

	Prop armor[5]=
	{
		//{0,"无装备",0,0,0,0},
		{1,"布衣",1,1,1,1},
		{2,"锁子甲",10,10,10,10},
	};

	Player players[5] =
	{
		{1,"大表哥"},
		{2,"二表哥",0,0,0,0,weapons[0],armor[1]}
	};

	eqpm_w++;
	plr++;

	printf("结构体中默认值为：%d\n", players[0].hp);
	printf("装备前%s的攻击力：%d\t\t防御力：%d\t生命值：%d\t魔力值：%d\t\n",
		players[plr].name, players[plr].attack, players[plr].defense, players[plr].hp, players[plr].mp);

	equit(&players[eqpm_w]);

	printf("装备后%s的攻击力：%d\t防御力：%d\t生命值：%d\t魔力值：%d\t\n",
		players[plr].name, players[plr].attack, players[plr].defense, players[plr].hp, players[plr].mp);

	system("pause");
	return 0;
}

/*
		int id;
		char name[50];
		int hp;         //玩家的血量
		int mp;         //玩家的内力值
		int gold;       //玩家的金币数量
		Prop weapon;    //玩家装备的武器
		Prop armor;     //玩家装备的防具
		//玩家的背包
	}Player;
*/

