#include "equipment.h"


int main()
{
	int plr = 0;//��plrλ���
	int eqpm_w = 0;//��eqpm_w+1������
	int eqpm_a = 2;//��eqpm_w+1������
	Prop weapons[5] =
	{
		//{0,"��װ��",0,0,0,0},
		{1,"�󱦽�",1,1,1,1},
		{2,"��������",10,10,10,10},

	};

	Prop armor[5]=
	{
		//{0,"��װ��",0,0,0,0},
		{1,"����",1,1,1,1},
		{2,"���Ӽ�",10,10,10,10},
	};

	Player players[5] =
	{
		{1,"����"},
		{2,"�����",0,0,0,0,weapons[0],armor[1]}
	};

	eqpm_w++;
	plr++;

	printf("�ṹ����Ĭ��ֵΪ��%d\n", players[0].hp);
	printf("װ��ǰ%s�Ĺ�������%d\t\t��������%d\t����ֵ��%d\tħ��ֵ��%d\t\n",
		players[plr].name, players[plr].attack, players[plr].defense, players[plr].hp, players[plr].mp);

	equit(&players[eqpm_w]);

	printf("װ����%s�Ĺ�������%d\t��������%d\t����ֵ��%d\tħ��ֵ��%d\t\n",
		players[plr].name, players[plr].attack, players[plr].defense, players[plr].hp, players[plr].mp);

	system("pause");
	return 0;
}

/*
		int id;
		char name[50];
		int hp;         //��ҵ�Ѫ��
		int mp;         //��ҵ�����ֵ
		int gold;       //��ҵĽ������
		Prop weapon;    //���װ��������
		Prop armor;     //���װ���ķ���
		//��ҵı���
	}Player;
*/

