#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*
	模拟实现道具店购物功能(商店暂时只支持一种类型的商品)
	1、商品结构-名称、单价、库存量、描述
	2、背包结构-玩家编号、商品[10]、道具数量、最大道具数
	3、玩家结构-编号、名称、密码、金钱、[背包]
	模拟玩家购买游戏道具
	1、玩家选择要购买的道具
	2、玩家同意交易后扣除相应游戏币
	3、对应商品库存-1
	*4、玩家背包中增加商品或该商品数量+1
*/
/* 商品结构 */
typedef struct _prop {
	int id;         //道具的唯一编号
	char name[50];  //道具名称
	double price;   //道具单价
	int stock;      //库存量：如果在背包中，表示此道具的叠加数量
	char desc[200]; //道具的功能描述
}Prop;
/* 背包结构 */
typedef struct _bag {
	int playerId;   //所属玩家的编号
	int count;      //当前背包中，道具的数量
	int max;        //当前背包的插槽总数-插槽数量可以让用户用rmb购买
	Prop props[8];  //当前背包中的道具数组
}Bag;
/* 玩家结构 */
typedef struct _player {
	int id;         //玩家编号
	char name[50];  //用户名/昵称
	char pass[50];  //密码
	Bag bag;        //玩家的背包
	int bagPropCount;//玩家背包道具数目
	int bagCapacity=8;	//玩家背包道具容量
	double gold;    //玩家金币-人性显示：可以将100000铜币转换成银币、金币显示
	double sysee;   //元宝数量
}Player;
Prop *props;
Player *players;
int propsCount = 0;
int playerCount = 0;

void Init();        //用来初始化游戏数据
void ShowProps();
void ShowPlayers();
/**
 * 交易函数
 * 参数1：参与交易的玩家指针-为了方便修改玩家交易后的金币数
 * 参数2：玩家购买的商品id
 */
void Trade(Player *player, int propId);

void Change(Player *player, int key);