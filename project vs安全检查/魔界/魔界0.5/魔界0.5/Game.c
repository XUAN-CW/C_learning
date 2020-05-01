/************************************************************************
 *  Project:	  魔界
 *  Description:  绘蓝杯参赛作品，MUD游戏
				  作者水平有限，本版本涉及内容仅到结构体，有所提升后将继续用本项目进行练习
 *  Version:	  0.5
 *  Date:		  2018-12-14
 *  Author:		  禤某
 ************************************************************************
 *  Copyright 2018 by GUET
 ************************************************************************/


#include "Game.h"

int X = 3, Y = 4;				//出生地坐标
int walkX = 0, walkY = 0;		//执行行走地图指令前的人物所在的坐标，若人物等级不够，行走失败，则返回此坐标
int i = 0;						//临时变量，循环时使用，使用时注意赋值，一定要现做现用
int j = -1;						//临时变量，循环时使用，使用时注意赋值，一定要现做现用
int bagY = 0;					//背包物品栏中物品的坐标
int bagWalk = 0;
int range = 0;					//背包中当前物品所在的范围，用于实现物品栏滚动效果
int walkFailure = 0;			//等级不够，不能进入地图，该变量用于验证是否进入地图失败
int WearEquipmentFailure = 0;
int bagPropCount;
int * ptr_bagPorpCount = &bagPropCount;
extern char key;
Prop emptyProp;					//Prop类型的临时变量
const Prop constEmptyProp;		//用于覆盖原来的道具，达到去掉该道具的效果
Player * currPlayer;
const Player originalPlayer = { 999, "剑士", 5,5,10,0.1,0.4,6,0,0.4,1000,5,0 };

Prop weapons[] =
{
	//编号 名称 级别 攻击力 防御力 血量 闪避率 暴击率 魔力值 经验值 库存或玩家背包中的叠加数量 单价 功能描述
	{101, "一字长蛇剑"	, WEAPON, 13, 120, 610, 180, 131, 131, 113, 13, 1, 10000, "犹如巨蟒出击，攻击凌厉！"},
	{102, "二龙汲水珠"	, WEAPON, 15, 104, 810, 140, 151, 151, 115, 15, 1, 10000, "高度的灵活性，玄妙无比！"},
	{103, "三叉海神戟"	, WEAPON, 10, 140, 710, 160, 101, 101, 110, 10, 1, 10000, "重达十万八千斤，威力无穷！"},
	{104, "四方苦禅杖"	, WEAPON, 16, 190, 910, 190, 161, 161, 116, 16, 1, 10000, "极度彰显了少林作为中原武林第一大派和佛门贵地的崇高地位。"},
	{105, "五虎攒羊锤"	, WEAPON, 10, 150, 210, 140, 101, 101, 110, 10, 1, 10000, "唯有能与元素沟通的人可以唤醒它的真正力量。"},
	{106, "六合迎风枪"	, WEAPON, 18, 180, 310, 160, 181, 181, 118, 18, 1, 10000, "当年兵器谱排名第二，第一是小李他妈的飞刀！"},
	{107, "七星斩将矛"	, WEAPON, 10, 160, 210, 110, 101, 101, 110, 10, 1, 10000, "矛尖有如白蛇吐信，是令敌将闻风丧胆的象征！"},
	{108, "八卦金锁鞭"	, WEAPON, 13, 180, 810, 170, 131, 131, 113, 13, 1, 10000, "打在身上，仿佛是幻影涰连，遮日蔽天！"},
	{109, "九转乾坤圈"	, WEAPON, 10, 140, 910, 106, 101, 101, 110, 10, 1, 10000, "金色镯子，可翻江倒海，震荡乾坤！"},
	{110, "辟邪犀"		, WEAPON, 12, 130, 610, 170, 121, 121, 112, 12, 1, 10000, "一块能解天下百毒的透明佩玉。"},
	{111, "帝皇剑"		, WEAPON, 10, 120, 210, 150, 101, 101, 110, 10, 1, 10000, "上古三皇五帝用过的宝剑！"},
	{112, "玄铁剑"		, WEAPON, 20, 202, 610, 200, 202, 202, 220, 20, 2, 20000, "一般人可用不了"},
};
Prop armors[] =
{
	{201, "道袍",		 ARMOR,3,3,3,3,3,3,3,3,1,3,  "只可远观不可亵玩！"},
	{202, "荆棘之甲",	 ARMOR,4,4,4,4,4,4,4,4,1,4,  "取日月之精华，反弹伤害！"},
	{203, "无极袍",	 ARMOR,4,4,4,4,4,4,4,4,1,4,  "刀枪不入，水火不侵"},

};
Prop goods[] =
{
	{1, "普通帝皇剑",WEAPON,1,1,1,1,1,1,1,1,1,15000, "上古三皇五帝用过的宝剑！"},
	{2, "良品帝皇剑",WEAPON,1,1,1,1,1,1,1,1,1,26000, "上古三皇五帝用过的宝剑！"},
	{3, "上品帝皇剑",WEAPON,1,1,1,1,1,1,1,1,1,37000, "上古三皇五帝用过的宝剑！"},
	{4, "极品帝皇剑",WEAPON,1,1,1,1,1,1,1,1,1,48000, "上古三皇五帝用过的宝剑！"},
	{5, "腐烂道袍",ARMOR,15,250,300,210,330,240,157,300,1,30000,  "只可远观不可亵玩！"},


};
Map mapArray[8][8] =
{
	{
		{1, "西玄山脉", 1, {0, 0}, "周回三千里，六甲四十八塘，传说有六条龙脉，三十六道石门位于山脉中央，不知是何人所留... ..."},
		{2, "无尽火域", 1, {1, 0}, "火，到处都是火！"},
		{3, "凤鸣山",   1, {2, 0}, "凤凰栖居之地。"},
		{4, "野猪林",   1, {3, 0}, "野猪林里到处都是野猪... ..."},
		{5, "清虚观",   1, {4, 0}, "洞虚内观，内有灵府，……清虚之东窗，林屋之隔沓，……真洞仙馆也！"},
		{6, "蚕  洞",   1, {5, 0}, "满地蚕茧，漫天飞蛾。"},
		{7, "猪笼寨",   1, {6, 0}, "内有高手。"},
		{8, "冰火岛",   1, {7, 0}, "○|￣|_，编不出来了，我选择狗带[手动狗头]"}
	},
	{
		{9, "迷  宫",  1, {0, 1}, "这里是高昌迷宫，也是一个十分神秘的地方，连阅历及其丰富的大前辈都不知道这会发生什么事情。"},
		{10, "太空城", 1, {1, 1}, "快走，这里没有氧气！"},
		{11, "轩辕岭", 1, {2, 1}, "一条山岭，绿油油的，不过从远处看去，岭上透出一层杀气，问过路人才知道，这里就是早有耳闻的轩辕岭！"},
		{12, "华  山", 1, {3, 1}, "自古华山一条路。"},
		{13, "嵩  山", 1, {4, 1}, "佛门重地。"},
		{14, "京  师", 1, {5, 1}, "国运所在之地。"},
		{15, "青  楼", 1, {6, 1}, "我就知道你会来这里→_→"},
		{16, "神秘岛", 1, {7, 1}, "这里很神秘，神秘到没什么人能来到这里。"}
	},
	{
		{17, "戈  壁", 1, {0, 2}, "这里没有水，没有树，没有草，死一般的像个地狱。"},
		{18, "葫芦谷", 1,{1, 2}, "葫芦峪里似乎只有葫芦。远看还真像只大葫芦。"},
		{19, "石  窟", 1, {2, 2}, "╮(￣⊿￣)╭"},
		{20, "终南山", 1, {3, 2}, "道家福地。"},
		{21, "国子监", 1, {4, 2}, "这里有美女老师，也有校花，当然，少不了校园恶霸ㄟ(▔ ,▔)ㄏ"},
		{22, "客  栈", 1, {5, 2}, "风云汇聚之地，这里可以打听到你想知道的东西"},
		{23, "玉皇顶", 1, {6, 2}, "一个永远不会安定的地方：泰山玉皇顶。这里是一个充满着厮杀的地方，无时无刻不充斥着暴力、仇杀的地方。"},
		{24, "灵蛇岛", 1, {7, 2}, "别的没有，就是蛇多!"}
	},
	{
		{25, "三十六峰", 1,{0, 3}, "所谓三十六峰者，骈列舒张，横绝天表，众岫叠岭，效奇献秀，尽在一览。"},
		{26, "摩天崖",   1,{1, 3}, "伸手就能碰到天。"},
		{27, "武  境",	 1,{2, 3}, "这里只接受强者！"},
		{28, "后  山",   1,{3, 3}, "终终南后山的景色就是不一般，到处盛开着叫不上名字的各色小花，几只蜜蜂在花间飞舞，沿着一条花间小路来到一个古墓前，上面写着：活死人墓。"},
		{29, "西玄山脉", 1,{4, 3}, "周回三千里，六甲四十八塘，传说有六条龙脉，三十六道石门位于山脉中央，不知通向何方... ..."},
		{30, "平天府",   1,{5, 3}, "(*'へ'*)"},
		{31, "二十四桥", 1,{6, 3}, "二十四桥明月夜，玉人何处教吹箫！"},
		{32, "蓬莱仙境", 1,{7, 3}, "云雾缭绕的蓬莱仙境自古以来都似乎隐藏着天大的秘密，谁能真正揭开这里的迷呢？"}
	},
	{
		{33, "力量山", 1, {0, 4}, "名字是我滚键盘得来的，感觉自己被掏空。"},
		{34, "小康河", 1, {1, 4}, "名字是我滚键盘得来的，感觉自己被掏空。"},
		{35, "百花谷", 1, {2, 4}, "哇，这里太美了，这里的很多花都叫不上名字！"},
		{36, "圣人村", 1, {3, 4}, "很久很久以前，大祭司路经此地，断定此地有大气运，必出圣人，故名圣人村。但目前为止，此地还没有出过圣人... ..."},
		{37, "天宁寺", 1, {4, 4}, "佛家地天宁寺，每天前来进香之人络绎不绝。可从进香之人求愿灵验的程度上让人不得不产生怀疑。"},
		{38, "积善堂", 1, {5, 4}, "抽奖的地方"},
		{39, "镇江府", 1, {6, 4}, "传说江中有龙王。"},
		{40, "浅  海", 1, {7, 4}, "小乌龟，好可爱。"}
	},
	{
		{41, "%#@*谷",1, {0, 5}, "不想说了，自行想象吧"},
		{42, "南秋寺",1, {1, 5}, "今天看了《修真聊天群》，借个名字用用"},
		{43, "迷踪林",1, {2, 5}, "这里是迷踪林，人们总说这片树林不要轻易走进，因为它十分危险，据说有不少人走进去就再也没有出来过。"},
		{44, "孔雀山",1, {3, 5}, "这里金湖碧波荡漾，森林茂密，孔雀争相开屏、鸵鸟欢唱迎宾，梅花鹿湖畔戏水，人与自然和谐相融。"},
		{45, "大明湖",1, {4, 5}, "大明湖，明湖大，大明湖里有蛤蟆，一戳一蹦跶！"},
		{46, "万仞堂",1, {5, 5}, "什么兵器都有！"},
		{47, "海滩三",1, {6, 5}, "这里是海滩！！！"},
		{48, "深  海",1, {7, 5}, "-_-!"}
	},
	{
		{49, "隗  宗", 1, {0, 6}, "来到了隗宗，这里好像什么东西都与其他地方有些不同。"},
		{50, "三角崖", 1, {1, 6}, "○|￣|_，编不出来了，我选择狗带[手动狗头]"},
		{51, "蝴蝶谷", 1, {2, 6}, "为何蝴蝶谷中会有如此众多的蝴蝶？是不是因为发生了什么不可告人的事情？看来只有有缘人才能知道了。"},
		{52, "康博堡", 1, {3, 6}, "想抓个写小说的帮我写介绍T_T"},
		{53, "疯人院", 1, {4, 6}, "有三硝基甲苯出售。"},
		{54, "海滩二", 1, {5, 6}, "这里是海滩！！"},
		{55, "海  沟", 1, {6, 6}, "小心，有巨型生物出没！"},
		{56, "石  头", 1, {7, 6}, "石头下似乎有粉红色的生物闪过... ..."}
	},
	{
		{57, "石  府",   1, {0, 7}, "天机石府里只有石头。石头当然不会是乱放的。"},
		{58, "三角州",   1, {1, 7}, "面积较大，土层深厚，水网密布，表面平坦，土质肥沃，易有洪涝。"},
		{59, "忏悔崖",   1, {2, 7}, "远古魔道巨擘封印于此，能听到隐隐约约的哭声。"},
		{60, "绿  岛",   1, {3, 7}, "此岛危险！"},
		{61, "海滩一",   1, {4, 7}, "这里是海滩！"},
		{62, "紫光亭",   1, {5, 7}, "亭中有棋，无人在下。"},
		{63, "人像屋",   1, {6, 7}, "位于海底世界的这里，竟有一座屋子，是谁住在这里呢？"},
		{64, "菠萝神殿", 1, {7, 7}, "这里有着可怕的存在，只有强者才能探索这里！"}
	}
};
Player players[] =
{
	//编号 名称 攻击力 防御力 血量 闪避率 暴击率 魔力值 经验值 级别 金币数量 当前所在地图的坐标 装备的武器 装备的防具 背包
	{1, "大表哥", 200,100,1500,0.1,80,100,150,50,100000,3,100,{4,3},weapons[4],armors[2],
	{1,2,50,{weapons[9],weapons[10],weapons[4],weapons[5],weapons[6],weapons[7],weapons[8],weapons[9],weapons[10]}}},//
};


Monster monsterArray[] =
{
	{1, "海绵宝宝",		9, 9999, 500, 9, 9999, 9995, 99991,1,{weapons[2]}, {7, 7}},
	{2, "章鱼哥",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{6, 7}},
	{3, "派大星",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{7, 6}},
	{4, "犀利哥",		2, 200, 8, 2, 5, 10, 1,1,{weapons[2]},{0, 0}},
	{5, "地狱男爵",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{3, 4}},
	{6, "恶魔小七",		8, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{4, 3}},
	{7, "猩红小月亮",	7, 3000, 5, 2, 5,  5, 1,1,{weapons[2],weapons[3]},{3, 4}},
	{8, "海阔天空鸟",	6, 100, 5, 2, 5,  5, 1,1,{weapons[2]},{0, 0}},

};

void ShowMonsters()
{
	int monsterCount = sizeof(monsterArray) / sizeof(Monster);
	int pkMonsterId = -1;
	int monsterNum;
	const char *levelNames[] =
	{ "乳臭未干", "初出茅庐", "粗通皮毛", "青年才俊", "略有小成", "心领神会", "出类拔萃", "所向无敌", "天人合一" };
	Clear(MARGIN_X, INFO_START_Y, 7);
	//找出当前地图怪物
	Monster pkMonsters[9];
	/* 查找所有怪物中，坐标是当前地图的怪物 */
	for (i = 0, monsterNum = 0; i < monsterCount; i++)
	{
		if (monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0)//state != 0 没死
		{
			pkMonsters[monsterNum] = monsterArray[i];
			if (monsterNum == 9)
			{
				break;
			}
			monsterNum++;
		}
	}
	//查找完毕，有j个怪物
	SetPosition(MARGIN_X + 10, INFO_START_Y);
	if (monsterNum == 0)
	{
		printf("当前地图一片祥和！");
		return;
	}
	SetPosition(MARGIN_X + 5, INFO_START_Y);
	for (i = 0; i < monsterNum; i++)
	{
		if (i != 0 && i % 3 == 0)
		{
			SetPosition(MARGIN_X + 5, INFO_START_Y + 2 + i / 3);
		}
		printf("%d.%s(%s)\t", i + 1, pkMonsters[i].name, levelNames[pkMonsters[i].level - 1]);
	}
	SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
	printf("请输入要攻击的对象：（输0返回）");
	do
	{
		pkMonsterId = _getch();
		pkMonsterId -= 48;					//ascii码转换为数字
		/* 验证用户输入 */
		if (pkMonsterId == 0)
		{
			ShowMap();
			return;
		}
		if (pkMonsterId > monsterNum || pkMonsterId < 0)
		{
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("怪物不存在                             ");
		}
		else
		{
			Fight(pkMonsterId, pkMonsters[pkMonsterId - 1]);
		}
		SetPosition(MARGIN_X + 5, INFO_START_Y);
		for (i = 0; i < monsterNum; i++)
		{
			if (i != 0 && i % 3 == 0)
			{
				SetPosition(MARGIN_X + 5, INFO_START_Y + 2 + i / 3);
			}
			printf("%d.%s(%s)\t", i + 1, pkMonsters[i].name, levelNames[pkMonsters[i].level - 1]);
		}

	} while (1);
}

void Fight(int monsterId, Monster  pkMonsters)
{
	int fightCount = 1;								//pk的轮数
	double multipleRandom = 1;						//随机倍数
	int playerInjure;								//玩家受到的伤害
	int monsterInjure;								//怪物受到的伤害
	int money;										//金钱
	int exp;										//经验
	Player pkPlayer = *(currPlayer);
	Monster pkMonster = pkMonsters;
	Clear(MARGIN_X, INFO_START_Y, 7);
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	while (1)
	{
		srand(time(NULL));
		//产生0.8~1.2的随机倍数
		multipleRandom = rand() % 400 + 800;		
		multipleRandom /= 1000;						
		fightCount++;
		SetPosition(MARGIN_X, INFO_END_Y - 2);
		printf("%s", BLANK_78);
		if (pkPlayer.agility > pkMonster.agility)
		{
			monsterInjure = floor((pkPlayer.atk - pkMonster.defence)*multipleRandom);
			monsterInjure = (monsterInjure > 0) ? monsterInjure : 1;

			if (pkMonster.miss < rand() % 100)			//中招了
			{
				if (pkPlayer.crit > rand() % 100)		//中招且被暴击
				{
					monsterInjure *= 2;
					SetPosition(MARGIN_X + 64, INFO_END_Y - 2);
					printf("暴击");
				}
				pkMonster.hp -= monsterInjure;
			}
			else										//没中招
			{
				SetPosition(MARGIN_X + 64, INFO_END_Y - 2);
				printf("miss");
			}
		}
		else
		{
			playerInjure = floor((pkMonster.atk - pkPlayer.defence)*multipleRandom);
			playerInjure = (playerInjure > 0) ? playerInjure : 1;

			if (pkMonster.miss < rand() % 100)
			{
				if (pkMonster.crit > rand() % 100)
				{
					playerInjure *= 2;
					SetPosition(MARGIN_X + 34, INFO_END_Y - 2);
					printf("暴击");
				}
				pkPlayer.hp -= playerInjure;
			}
			else
			{
				SetPosition(MARGIN_X + 34, INFO_END_Y - 2);
				printf("miss");
			}
			pkPlayer.agility--;
		}
		i = pkPlayer.agility;
		pkPlayer.agility = pkMonster.agility;
		pkMonster.agility = i;

		SetPosition(MARGIN_X + 5, INFO_END_Y - 2);
		printf("战斗第%d轮", fightCount / 2);
		SetPosition(MARGIN_X + 17, INFO_END_Y - 2);
		printf("%sHP:%-6d", pkPlayer.name, pkPlayer.hp);
		SetPosition(MARGIN_X + 44, INFO_END_Y - 2);
		printf("%sHP:%-6d ", pkMonster.name, pkMonster.hp);
		SetPosition(98, INFO_END_Y - 1);
		Sleep(200);
		/* 赢了 */
		if (pkMonster.hp <= 0)
		{
			exp = pkMonster.Money * multipleRandom;
			money = pkMonster.Money * multipleRandom;
			currPlayer->exp += exp;								//获得的经验
			currPlayer->gold += money;							//获得的金钱
			if (currPlayer->luck > rand() % pkMonster.luck)		//获得的装备
			{
				currPlayer->bag.props[bagPropCount] = pkMonster.props[rand() % 2];//错误rand() % MONSTER_PROP_MAX - 1
				if (currPlayer->bag.props[bagPropCount].id != 0)
				{
					SetPosition(CENTERED - 6, INFO_END_Y - 4);
					printf("恭喜你，获得了[%s]!", currPlayer->bag.props[bagPropCount].name);
					SeekRepetition(currPlayer->bag);
				}
			}
			SetPosition(MARGIN_X, INFO_END_Y - 1);
			printf("%s", BLANK_78);
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("经过艰苦的战斗，您战胜了《%s》，获得%d经验，%d金币！", pkMonster.name, exp, money);
			if (currPlayer->exp > currPlayer->level * 1000)
			{
				currPlayer->exp -= currPlayer->level * 1000;
				currPlayer->level++;
				Init();
			}
			//printf("经过艰苦的战斗，您战胜了《%s》，获得%d经验，%d金币！",
			//pkMonster.name,pkMonster.Money * multipleRandom,pkMonster.Money * multipleRandom);为什么会出错？
			break;

		}
		/*输了*/
		if (pkPlayer.hp <= 0)
		{
			SetPosition(MARGIN_X, INFO_END_Y - 1);
			printf("%s", BLANK_78);
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("《%s》在与《%s》的战斗中壮烈牺牲，一代天才就此陨落！", currPlayer->name, pkMonster.name);
			currPlayer->level--;
			Init();
			break;
		}
	}

}


void ShowWelcome()
{
	/* 显示游戏的欢迎信息 */
	SetPosition(MARGIN_X, 0);
	printf("%s", SEP);
	SetPosition(MARGIN_X, 1);
	printf("|");
	SetPosition(CENTERED, 1);
	printf("欢迎来到魔界！");
	SetPosition(MARGIN_X + 77, 1);
	printf("|");
	SetPosition(MARGIN_X, 2);
	printf("%s", SEP);
}

/* 显示游戏地图 */
void ShowMap()
{
	
	int i, j;
	Clear(MARGIN_X, 4, 8);
	printf("\n");
	for (i = 0; i < 8; i++)
	{
		SetPosition(MARGIN_X, MAP_START_Y + i);
		for (j = 0; j < 8; j++)
		{
			if (j == 0)
				printf("|   ");
			//地图更改当前地图文字的颜色和背景色
			if (i == Y && j == X)
			{
				SetColor(12, 15);
			}
			printf("%-9s", mapArray[i][j].name);
			//打印完当前地图后，将颜色据变回默认颜色
			SetColor(10, 0);
		}
		SetPosition(MARGIN_X + 77, 3 + i);
		printf("|");
	}
	SetPosition(MARGIN_X, MAP_END_Y);
	printf(SEP);
	ShowMapInfo();
	ShowInfomation();
	if (walkFailure != 0)
	{
		SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
		printf("%d级才能进入%s，某人的等级不够哦→_→", mapArray[walkX][walkY].level, mapArray[walkX][walkY].name);
		walkFailure = 0;
	}
}

void ShowMapInfo()
{
	/* 在信息界面显示当前地图的信息 */
	//1.清除信息窗的信息
	Clear(MARGIN_X, INFO_START_Y, 7);
	//2.显示当前玩家所在地图的信息
	SetPosition(MARGIN_X + 25, INFO_START_Y);
	printf("当前玩家所在地图：《%s》", mapArray[Y][X].name);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
	//需要控制文字显示的行
	char * desc = mapArray[Y][X].desc;
	int descLen = strlen(desc);
	int i;
	for (i = 0; i < descLen; i++)
	{
		//控制此行只能打印60个中文字符
		if (i != 0 && i % 60 == 0)
		{
			SetPosition(MARGIN_X + 10, INFO_START_Y + 1 + i / 60);
		}
		printf("%c", desc[i]);
	}
}

void ShowInfomation()
{
	/* 显示游戏地图下方的游戏信息 */
	//信息窗口一共有7行
	SetPosition(MARGIN_X, INFO_START_Y);
	int i;
	for (i = 0; i < 7; i++)
	{
		SetPosition(MARGIN_X, INFO_START_Y + i);
		printf("|");
		SetPosition(MARGIN_X + 77, INFO_START_Y + i);
		printf("|");
	}
	SetPosition(MARGIN_X, INFO_START_Y + 7);
	printf(SEP);
}

void ShowMainMenu()
{

	/* 显示游戏的主菜单 */
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y);
	printf("游戏菜单：");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 1);
	printf("1、自我欣赏");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 2);
	printf("2、查找怪物");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 3);
	printf("3、回家");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 4);
	printf("4、购买装备");
}

void ShowPlayerInfo()
{
	//1.清除信息窗的信息
	Clear(MARGIN_X, INFO_START_Y, 7);
	SetPosition(MARGIN_X + 20, INFO_START_Y);
	printf("《%s》的个人资料如下：", currPlayer->name);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
	printf("等级：%d\t血量：%d\t法力：%d\t经验值：%d", currPlayer->level, currPlayer->hp, currPlayer->mp, currPlayer->exp);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
	printf("当前武器：%s(攻击+%d)\t", currPlayer->weapon.name, currPlayer->weapon.atk);
	printf("当前防具：%s(防御力+%d)", currPlayer->armor.name, currPlayer->armor.defence);


}


void SetColor(int foreColor, int backColor)
{
	/** 
	 * 设置文字颜色
	 * 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝 
	 * 10-淡绿 11-淡浅绿  12-淡红 13-淡紫 14-淡黄 15-亮白 
	 */
	HANDLE winHandle;   //句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);//https://blog.csdn.net/qq_36771850/article/details/79187836
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;   //句柄，不会
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标的坐标
	SetConsoleCursorPosition(winHandle, pos);
}

void Clear(int x, int y, int rowCount)
{
	/* 从x、y坐标开始，清rowCount行 */
	//每行清除78个字符-打印78个空格
	int i;
	for (i = 0; i < rowCount; i++)
	{
		SetPosition(x, y + i);
		printf("%s", BLANK_78);
	}
}

void Move(int x, int y)
{
	Y = x;
	X = y;
	//刷新地图
	ShowMap();
}

void walk(char key)
{
	i = X;
	j = Y;
	if (key == 38 || key == 72)//用户按了上键
	{
		Y--;
	}
	else if (key == 39 || key == 77)//右
	{
		X++;
	}
	else if (key == 40 || key == 80)//下
	{
		Y++;
	}
	else if (key == 37 || key == 75)//左
	{
		X--;
	}
	walkX = Y;
	walkY = X;
	if (currPlayer->level < mapArray[walkX][walkY].level)
	{
		walkFailure++;
		X = i;
		Y = j;
	}
	if (X > 7) X = 0;
	if (X < 0) X = 7;
	if (Y > 7) Y = 0;
	if (Y < 0) Y = 7;
}

void Init()//初始化游戏数据
{
	double multipleGrowth = 1;
	currPlayer = &players[0];//当前玩家
	for (i = 0; i < currPlayer->level; i++)
	{
		multipleGrowth *= LEVEL_GEOWTH_RATE;
	}
	int int_multipleGrowth = multipleGrowth;
	//升级后，属性 = 初始属性 * 成长倍数
	currPlayer->agility = originalPlayer.agility * int_multipleGrowth;
	currPlayer->atk = originalPlayer.atk * int_multipleGrowth;
	currPlayer->crit = originalPlayer.crit*currPlayer->level;
	currPlayer->defence = originalPlayer.defence * int_multipleGrowth;
	currPlayer->hp = originalPlayer.hp * int_multipleGrowth;
	currPlayer->luck = originalPlayer.luck + currPlayer->level;
	currPlayer->miss = originalPlayer.miss * multipleGrowth;
	currPlayer->mp = originalPlayer.mp * int_multipleGrowth;
	EquipmentAttribute_add(currPlayer->weapon);//以此类推，将装备的属性加到玩家上
	EquipmentAttribute_add(currPlayer->armor);
}

void Box(int x, int y, int rowCount)
{
	SetPosition(x, y - 1);
	printf("%s", SEP);
	for (i = 0; i < rowCount; i++)
	{

		SetPosition(x, y + i);
		printf("|");
		SetPosition(x + COL - 1, y + i);
		printf("|");
	}
	SetPosition(x, y + i);
	printf("%s", SEP);
};


/*商城*/
void Store()
{
	char propId;
	Clear(MARGIN_X, MAP_START_Y, 25);
	do {
		ShowGoods();
		ShowBag();
		propId = _getch();
		SetPosition(MARGIN_X, 27);
		printf("%s", BLANK_78);
		if (propId == '0')
		{
			break;
		}
		BagWalk(propId);
		if (propId == '1' || propId == '2' || propId == '3' || propId == '4' || propId == '5')//确保了只有五个商品可以出售
			Trade(currPlayer, propId);

	} while (1);
	//重新显示地图
	ShowMap();
	Clear(MARGIN_X, MAINMENU_START_Y, 7);
	ShowMainMenu();
}

void Trade(Player * currPlayer, int propId)
{
	int goodsCount;
	int bagPropCount;
	int bagPropId_tradePropId = -1;		//判断背包中有没有要交易的道具
	Prop *tradeProp = NULL;				//要购买的商品指针
	goodsCount = sizeof(goods) / sizeof(Prop);
	propId -= 48;

	//有商品
	for (i = 0; i < goodsCount; i++)
	{
		if (propId == goods[i].id)
		{
			tradeProp = &goods[i];		//找到了 
			break;
		}
	}
	if (i == goodsCount)				//没有找到
	{
		SetPosition(MARGIN_X, 27);
		printf("没有找到您需要的商品，请重新选择！");
		return;
	}
	//有钱	
	if (currPlayer->gold < tradeProp->price)
	{
		SetPosition(MARGIN_X, 27);
		printf("钱包都是瘪的，这里可是看钱的社会！\n");
		return;
	}
	//背包还能装
	//计算背包之中道具的数目并检验背包中有无要交易道具的编号
	//跳出循环时bagPropCount==背包中道具的数目
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0 || bagPropCount == currPlayer->bag.capacity; bagPropCount++)
	{
		currPlayer->bag.props[bagPropCount];
		if (currPlayer->bag.props[bagPropCount].id == propId)
		{
			bagPropId_tradePropId = tradeProp->id;									//背包中已有要交易的道具
		}
	}
	if (bagPropCount == currPlayer->bag.capacity && bagPropId_tradePropId == -1)	//背包已满且背包中没有要交易的商品
	{
		printf("背包已满！");
		return;
	}

	/*交易开始*/
	if (bagPropId_tradePropId != -1)												//背包中有要交易的商品
	{
		for (i = 0;; i++)
		{
			if (currPlayer->bag.props[i].id == bagPropId_tradePropId)
			{
				currPlayer->bag.props[i].stock++;
				currPlayer->gold -= tradeProp->price;
				return;
			}

		}
	}
	if (bagPropCount != currPlayer->bag.capacity && bagPropId_tradePropId == -1)	//背包位置未满且背包中无要交易的商品
	{
		//背包中第bagPropCount个位置为空，将商品复制到背包中
		currPlayer->bag.props[bagPropCount].atk = tradeProp->atk;					
		currPlayer->bag.props[bagPropCount].crit = tradeProp->crit;
		currPlayer->bag.props[bagPropCount].defence = tradeProp->defence;
		currPlayer->bag.props[bagPropCount].exp = tradeProp->exp;
		currPlayer->bag.props[bagPropCount].hp = tradeProp->hp;
		currPlayer->bag.props[bagPropCount].id = tradeProp->id;
		currPlayer->bag.props[bagPropCount].leve = tradeProp->leve;
		currPlayer->bag.props[bagPropCount].miss = tradeProp->miss;
		currPlayer->bag.props[bagPropCount].mp = tradeProp->mp;
		currPlayer->bag.props[bagPropCount].price = tradeProp->price;
		currPlayer->bag.props[bagPropCount].stock = tradeProp->stock;
		currPlayer->bag.props[bagPropCount].category = tradeProp->category;
		strcpy_s(currPlayer->bag.props[bagPropCount].desc, tradeProp->desc);
		strcpy_s(currPlayer->bag.props[bagPropCount].name, tradeProp->name);
	}
	currPlayer->gold -= tradeProp->price;
	return;
}

void ShowGoods()
{
	int goodsCount;
	goodsCount = sizeof(goods) / sizeof(Prop);
	SetPosition(MARGIN_X + 34, 3);
	printf("商城");
	SetPosition(MARGIN_X, 5);
	printf(" %-6s%-12s%-10s%s\n", "编号", "道具", "价格", "描述");
	SetPosition(MARGIN_X + COL - 1, 5);
	for (i = 0; i < goodsCount; i++)
	{
		SetPosition(MARGIN_X, 6 + i);
		printf(" %-6d%-12s%-10d%s\n", goods[i].id, goods[i].name, goods[i].price, goods[i].desc);
		SetPosition(MARGIN_X + COL - 1, 6 + i);
	}
	Box(MARGIN_X, 3, 8);
}

void ShowBag()
{
	int rangeMax;
	char * ptr_propDescription = NULL;
	int propDescriptionLen;
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	*ptr_bagPorpCount = bagPropCount;
	PropFlashback(currPlayer);
	Clear(MARGIN_X, 13, 13);
	SetPosition(MARGIN_X + 34, 12);
	printf("背包");
	printf("                         金币:%-8d", currPlayer->gold);
	rangeMax = range + 11;
	//不够十一行，全部打完，超过十一行，只打十一行
	for (range, bagWalk = 0; range < rangeMax; bagWalk++, range++)
	{
		SetPosition(MARGIN_X + 2, 14 + bagWalk);
		if (currPlayer->bag.props[bagY].id == 0)
		{
			bagY--;
		}
		if (bagY == range)
		{
			SetColor(12, 15);
		}
		printf("%-12s\n", currPlayer->bag.props[range].name);
		SetColor(10, 0);
		if (bagY == range)
		{
			i = 0;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("攻击+%-8d", currPlayer->bag.props[range].atk);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("防御+%-8d", currPlayer->bag.props[range].defence);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("血量+%-8d", currPlayer->bag.props[range].hp);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("魔力+%-8d", currPlayer->bag.props[range].mp);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("敏捷+%-8d", currPlayer->bag.props[range].agility);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("闪避+%.2lf%%   ", currPlayer->bag.props[range].miss);
			i++;;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("暴击+%.2lf%%   ", currPlayer->bag.props[range].crit);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y);
			switch (currPlayer->bag.props[range].category)
			{
			case WEAPON:
				printf("种类：武器");
				break;
			case ARMOR:
				printf("种类：防具");
				break;
			}
			printf("    等级：%-4d", currPlayer->bag.props[range].leve);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 1);
			printf("数目：%-4d", currPlayer->bag.props[range].stock);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 2);
			printf("售价：%d金币       ", currPlayer->bag.props[range].price);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 3);
			printf("描述：");
			ptr_propDescription = currPlayer->bag.props[range].desc;
			propDescriptionLen = strlen(ptr_propDescription);
			SetPosition(CENTERED + 8, 17);
			for (i = 0; i < propDescriptionLen; i++)
			{
				//控制此行只能打印17个中文字符
				if (i != 0 && i % 36 == 0)
				{
					SetPosition(CENTERED + 8, 17 + i / 36);
				}
				printf("%c", ptr_propDescription[i]);
			}
		}
	}
	if (WearEquipmentFailure != 0)
	{
		SetPosition(MARGIN_X, 27);
		printf("%d级才能穿上%s，某人的等级不够哦→_→", currPlayer->bag.props[bagY].leve, currPlayer->bag.props[bagY].name);
		WearEquipmentFailure = 0;
	}
	PropFlashback(currPlayer);
	Box(MARGIN_X, 12, 14);
	range -= 11;
};

void PropFlashback(Player * currPlayer)
{
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	for (i = 0; i < bagPropCount / 2; i++)//失误for (i = 0; i <= bagPropCount / 2; i++)
	{
		emptyProp = currPlayer->bag.props[i];
		currPlayer->bag.props[i] = currPlayer->bag.props[bagPropCount - i - 1];
		//失误currPlayer->bag.props[i]=currPlayer->bag.props[bagPropCount - i] ;
		currPlayer->bag.props[bagPropCount - i - 1] = emptyProp;
	}

}

void BagWalk(char propId)
{
	if (propId == 38 || propId == 72)		//用户按了上键
	{
		bagY--;

	}
	else if (propId == 40 || propId == 80)	//下
	{
		bagY++;
	}
	if (bagY > * ptr_bagPorpCount - 1)
		bagY = 0;
	if (bagY < 0)
		bagY = *ptr_bagPorpCount - 1;
	if (bagY == -1)
		bagY = 0;
	if (bagY < range)
	{
		range = bagY;
	}
	if (bagY > range + 10)
	{
		range = bagY - 10;
	}
}


/*个人信息与装备*/
void Player_Equipment()
{
	char equipmentKey;
	do {
		ShowPlayerInformation();
		ShowBag();
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y);
		printf("0、退出");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 1);
		printf("1、穿装备");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 2);
		printf("2、卸下全部装备");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 3);
		printf("9、出售该装备");

		equipmentKey = _getch();
		if (equipmentKey == '0')
		{
			break;
		}
		SetPosition(MARGIN_X, 27);
		printf("%s", BLANK_78);
		BagWalk(equipmentKey);
		switch (equipmentKey)
		{
		case '1':
			WearEquipment(currPlayer, bagY);
			break;
		case '2':
			TakeOffAllEquipment(currPlayer, bagY);
			break;
		case '9':
			Sell(currPlayer, bagY);
			break;
		default:
			break;
		}
	} while (1);
	//重新显示地图
	ShowMap();
	Clear(MARGIN_X, MAINMENU_START_Y, 7);
	ShowMainMenu();
};

void ShowPlayerInformation()
{
	double k;
	const char *LuckLevels[] =
	{ "印堂发黑", "天庭饱满", "顺风顺水", "心想事成", "福星高照", "吉人天相", "得天独厚", "洪福齐天", "紫气东来","位面之子" };
	Clear(MARGIN_X, 3, 25);
	Box(MARGIN_X, 3, 8);
	SetPosition(CENTERED - 4, 4);
	printf("%s的个人信息如下：", currPlayer->name);

	SetPosition(MARGIN_X + 5, 6);
	printf("等级：%-12d", currPlayer->level);
	SetPosition(MARGIN_X + 5, 7);
	printf("经验：%-12d   ", currPlayer->exp);
	SetPosition(MARGIN_X + 5, 8);
	printf("武器：%-12s", currPlayer->weapon.name);
	SetPosition(MARGIN_X + 5, 9);
	printf("防具：%-12s", currPlayer->armor.name);

	SetPosition(MARGIN_X + 33, 6);
	printf("攻击：%-12d", currPlayer->atk);
	SetPosition(MARGIN_X + 33, 7);
	printf("防御：%-12d", currPlayer->defence);
	SetPosition(MARGIN_X + 33, 8);
	printf("血量：%-12d", currPlayer->hp);
	SetPosition(MARGIN_X + 33, 9);
	printf("魔力：%-12d", currPlayer->mp);

	SetPosition(MARGIN_X + 59, 6);
	printf("暴击：%.2lf%%", currPlayer->crit);
	SetPosition(MARGIN_X + 59, 7);
	printf("闪避：%.2lf%%", currPlayer->miss);
	SetPosition(MARGIN_X + 59, 8);
	printf("敏捷：%d", currPlayer->agility);
	SetPosition(MARGIN_X + 59, 9);
	for (i = 0, k = 5; k < currPlayer->luck; i++)
	{
		k *= 1.4;
	}
	i = (i > 9) ? 9 : i;
	printf("气运：%s", LuckLevels[i]);
};

void WearEquipment(Player * currPlayer, int bagY)
{
	PropFlashback(currPlayer);
	if (currPlayer->level < currPlayer->bag.props[bagY].leve)
	{
		WearEquipmentFailure++;
		PropFlashback(currPlayer);
		return;
	}
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	/* 先换装备的情况太多，所以先变更人物属性 */
	switch (currPlayer->bag.props[bagY].category)
	{
	case WEAPON:
		EquipmentAttribute_add(currPlayer->bag.props[bagY]);
		EquipmentAttribute_minus(currPlayer->weapon);
		break;
	case ARMOR:
		EquipmentAttribute_add(currPlayer->bag.props[bagY]);
		EquipmentAttribute_minus(currPlayer->armor);
	default:
		break;
	}
	//要更换的装备背包中只有一件
	if (currPlayer->bag.props[bagY].stock == 1)					
	{
		switch (currPlayer->bag.props[bagY].category)
		{
		case WEAPON:
			emptyProp = currPlayer->bag.props[bagY];
			currPlayer->bag.props[bagY] = currPlayer->weapon;
			currPlayer->weapon = emptyProp;
			break;
		case ARMOR:
			emptyProp = currPlayer->bag.props[bagY];
			currPlayer->bag.props[bagY] = currPlayer->armor;
			currPlayer->armor = emptyProp;
			break;
		default:
			break;
		}

	}
	//要更换的装备背包中有多件
	else
	{
		currPlayer->bag.props[bagY].stock--;
		switch (currPlayer->bag.props[bagY].category)
		{
		case WEAPON:
			currPlayer->bag.props[bagPropCount] = currPlayer->weapon;
			currPlayer->weapon = currPlayer->bag.props[bagY];
			currPlayer->weapon.stock = 1;
			break;
		case ARMOR:
			currPlayer->bag.props[bagPropCount] = currPlayer->armor;
			currPlayer->armor = currPlayer->bag.props[bagY];
			currPlayer->armor.stock = 1;
		default:
			break;
		}
	}
	SeekRepetition(currPlayer->bag);
	PropFlashback(currPlayer);
	RandBag(currPlayer);

}

void Sell(Player * currPlayer, int bagY)
{
	int propPrice;
	PropFlashback(currPlayer);
	propPrice = currPlayer->bag.props[bagY].price;
	if (currPlayer->bag.props[bagY].stock > 1)
	{
		currPlayer->bag.props[bagY].stock--;
	}
	else
	{
		currPlayer->bag.props[bagY] = constEmptyProp;
	}
	currPlayer->gold += propPrice;
	RandBag(currPlayer);
	PropFlashback(currPlayer);
	//失误：先PropFlashback(currPlayer); 后RandBag(currPlayer);
}

void TakeOffAllEquipment(Player * currPlayer, int bagY)
{
	EquipmentAttribute_minus(currPlayer->weapon);
	EquipmentAttribute_minus(currPlayer->armor);
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	currPlayer->bag.props[bagPropCount] = currPlayer->weapon;
	currPlayer->bag.props[bagPropCount + 1] = currPlayer->armor;
	currPlayer->weapon = constEmptyProp;
	currPlayer->armor = constEmptyProp;
	RandBag(currPlayer);
	SeekRepetition(currPlayer->bag);
	SeekRepetition(currPlayer->bag);
}

void RandBag(Player * currPlayer)
{
	//prop[j]为最后一件道具的位置,j==-1,背包为空
	for (j = currPlayer->bag.capacity - 1; currPlayer->bag.props[j].id == 0; j--) {}//不明白为什么出售最后一件装备时j==-4
	if (j < 0)
	{
		return;
	}
	for (i = 0; i < j; i++)
	{
		if (currPlayer->bag.props[i].id == 0)
		{
			break;
		}
	}
	//prop[i]为空||i==j，i==j说明prop[0]~prop[j]没有空位，循序已排好
	for (; i != j;)
	{
		//完成此循环，prop[j]为空
		for (i; i < j; i++)
		{
			emptyProp = currPlayer->bag.props[i];
			currPlayer->bag.props[i] = currPlayer->bag.props[i + 1];
			currPlayer->bag.props[i + 1] = emptyProp;
		}
		for (j = currPlayer->bag.capacity - 1; currPlayer->bag.props[j].id == 0; j--) {}
		//重新验证是否排好序，若排好则跳出循环
		for (i = 0; i < j; i++)
		{
			if (currPlayer->bag.props[i].id == 0)
			{
				break;
			}
		}
		
	}

}

void EquipmentAttribute_add(Prop equipment)
{
	currPlayer->atk += equipment.atk;
	currPlayer->crit += equipment.crit;
	currPlayer->defence += equipment.defence;
	currPlayer->hp += equipment.hp;
	currPlayer->miss += equipment.miss;
	currPlayer->mp += equipment.mp;
}

void EquipmentAttribute_minus(Prop equipment)
{
	currPlayer->atk -= equipment.atk;
	currPlayer->crit -= equipment.crit;
	currPlayer->defence -= equipment.defence;
	currPlayer->hp -= equipment.hp;
	currPlayer->miss -= equipment.miss;
	currPlayer->mp -= equipment.mp;
}

void SeekRepetition(Bag currPlayerBag)
{
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	for (i = 0; i < bagPropCount; i++)
	{
		for (j = i + 1; j < bagPropCount; j++)
		{
			if (currPlayer->bag.props[i].id == currPlayer->bag.props[j].id)
			{
				currPlayer->bag.props[i].stock += currPlayer->bag.props[j].stock;
				currPlayer->bag.props[j] = constEmptyProp;
			}
		}
	}
}