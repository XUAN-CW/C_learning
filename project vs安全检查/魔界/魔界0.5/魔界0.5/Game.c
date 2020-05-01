/************************************************************************
 *  Project:	  ħ��
 *  Description:  ������������Ʒ��MUD��Ϸ
				  ����ˮƽ���ޣ����汾�漰���ݽ����ṹ�壬���������󽫼����ñ���Ŀ������ϰ
 *  Version:	  0.5
 *  Date:		  2018-12-14
 *  Author:		  �Pĳ
 ************************************************************************
 *  Copyright 2018 by GUET
 ************************************************************************/


#include "Game.h"

int X = 3, Y = 4;				//����������
int walkX = 0, walkY = 0;		//ִ�����ߵ�ͼָ��ǰ���������ڵ����꣬������ȼ�����������ʧ�ܣ��򷵻ش�����
int i = 0;						//��ʱ������ѭ��ʱʹ�ã�ʹ��ʱע�⸳ֵ��һ��Ҫ��������
int j = -1;						//��ʱ������ѭ��ʱʹ�ã�ʹ��ʱע�⸳ֵ��һ��Ҫ��������
int bagY = 0;					//������Ʒ������Ʒ������
int bagWalk = 0;
int range = 0;					//�����е�ǰ��Ʒ���ڵķ�Χ������ʵ����Ʒ������Ч��
int walkFailure = 0;			//�ȼ����������ܽ����ͼ���ñ���������֤�Ƿ�����ͼʧ��
int WearEquipmentFailure = 0;
int bagPropCount;
int * ptr_bagPorpCount = &bagPropCount;
extern char key;
Prop emptyProp;					//Prop���͵���ʱ����
const Prop constEmptyProp;		//���ڸ���ԭ���ĵ��ߣ��ﵽȥ���õ��ߵ�Ч��
Player * currPlayer;
const Player originalPlayer = { 999, "��ʿ", 5,5,10,0.1,0.4,6,0,0.4,1000,5,0 };

Prop weapons[] =
{
	//��� ���� ���� ������ ������ Ѫ�� ������ ������ ħ��ֵ ����ֵ ������ұ����еĵ������� ���� ��������
	{101, "һ�ֳ��߽�"	, WEAPON, 13, 120, 610, 180, 131, 131, 113, 13, 1, 10000, "�����������������������"},
	{102, "������ˮ��"	, WEAPON, 15, 104, 810, 140, 151, 151, 115, 15, 1, 10000, "�߶ȵ�����ԣ������ޱȣ�"},
	{103, "���溣���"	, WEAPON, 10, 140, 710, 160, 101, 101, 110, 10, 1, 10000, "�ش�ʮ���ǧ��������"},
	{104, "�ķ�������"	, WEAPON, 16, 190, 910, 190, 161, 161, 116, 16, 1, 10000, "����������������Ϊ��ԭ���ֵ�һ���ɺͷ��Ź�صĳ�ߵ�λ��"},
	{105, "�廢����"	, WEAPON, 10, 150, 210, 140, 101, 101, 110, 10, 1, 10000, "Ψ������Ԫ�ع�ͨ���˿��Ի�����������������"},
	{106, "����ӭ��ǹ"	, WEAPON, 18, 180, 310, 160, 181, 181, 118, 18, 1, 10000, "��������������ڶ�����һ��С������ķɵ���"},
	{107, "����ն��ì"	, WEAPON, 10, 160, 210, 110, 101, 101, 110, 10, 1, 10000, "ì������������ţ�����н��ŷ�ɥ����������"},
	{108, "���Խ�����"	, WEAPON, 13, 180, 810, 170, 131, 131, 113, 13, 1, 10000, "�������ϣ��·��ǻ�Ӱ���������ձ��죡"},
	{109, "��תǬ��Ȧ"	, WEAPON, 10, 140, 910, 106, 101, 101, 110, 10, 1, 10000, "��ɫ���ӣ��ɷ�����������Ǭ����"},
	{110, "��аϬ"		, WEAPON, 12, 130, 610, 170, 121, 121, 112, 12, 1, 10000, "һ���ܽ����°ٶ���͸������"},
	{111, "�ۻʽ�"		, WEAPON, 10, 120, 210, 150, 101, 101, 110, 10, 1, 10000, "�Ϲ���������ù��ı�����"},
	{112, "������"		, WEAPON, 20, 202, 610, 200, 202, 202, 220, 20, 2, 20000, "һ���˿��ò���"},
};
Prop armors[] =
{
	{201, "����",		 ARMOR,3,3,3,3,3,3,3,3,1,3,  "ֻ��Զ�۲������棡"},
	{202, "����֮��",	 ARMOR,4,4,4,4,4,4,4,4,1,4,  "ȡ����֮�����������˺���"},
	{203, "�޼���",	 ARMOR,4,4,4,4,4,4,4,4,1,4,  "��ǹ���룬ˮ����"},

};
Prop goods[] =
{
	{1, "��ͨ�ۻʽ�",WEAPON,1,1,1,1,1,1,1,1,1,15000, "�Ϲ���������ù��ı�����"},
	{2, "��Ʒ�ۻʽ�",WEAPON,1,1,1,1,1,1,1,1,1,26000, "�Ϲ���������ù��ı�����"},
	{3, "��Ʒ�ۻʽ�",WEAPON,1,1,1,1,1,1,1,1,1,37000, "�Ϲ���������ù��ı�����"},
	{4, "��Ʒ�ۻʽ�",WEAPON,1,1,1,1,1,1,1,1,1,48000, "�Ϲ���������ù��ı�����"},
	{5, "���õ���",ARMOR,15,250,300,210,330,240,157,300,1,30000,  "ֻ��Զ�۲������棡"},


};
Map mapArray[8][8] =
{
	{
		{1, "����ɽ��", 1, {0, 0}, "�ܻ���ǧ�������ʮ��������˵��������������ʮ����ʯ��λ��ɽ�����룬��֪�Ǻ�������... ..."},
		{2, "�޾�����", 1, {1, 0}, "�𣬵������ǻ�"},
		{3, "����ɽ",   1, {2, 0}, "����ܾ�֮�ء�"},
		{4, "Ұ����",   1, {3, 0}, "Ұ�����ﵽ������Ұ��... ..."},
		{5, "�����",   1, {4, 0}, "�����ڹۣ������鸮����������֮����������֮���������涴�ɹ�Ҳ��"},
		{6, "��  ��",   1, {5, 0}, "���زϼ룬����ɶꡣ"},
		{7, "����կ",   1, {6, 0}, "���и��֡�"},
		{8, "����",   1, {7, 0}, "��|��|_���಻�����ˣ���ѡ�񹷴�[�ֶ���ͷ]"}
	},
	{
		{9, "��  ��",  1, {0, 1}, "�����Ǹ߲��Թ���Ҳ��һ��ʮ�����صĵط�������������ḻ�Ĵ�ǰ������֪����ᷢ��ʲô���顣"},
		{10, "̫�ճ�", 1, {1, 1}, "���ߣ�����û��������"},
		{11, "��ԯ��", 1, {2, 1}, "һ��ɽ�룬�����͵ģ�������Զ����ȥ������͸��һ��ɱ�����ʹ�·�˲�֪��������������ж��ŵ���ԯ�룡"},
		{12, "��  ɽ", 1, {3, 1}, "�ԹŻ�ɽһ��·��"},
		{13, "��  ɽ", 1, {4, 1}, "�����صء�"},
		{14, "��  ʦ", 1, {5, 1}, "��������֮�ء�"},
		{15, "��  ¥", 1, {6, 1}, "�Ҿ�֪������������_��"},
		{16, "���ص�", 1, {7, 1}, "��������أ����ص�ûʲô�����������"}
	},
	{
		{17, "��  ��", 1, {0, 2}, "����û��ˮ��û������û�вݣ���һ������������"},
		{18, "��«��", 1,{1, 2}, "��«�����ƺ�ֻ�к�«��Զ��������ֻ���«��"},
		{19, "ʯ  ��", 1, {2, 2}, "�r(���S��)�q"},
		{20, "����ɽ", 1, {3, 2}, "���Ҹ��ء�"},
		{21, "���Ӽ�", 1, {4, 2}, "��������Ů��ʦ��Ҳ��У������Ȼ���ٲ���У԰��Ԩ�(�� ,��)��"},
		{22, "��  ջ", 1, {5, 2}, "���ƻ��֮�أ�������Դ���������֪���Ķ���"},
		{23, "��ʶ�", 1, {6, 2}, "һ����Զ���ᰲ���ĵط���̩ɽ��ʶ���������һ����������ɱ�ĵط�����ʱ�޿̲�����ű�������ɱ�ĵط���"},
		{24, "���ߵ�", 1, {7, 2}, "���û�У������߶�!"}
	},
	{
		{25, "��ʮ����", 1,{0, 3}, "��ν��ʮ�����ߣ��������ţ���������ᶵ��룬Ч�����㣬����һ����"},
		{26, "Ħ����",   1,{1, 3}, "���־��������졣"},
		{27, "��  ��",	 1,{2, 3}, "����ֻ����ǿ�ߣ�"},
		{28, "��  ɽ",   1,{3, 3}, "�����Ϻ�ɽ�ľ�ɫ���ǲ�һ�㣬����ʢ���Žв������ֵĸ�ɫС������ֻ�۷��ڻ�����裬����һ������С·����һ����Ĺǰ������д�ţ�������Ĺ��"},
		{29, "����ɽ��", 1,{4, 3}, "�ܻ���ǧ�������ʮ��������˵��������������ʮ����ʯ��λ��ɽ�����룬��֪ͨ��η�... ..."},
		{30, "ƽ�츮",   1,{5, 3}, "(*'��'*)"},
		{31, "��ʮ����", 1,{6, 3}, "��ʮ��������ҹ�����˺δ��̴��"},
		{32, "�����ɾ�", 1,{7, 3}, "�������Ƶ������ɾ��Թ��������ƺ��������������ܣ�˭�������ҿ���������أ�"}
	},
	{
		{33, "����ɽ", 1, {0, 4}, "�������ҹ����̵����ģ��о��Լ����Ϳա�"},
		{34, "С����", 1, {1, 4}, "�������ҹ����̵����ģ��о��Լ����Ϳա�"},
		{35, "�ٻ���", 1, {2, 4}, "�ۣ�����̫���ˣ�����ĺܶ໨���в������֣�"},
		{36, "ʥ�˴�", 1, {3, 4}, "�ܾúܾ���ǰ�����˾·���˵أ��϶��˵��д����ˣ��س�ʥ�ˣ�����ʥ�˴塣��ĿǰΪֹ���˵ػ�û�г���ʥ��... ..."},
		{37, "������", 1, {4, 4}, "��ҵ������£�ÿ��ǰ������֮�����ﲻ�����ɴӽ���֮����Ը����ĳ̶������˲��ò��������ɡ�"},
		{38, "������", 1, {5, 4}, "�齱�ĵط�"},
		{39, "�򽭸�", 1, {6, 4}, "��˵������������"},
		{40, "ǳ  ��", 1, {7, 4}, "С�ڹ꣬�ÿɰ���"}
	},
	{
		{41, "%#@*��",1, {0, 5}, "����˵�ˣ����������"},
		{42, "������",1, {1, 5}, "���쿴�ˡ���������Ⱥ���������������"},
		{43, "������",1, {2, 5}, "�����������֣�������˵��Ƭ���ֲ�Ҫ�����߽�����Ϊ��ʮ��Σ�գ���˵�в������߽�ȥ����Ҳû�г�������"},
		{44, "��ȸɽ",1, {3, 5}, "�������̲�������ɭ��ï�ܣ���ȸ���࿪�������񻶳�ӭ����÷��¹����Ϸˮ��������Ȼ��г���ڡ�"},
		{45, "������",1, {4, 5}, "�������������󣬴��������и�󡣬һ��һ���Q��"},
		{46, "������",1, {5, 5}, "ʲô�������У�"},
		{47, "��̲��",1, {6, 5}, "�����Ǻ�̲������"},
		{48, "��  ��",1, {7, 5}, "-_-!"}
	},
	{
		{49, "��  ��", 1, {0, 6}, "���������ڣ��������ʲô�������������ط���Щ��ͬ��"},
		{50, "������", 1, {1, 6}, "��|��|_���಻�����ˣ���ѡ�񹷴�[�ֶ���ͷ]"},
		{51, "������", 1, {2, 6}, "Ϊ�κ������л�������ڶ�ĺ������ǲ�����Ϊ������ʲô���ɸ��˵����飿����ֻ����Ե�˲���֪���ˡ�"},
		{52, "������", 1, {3, 6}, "��ץ��дС˵�İ���д����T_T"},
		{53, "����Ժ", 1, {4, 6}, "���������ױ����ۡ�"},
		{54, "��̲��", 1, {5, 6}, "�����Ǻ�̲����"},
		{55, "��  ��", 1, {6, 6}, "С�ģ��о��������û��"},
		{56, "ʯ  ͷ", 1, {7, 6}, "ʯͷ���ƺ��зۺ�ɫ����������... ..."}
	},
	{
		{57, "ʯ  ��",   1, {0, 7}, "���ʯ����ֻ��ʯͷ��ʯͷ��Ȼ�������ҷŵġ�"},
		{58, "������",   1, {1, 7}, "����ϴ��������ˮ���ܲ�������ƽ̹�����ʷ��֣����к��ԡ�"},
		{59, "�����",   1, {2, 7}, "Զ��ħ����뢷�ӡ�ڴˣ�����������ԼԼ�Ŀ�����"},
		{60, "��  ��",   1, {3, 7}, "�˵�Σ�գ�"},
		{61, "��̲һ",   1, {4, 7}, "�����Ǻ�̲��"},
		{62, "�Ϲ�ͤ",   1, {5, 7}, "ͤ�����壬�������¡�"},
		{63, "������",   1, {6, 7}, "λ�ں���������������һ�����ӣ���˭ס�������أ�"},
		{64, "�������", 1, {7, 7}, "�������ſ��µĴ��ڣ�ֻ��ǿ�߲���̽�����"}
	}
};
Player players[] =
{
	//��� ���� ������ ������ Ѫ�� ������ ������ ħ��ֵ ����ֵ ���� ������� ��ǰ���ڵ�ͼ������ װ�������� װ���ķ��� ����
	{1, "����", 200,100,1500,0.1,80,100,150,50,100000,3,100,{4,3},weapons[4],armors[2],
	{1,2,50,{weapons[9],weapons[10],weapons[4],weapons[5],weapons[6],weapons[7],weapons[8],weapons[9],weapons[10]}}},//
};


Monster monsterArray[] =
{
	{1, "���౦��",		9, 9999, 500, 9, 9999, 9995, 99991,1,{weapons[2]}, {7, 7}},
	{2, "�����",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{6, 7}},
	{3, "�ɴ���",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{7, 6}},
	{4, "Ϭ����",		2, 200, 8, 2, 5, 10, 1,1,{weapons[2]},{0, 0}},
	{5, "�����о�",		9, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{3, 4}},
	{6, "��ħС��",		8, 100, 5, 2, 5, 10, 1,1,{weapons[2]},{4, 3}},
	{7, "�ɺ�С����",	7, 3000, 5, 2, 5,  5, 1,1,{weapons[2],weapons[3]},{3, 4}},
	{8, "���������",	6, 100, 5, 2, 5,  5, 1,1,{weapons[2]},{0, 0}},

};

void ShowMonsters()
{
	int monsterCount = sizeof(monsterArray) / sizeof(Monster);
	int pkMonsterId = -1;
	int monsterNum;
	const char *levelNames[] =
	{ "���δ��", "����é®", "��ͨƤë", "����ſ�", "����С��", "�������", "�������", "�����޵�", "���˺�һ" };
	Clear(MARGIN_X, INFO_START_Y, 7);
	//�ҳ���ǰ��ͼ����
	Monster pkMonsters[9];
	/* �������й����У������ǵ�ǰ��ͼ�Ĺ��� */
	for (i = 0, monsterNum = 0; i < monsterCount; i++)
	{
		if (monsterArray[i].coord.X == X && monsterArray[i].coord.Y == Y && monsterArray[i].state != 0)//state != 0 û��
		{
			pkMonsters[monsterNum] = monsterArray[i];
			if (monsterNum == 9)
			{
				break;
			}
			monsterNum++;
		}
	}
	//������ϣ���j������
	SetPosition(MARGIN_X + 10, INFO_START_Y);
	if (monsterNum == 0)
	{
		printf("��ǰ��ͼһƬ��ͣ�");
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
	printf("������Ҫ�����Ķ��󣺣���0���أ�");
	do
	{
		pkMonsterId = _getch();
		pkMonsterId -= 48;					//ascii��ת��Ϊ����
		/* ��֤�û����� */
		if (pkMonsterId == 0)
		{
			ShowMap();
			return;
		}
		if (pkMonsterId > monsterNum || pkMonsterId < 0)
		{
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("���ﲻ����                             ");
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
	int fightCount = 1;								//pk������
	double multipleRandom = 1;						//�������
	int playerInjure;								//����ܵ����˺�
	int monsterInjure;								//�����ܵ����˺�
	int money;										//��Ǯ
	int exp;										//����
	Player pkPlayer = *(currPlayer);
	Monster pkMonster = pkMonsters;
	Clear(MARGIN_X, INFO_START_Y, 7);
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	while (1)
	{
		srand(time(NULL));
		//����0.8~1.2���������
		multipleRandom = rand() % 400 + 800;		
		multipleRandom /= 1000;						
		fightCount++;
		SetPosition(MARGIN_X, INFO_END_Y - 2);
		printf("%s", BLANK_78);
		if (pkPlayer.agility > pkMonster.agility)
		{
			monsterInjure = floor((pkPlayer.atk - pkMonster.defence)*multipleRandom);
			monsterInjure = (monsterInjure > 0) ? monsterInjure : 1;

			if (pkMonster.miss < rand() % 100)			//������
			{
				if (pkPlayer.crit > rand() % 100)		//�����ұ�����
				{
					monsterInjure *= 2;
					SetPosition(MARGIN_X + 64, INFO_END_Y - 2);
					printf("����");
				}
				pkMonster.hp -= monsterInjure;
			}
			else										//û����
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
					printf("����");
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
		printf("ս����%d��", fightCount / 2);
		SetPosition(MARGIN_X + 17, INFO_END_Y - 2);
		printf("%sHP:%-6d", pkPlayer.name, pkPlayer.hp);
		SetPosition(MARGIN_X + 44, INFO_END_Y - 2);
		printf("%sHP:%-6d ", pkMonster.name, pkMonster.hp);
		SetPosition(98, INFO_END_Y - 1);
		Sleep(200);
		/* Ӯ�� */
		if (pkMonster.hp <= 0)
		{
			exp = pkMonster.Money * multipleRandom;
			money = pkMonster.Money * multipleRandom;
			currPlayer->exp += exp;								//��õľ���
			currPlayer->gold += money;							//��õĽ�Ǯ
			if (currPlayer->luck > rand() % pkMonster.luck)		//��õ�װ��
			{
				currPlayer->bag.props[bagPropCount] = pkMonster.props[rand() % 2];//����rand() % MONSTER_PROP_MAX - 1
				if (currPlayer->bag.props[bagPropCount].id != 0)
				{
					SetPosition(CENTERED - 6, INFO_END_Y - 4);
					printf("��ϲ�㣬�����[%s]!", currPlayer->bag.props[bagPropCount].name);
					SeekRepetition(currPlayer->bag);
				}
			}
			SetPosition(MARGIN_X, INFO_END_Y - 1);
			printf("%s", BLANK_78);
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("��������ս������սʤ�ˡ�%s�������%d���飬%d��ң�", pkMonster.name, exp, money);
			if (currPlayer->exp > currPlayer->level * 1000)
			{
				currPlayer->exp -= currPlayer->level * 1000;
				currPlayer->level++;
				Init();
			}
			//printf("��������ս������սʤ�ˡ�%s�������%d���飬%d��ң�",
			//pkMonster.name,pkMonster.Money * multipleRandom,pkMonster.Money * multipleRandom);Ϊʲô�����
			break;

		}
		/*����*/
		if (pkPlayer.hp <= 0)
		{
			SetPosition(MARGIN_X, INFO_END_Y - 1);
			printf("%s", BLANK_78);
			SetPosition(MARGIN_X + 5, INFO_END_Y - 1);
			printf("��%s�����롶%s����ս����׳��������һ����žʹ����䣡", currPlayer->name, pkMonster.name);
			currPlayer->level--;
			Init();
			break;
		}
	}

}


void ShowWelcome()
{
	/* ��ʾ��Ϸ�Ļ�ӭ��Ϣ */
	SetPosition(MARGIN_X, 0);
	printf("%s", SEP);
	SetPosition(MARGIN_X, 1);
	printf("|");
	SetPosition(CENTERED, 1);
	printf("��ӭ����ħ�磡");
	SetPosition(MARGIN_X + 77, 1);
	printf("|");
	SetPosition(MARGIN_X, 2);
	printf("%s", SEP);
}

/* ��ʾ��Ϸ��ͼ */
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
			//��ͼ���ĵ�ǰ��ͼ���ֵ���ɫ�ͱ���ɫ
			if (i == Y && j == X)
			{
				SetColor(12, 15);
			}
			printf("%-9s", mapArray[i][j].name);
			//��ӡ�굱ǰ��ͼ�󣬽���ɫ�ݱ��Ĭ����ɫ
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
		printf("%d�����ܽ���%s��ĳ�˵ĵȼ�����Ŷ��_��", mapArray[walkX][walkY].level, mapArray[walkX][walkY].name);
		walkFailure = 0;
	}
}

void ShowMapInfo()
{
	/* ����Ϣ������ʾ��ǰ��ͼ����Ϣ */
	//1.�����Ϣ������Ϣ
	Clear(MARGIN_X, INFO_START_Y, 7);
	//2.��ʾ��ǰ������ڵ�ͼ����Ϣ
	SetPosition(MARGIN_X + 25, INFO_START_Y);
	printf("��ǰ������ڵ�ͼ����%s��", mapArray[Y][X].name);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
	//��Ҫ����������ʾ����
	char * desc = mapArray[Y][X].desc;
	int descLen = strlen(desc);
	int i;
	for (i = 0; i < descLen; i++)
	{
		//���ƴ���ֻ�ܴ�ӡ60�������ַ�
		if (i != 0 && i % 60 == 0)
		{
			SetPosition(MARGIN_X + 10, INFO_START_Y + 1 + i / 60);
		}
		printf("%c", desc[i]);
	}
}

void ShowInfomation()
{
	/* ��ʾ��Ϸ��ͼ�·�����Ϸ��Ϣ */
	//��Ϣ����һ����7��
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

	/* ��ʾ��Ϸ�����˵� */
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y);
	printf("��Ϸ�˵���");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 1);
	printf("1����������");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 2);
	printf("2�����ҹ���");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 3);
	printf("3���ؼ�");
	SetPosition(MARGIN_X + 1, MAINMENU_START_Y + 4);
	printf("4������װ��");
}

void ShowPlayerInfo()
{
	//1.�����Ϣ������Ϣ
	Clear(MARGIN_X, INFO_START_Y, 7);
	SetPosition(MARGIN_X + 20, INFO_START_Y);
	printf("��%s���ĸ����������£�", currPlayer->name);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
	printf("�ȼ���%d\tѪ����%d\t������%d\t����ֵ��%d", currPlayer->level, currPlayer->hp, currPlayer->mp, currPlayer->exp);
	SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
	printf("��ǰ������%s(����+%d)\t", currPlayer->weapon.name, currPlayer->weapon.atk);
	printf("��ǰ���ߣ�%s(������+%d)", currPlayer->armor.name, currPlayer->armor.defence);


}


void SetColor(int foreColor, int backColor)
{
	/** 
	 * ����������ɫ
	 * 0-�� 1-�� 2-�� 3-ǳ�� 4-�� 5-�� 6-�� 7-�� 8-�� 9-���� 
	 * 10-���� 11-��ǳ��  12-���� 13-���� 14-���� 15-���� 
	 */
	HANDLE winHandle;   //���
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������ɫ
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);//https://blog.csdn.net/qq_36771850/article/details/79187836
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;   //���������
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù�������
	SetConsoleCursorPosition(winHandle, pos);
}

void Clear(int x, int y, int rowCount)
{
	/* ��x��y���꿪ʼ����rowCount�� */
	//ÿ�����78���ַ�-��ӡ78���ո�
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
	//ˢ�µ�ͼ
	ShowMap();
}

void walk(char key)
{
	i = X;
	j = Y;
	if (key == 38 || key == 72)//�û������ϼ�
	{
		Y--;
	}
	else if (key == 39 || key == 77)//��
	{
		X++;
	}
	else if (key == 40 || key == 80)//��
	{
		Y++;
	}
	else if (key == 37 || key == 75)//��
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

void Init()//��ʼ����Ϸ����
{
	double multipleGrowth = 1;
	currPlayer = &players[0];//��ǰ���
	for (i = 0; i < currPlayer->level; i++)
	{
		multipleGrowth *= LEVEL_GEOWTH_RATE;
	}
	int int_multipleGrowth = multipleGrowth;
	//���������� = ��ʼ���� * �ɳ�����
	currPlayer->agility = originalPlayer.agility * int_multipleGrowth;
	currPlayer->atk = originalPlayer.atk * int_multipleGrowth;
	currPlayer->crit = originalPlayer.crit*currPlayer->level;
	currPlayer->defence = originalPlayer.defence * int_multipleGrowth;
	currPlayer->hp = originalPlayer.hp * int_multipleGrowth;
	currPlayer->luck = originalPlayer.luck + currPlayer->level;
	currPlayer->miss = originalPlayer.miss * multipleGrowth;
	currPlayer->mp = originalPlayer.mp * int_multipleGrowth;
	EquipmentAttribute_add(currPlayer->weapon);//�Դ����ƣ���װ�������Լӵ������
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


/*�̳�*/
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
		if (propId == '1' || propId == '2' || propId == '3' || propId == '4' || propId == '5')//ȷ����ֻ�������Ʒ���Գ���
			Trade(currPlayer, propId);

	} while (1);
	//������ʾ��ͼ
	ShowMap();
	Clear(MARGIN_X, MAINMENU_START_Y, 7);
	ShowMainMenu();
}

void Trade(Player * currPlayer, int propId)
{
	int goodsCount;
	int bagPropCount;
	int bagPropId_tradePropId = -1;		//�жϱ�������û��Ҫ���׵ĵ���
	Prop *tradeProp = NULL;				//Ҫ�������Ʒָ��
	goodsCount = sizeof(goods) / sizeof(Prop);
	propId -= 48;

	//����Ʒ
	for (i = 0; i < goodsCount; i++)
	{
		if (propId == goods[i].id)
		{
			tradeProp = &goods[i];		//�ҵ��� 
			break;
		}
	}
	if (i == goodsCount)				//û���ҵ�
	{
		SetPosition(MARGIN_X, 27);
		printf("û���ҵ�����Ҫ����Ʒ��������ѡ��");
		return;
	}
	//��Ǯ	
	if (currPlayer->gold < tradeProp->price)
	{
		SetPosition(MARGIN_X, 27);
		printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣡ\n");
		return;
	}
	//��������װ
	//���㱳��֮�е��ߵ���Ŀ�����鱳��������Ҫ���׵��ߵı��
	//����ѭ��ʱbagPropCount==�����е��ߵ���Ŀ
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0 || bagPropCount == currPlayer->bag.capacity; bagPropCount++)
	{
		currPlayer->bag.props[bagPropCount];
		if (currPlayer->bag.props[bagPropCount].id == propId)
		{
			bagPropId_tradePropId = tradeProp->id;									//����������Ҫ���׵ĵ���
		}
	}
	if (bagPropCount == currPlayer->bag.capacity && bagPropId_tradePropId == -1)	//���������ұ�����û��Ҫ���׵���Ʒ
	{
		printf("����������");
		return;
	}

	/*���׿�ʼ*/
	if (bagPropId_tradePropId != -1)												//��������Ҫ���׵���Ʒ
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
	if (bagPropCount != currPlayer->bag.capacity && bagPropId_tradePropId == -1)	//����λ��δ���ұ�������Ҫ���׵���Ʒ
	{
		//�����е�bagPropCount��λ��Ϊ�գ�����Ʒ���Ƶ�������
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
	printf("�̳�");
	SetPosition(MARGIN_X, 5);
	printf(" %-6s%-12s%-10s%s\n", "���", "����", "�۸�", "����");
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
	printf("����");
	printf("                         ���:%-8d", currPlayer->gold);
	rangeMax = range + 11;
	//����ʮһ�У�ȫ�����꣬����ʮһ�У�ֻ��ʮһ��
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
			printf("����+%-8d", currPlayer->bag.props[range].atk);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("����+%-8d", currPlayer->bag.props[range].defence);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("Ѫ��+%-8d", currPlayer->bag.props[range].hp);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("ħ��+%-8d", currPlayer->bag.props[range].mp);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("����+%-8d", currPlayer->bag.props[range].agility);
			i++;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("����+%.2lf%%   ", currPlayer->bag.props[range].miss);
			i++;;
			SetPosition(PROP_ATTRIBUTE_X, PROP_ATTRIBUTE_Y + i);
			printf("����+%.2lf%%   ", currPlayer->bag.props[range].crit);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y);
			switch (currPlayer->bag.props[range].category)
			{
			case WEAPON:
				printf("���ࣺ����");
				break;
			case ARMOR:
				printf("���ࣺ����");
				break;
			}
			printf("    �ȼ���%-4d", currPlayer->bag.props[range].leve);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 1);
			printf("��Ŀ��%-4d", currPlayer->bag.props[range].stock);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 2);
			printf("�ۼۣ�%d���       ", currPlayer->bag.props[range].price);
			SetPosition(CENTERED + 2, PROP_ATTRIBUTE_Y + 3);
			printf("������");
			ptr_propDescription = currPlayer->bag.props[range].desc;
			propDescriptionLen = strlen(ptr_propDescription);
			SetPosition(CENTERED + 8, 17);
			for (i = 0; i < propDescriptionLen; i++)
			{
				//���ƴ���ֻ�ܴ�ӡ17�������ַ�
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
		printf("%d�����ܴ���%s��ĳ�˵ĵȼ�����Ŷ��_��", currPlayer->bag.props[bagY].leve, currPlayer->bag.props[bagY].name);
		WearEquipmentFailure = 0;
	}
	PropFlashback(currPlayer);
	Box(MARGIN_X, 12, 14);
	range -= 11;
};

void PropFlashback(Player * currPlayer)
{
	for (bagPropCount = 0; currPlayer->bag.props[bagPropCount].id != 0; bagPropCount++) {}
	for (i = 0; i < bagPropCount / 2; i++)//ʧ��for (i = 0; i <= bagPropCount / 2; i++)
	{
		emptyProp = currPlayer->bag.props[i];
		currPlayer->bag.props[i] = currPlayer->bag.props[bagPropCount - i - 1];
		//ʧ��currPlayer->bag.props[i]=currPlayer->bag.props[bagPropCount - i] ;
		currPlayer->bag.props[bagPropCount - i - 1] = emptyProp;
	}

}

void BagWalk(char propId)
{
	if (propId == 38 || propId == 72)		//�û������ϼ�
	{
		bagY--;

	}
	else if (propId == 40 || propId == 80)	//��
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


/*������Ϣ��װ��*/
void Player_Equipment()
{
	char equipmentKey;
	do {
		ShowPlayerInformation();
		ShowBag();
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y);
		printf("0���˳�");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 1);
		printf("1����װ��");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 2);
		printf("2��ж��ȫ��װ��");
		SetPosition(PLAYER_EQUIPMENT_X, PLAYER_EQUIPMENT_Y + 3);
		printf("9�����۸�װ��");

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
	//������ʾ��ͼ
	ShowMap();
	Clear(MARGIN_X, MAINMENU_START_Y, 7);
	ShowMainMenu();
};

void ShowPlayerInformation()
{
	double k;
	const char *LuckLevels[] =
	{ "ӡ�÷���", "��ͥ����", "˳��˳ˮ", "�����³�", "���Ǹ���", "��������", "�������", "�鸣����", "��������","λ��֮��" };
	Clear(MARGIN_X, 3, 25);
	Box(MARGIN_X, 3, 8);
	SetPosition(CENTERED - 4, 4);
	printf("%s�ĸ�����Ϣ���£�", currPlayer->name);

	SetPosition(MARGIN_X + 5, 6);
	printf("�ȼ���%-12d", currPlayer->level);
	SetPosition(MARGIN_X + 5, 7);
	printf("���飺%-12d   ", currPlayer->exp);
	SetPosition(MARGIN_X + 5, 8);
	printf("������%-12s", currPlayer->weapon.name);
	SetPosition(MARGIN_X + 5, 9);
	printf("���ߣ�%-12s", currPlayer->armor.name);

	SetPosition(MARGIN_X + 33, 6);
	printf("������%-12d", currPlayer->atk);
	SetPosition(MARGIN_X + 33, 7);
	printf("������%-12d", currPlayer->defence);
	SetPosition(MARGIN_X + 33, 8);
	printf("Ѫ����%-12d", currPlayer->hp);
	SetPosition(MARGIN_X + 33, 9);
	printf("ħ����%-12d", currPlayer->mp);

	SetPosition(MARGIN_X + 59, 6);
	printf("������%.2lf%%", currPlayer->crit);
	SetPosition(MARGIN_X + 59, 7);
	printf("���ܣ�%.2lf%%", currPlayer->miss);
	SetPosition(MARGIN_X + 59, 8);
	printf("���ݣ�%d", currPlayer->agility);
	SetPosition(MARGIN_X + 59, 9);
	for (i = 0, k = 5; k < currPlayer->luck; i++)
	{
		k *= 1.4;
	}
	i = (i > 9) ? 9 : i;
	printf("���ˣ�%s", LuckLevels[i]);
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
	/* �Ȼ�װ�������̫�࣬�����ȱ���������� */
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
	//Ҫ������װ��������ֻ��һ��
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
	//Ҫ������װ���������ж��
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
	//ʧ����PropFlashback(currPlayer); ��RandBag(currPlayer);
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
	//prop[j]Ϊ���һ�����ߵ�λ��,j==-1,����Ϊ��
	for (j = currPlayer->bag.capacity - 1; currPlayer->bag.props[j].id == 0; j--) {}//������Ϊʲô�������һ��װ��ʱj==-4
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
	//prop[i]Ϊ��||i==j��i==j˵��prop[0]~prop[j]û�п�λ��ѭ�����ź�
	for (; i != j;)
	{
		//��ɴ�ѭ����prop[j]Ϊ��
		for (i; i < j; i++)
		{
			emptyProp = currPlayer->bag.props[i];
			currPlayer->bag.props[i] = currPlayer->bag.props[i + 1];
			currPlayer->bag.props[i + 1] = emptyProp;
		}
		for (j = currPlayer->bag.capacity - 1; currPlayer->bag.props[j].id == 0; j--) {}
		//������֤�Ƿ��ź������ź�������ѭ��
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