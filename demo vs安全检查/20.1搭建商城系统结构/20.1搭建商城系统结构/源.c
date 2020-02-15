#include "store.h"
int main()
{
	int key;
	//初始化游戏数据
	Init();
	printf("\n*********交易前************************\n\n");
	//2、打印这些初始化数据
	ShowProps();
	ShowPlayers();
	while (1)
	{
		
		key = _getch() - 48;//不减48，key==输入字符的ASCII码

		if (key == 0)
		{
			break;
		}
		if (key < 0 || key>10)
		{
			printf("请输入0-4之间的数!\n");
			continue;
		}
	
		Trade(&players[0], key);
		system("cls");//可用覆盖法优化
		printf("\n\n*********交易后************************\n");
		ShowProps();
		ShowPlayers();
		printf("按0结束交易！\n");
	}
	


	system("pause");
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
		if (propId == props[i].id) 
		{
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
		if (propId == props[i].id) 
		printf("钱包都是瘪的，这里可是看钱的社会，%s您买不起！\n", props[propId-1].name);
		return;
	}
	if (player->bag.props[7].id != 0)//player->bag.props[7].id 默认值为零，若有道具，player->bag.props[7].id != 0
		//(player->bag.count >= player->bag.max && player->bag.count != 0)
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
		strcpy_s(player->bag.props[newIndex].name, tradeProp->name);
		strcpy_s(player->bag.props[newIndex].desc, tradeProp->desc);
		player->bag.count++;
	}
}
void Init()
{
	//1、初始化数据
	static Prop propArray[] = 
	{
		{1, "双倍经验卡", 3000, 20, "双击666"},
		{2, "腐烂的道袍", 5000, 20,  "只可远观不可亵玩！"},
		{3, "生锈的铁剑", 8000, 20, "新手专用"},
		{4, "无极袍",     13000, 20, "刀枪不入，水火不侵"},
		{5, "封神榜",  99999, 20, "内有三百六十五位仙神，威力无穷"},
		{6, "3倍经验卡", 3000, 20, "双击6666"},
		{7, "布衣", 5000, 20,  "刀枪可入，水火可侵"},
		{8, "玄铁剑", 8000, 20, "一般人可用不了"},
		{9, "无极袍",     13000, 20, "刀枪不入，水火不侵"},
	

	};

	static Player playerArray[] = 
	{
		{1, "大表哥", "123456"},
		{2, "二表哥", "123456",playerArray[1].bag.max = 8},
		{3, "三表哥", "123456",playerArray[2].gold = 200000,playerArray[2].bag.max = 8},
		{4, "四表哥", "123456",playerArray[3].gold = 400000,playerArray[3].bag.max = 8}
	};
	playerArray[0].gold = 100000;
	playerArray[0].bag.max = 8;
	playerArray[1].gold = 200000;


	propsCount = sizeof(propArray) / sizeof(Prop);
	playerCount = sizeof(playerArray) / sizeof(Player);
	props = propArray;//设定指针的指向
	players = playerArray;//设定指针的指向
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
	printf("\n");
}

void ShowPlayers()
{
	int i;//第i个玩家
	int j;//第j个道具
	if (players == NULL) return;
	printf("编号\t%-14s金币\t\t道具\n", "名称");
	for (i = 0; i < playerCount; i++)
	{
		printf("%d\t%-14s%.2lf\n", players[i].id, players[i].name, players[i].gold);
		
		for (j = 0; j < players[i].bag.count; j++)
		{
			if ( players[i].bag.props[j].stock == 0)
			{
				continue;
			}
			printf("\t\t\t\t\t%-10s\t%d\n", players[i].bag.props[j].name, players[i].bag.props[j].stock);
		}
		
		printf("\n");
	}
}
