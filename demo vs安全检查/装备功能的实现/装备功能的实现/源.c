#include "equipment.h"

/*
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
*/
int main()
{
	Prop weapons[5] =
	{
		{0,"大宝剑",Weapon,weapons[0].minAttack=100,weapons[0].maxAttack=100},
		{1,"屠龙宝刀",Weapon,weapons[1].minAttack = 200,weapons[1].maxAttack = 200},

	};

	Player players[5] = 
	{
		{1,"大表哥",100,weapons[0]},
		{2,"二表哥",100,weapons[1]}
	};

	printf("enum：%d %d %d %d %d\n", Weapon, Armor, Con, card, Frag);
	printf("结构体中默认值为：%d\n", players[0].A);

	printf("装备前大表哥的攻击力：%d\n",players[0].Attack);//  .enum中的元素（如weapon）之后,枚举结构体Prop中所有元素
	players[0].Attack += players[0].weapon[0].maxAttack;
	printf("装备后大表哥的攻击力：%d\n",players[0].Attack);

	equip(players[0].Attack, players[0].weapon[0].maxAttack);
	printf("装备后大表哥的攻击力：%d\n", players[0].Attack);

	//Player * player_ptr = players;
	equip_ptr(&players[0]);
	printf("装备后大表哥的攻击力：%d\n\n", players[0].Attack);



	printf("装备前二表哥的攻击力：%d\n", players[1].Attack);
	equip_ptr(&players[1]);
	printf("装备后二表哥的攻击力：%d\n\n", players[1].Attack);





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

