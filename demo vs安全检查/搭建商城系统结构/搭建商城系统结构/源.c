#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main()
{
	//初始化游戏数据
	Init();
	printf("\n*********交易前************************\n");
	//2、打印这些初始化数据
	ShowProps();
	ShowPlayers();

	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 4);
	Trade(&players[0], 5);

	Trade(&players[3], 1);

	printf("\n\n*********交易后************************\n");
	ShowProps();
	ShowPlayers();
	return 0;
}
/**
 * 交易函数
 * 参数1：参与交易的玩家指针-为了方便修改玩家交易后的金币数
 * 参数2：玩家购买的商品id
 */
void Trade(Player *player, int propId)
{
	int i;
	//需要判断：商品的库存，玩家余额够不够，玩家背包空间够不够
	Prop *tradeProp = NULL;//要购买的商品指针
	for (i = 0; i < propsCount; i++)
	{
		if (propId == props[i].id) {
			tradeProp = &props[i];//tradeProp = props + i;
			break;
		}
	}
	if (tradeProp->stock <= 0)
	{
		printf("地主家都没有余粮！商店都被买空啦！\n");
		return;
	}
	if (player->gold < tradeProp->price)
	{
		printf("钱包都是瘪的，这里可是看钱的社会！！\n");
		return;
	}
	if (player->bag.count >= player->bag.max && player->bag.count != 0)
	{
		printf("背包已满，交易失败！\n");
		return;
	}
	//满足交易条件，执行交易的业务操作
	//1、商品库存-1
	tradeProp->stock--;
	//2、玩家金币-商品单价
	player->gold -= tradeProp->price;
	//*3、玩家背包道具增加
	//判断玩家背包中是否已有该商品

	//如果有该商品，背包中的该商品总数+1
	for (i = 0; i < player->bag.count; i++)
	{
		//如果要购买的商品id 跟 背包中的某个商品id相同
		if (propId == player->bag.props[i].id)
		{
			player->bag.props[i].stock++;
			break;
		}
	}
	if (i == player->bag.count)//如果没有该商品，该商品添加到背包中即可
	{
		//向背包中创建一个商品-复制一份要交易的商品信息到背包中
		int newIndex = player->bag.count;
		player->bag.props[newIndex].id = tradeProp->id;
		player->bag.props[newIndex].price = tradeProp->price;
		player->bag.props[newIndex].stock = 1;
		strcpy(player->bag.props[newIndex].name, tradeProp->name);
		strcpy(player->bag.props[newIndex].desc, tradeProp->desc);
		player->bag.count++;
	}
}
void Init()
{
	//1、初始化数据
	static Prop propArray[] = {
		{1, "双倍经验卡", 3000, 10, "双击666"},
		{2, "腐烂的道袍", 5000, 8,  "只可远观不可亵玩！"},
		{3, "生锈的铁剑", 8000, 10, "新手专用"},
		{4, "无极袍",     13000, 5, "刀枪不入，水火不侵"},
		{5, "直升1级丹",  83000, 10, "吃了以后保准还想再吃再吃再吃。。。"},
	};
	propsCount = sizeof(propArray) / sizeof(Prop);
	props = propArray;//设定指针的指向
	static Player playerArray[] = {
		{1, "超级毛毛虫", "123456",.gold = 5000000,.bag.max = 8},
		{2, "塔罗奥特曼", "123456",.gold = 150000,.bag.max = 8},
		{3, "元始天尊之徒", "123456",.gold = 500000,.bag.max = 8},
		{4, "星河", "123456",.gold = 1150000,.bag.max = 8}
	};
	playerCount = 4;
	players = playerArray;

}
void ShowProps()
{
	int i;
	if (props == NULL) return;
	printf("%-5s%-14s%-7s\t库存\t商品介绍\n", "编号", "名称", "单价");
	for (i = 0; i < propsCount; i++)
	{
		printf("%-5d%-14s%-7.0lf\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
	}
}
void ShowPlayers()
{
	int i, j;
	if (players == NULL) return;
	printf("编号\t%-14s金币\n", "名称");
	for (i = 0; i < playerCount; i++)
	{
		printf("%d\t%-14s%.0lf\n", players[i].id, players[i].name, players[i].gold);
		for (j = 0; j < players[i].bag.count; j++)
		{
			printf("\t%s\t%d\t", players[i].bag.props[j].name, players[i].bag.props[j].stock);
		}
		printf("\n");
	}

}







