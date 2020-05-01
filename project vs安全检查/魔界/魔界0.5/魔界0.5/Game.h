#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "Define.h"
#include <conio.h>
#include <math.h>

typedef struct _map
{
	int id;					//��ͼ���
	char name[50];			//��ͼ����
	int level;				//��ҽ������͵ȼ�
	COORD coord;			//��ͼ������
	char desc[500];			//��ͼ�Ľ���
}Map;

typedef struct _prop
{

	int id;
	char name[50];
	int category;
	int leve;
	int atk;
	int defence;
	int hp;
	double miss;
	double crit;
	int mp;
	int exp;
	int stock;
	int price;
	char desc[200];
	int specificAbility;
	int agility;
}Prop;

typedef struct _bag
{
	int playerId;				//������ҵı��
	int count;					//��ǰ�����У����ߵ�����
	int capacity;				//��������
	Prop props[50];				//��ǰ�����еĵ�������
}Bag;

typedef struct _player
{
	int id;						//���
	char name[50];				//����
	int atk;					//������
	int defence;				//������
	int hp;						//Ѫ��
	double miss;				//������
	double crit;				//������
	int mp;						//ħ��ֵ
	int exp;					//����ֵ
	int level;					//����
	int gold;					//�������
	int agility;				//����
	int luck;					//���� (��װ������)
	COORD coord;				//��ǰ���ڵ�ͼ������
	Prop weapon;				//װ��������
	Prop armor;					//װ���ķ���
	Bag bag;					//����
}Player;

typedef struct _monster {
	int id;
	char name[50];
	int level;					//����ļ���
	int hp;						//���������ֵ
	int atk;					//����Ĺ�����
	int defence;				//����ķ�����
	int Money;					//ɱ����������Ľ��ֵ
	int exp;					//ɱ���������һ�õľ���ֵ
	int state;					//���ﵱǰ��״̬��0��ʾ������������0��ʾ�������
	int agility;				//����
	Prop props[3];				//ɱ�����������װ��
	COORD coord;				//���������
	int luck = 1;				//����
	double miss;				//������
	double crit;				//������
}Monster;


void ShowWelcome();			//��ʾ��Ϸ�Ļ�ӭ��Ϣ 

void ShowMap();				//��ʾ��Ϸ��ͼ 

void ShowMapInfo();			//����Ϣ������ʾ��ǰ��ͼ����Ϣ  

void ShowInfomation();		//��ʾ��Ϸ��ͼ�·�����Ϸ��Ϣ 

void ShowMainMenu();		//��ʾ��Ϸ�����˵� 

void ShowPlayerInfo();		//����Ϣ������ʾ��ҵĸ�������  

void ShowMonsters();		//����Ϣ������ʾ��ǰ��ͼ�Ĺ��� 

void Move(int x, int y);	// ˲���ƶ�  


/**
 * 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
 * 8-��ɫ, 9-����ɫ, 10-����ɫ    11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
 */
void SetColor(int foreColor, int backColor);

void SetPosition(int x, int y);					// ���ù���λ�� 

void Clear(int x, int y, int rowCount);			// ��x��y���꿪ʼ����rowCount�� 

void Init();									//��ʼ����Ϸ����

void walk(char);
void Box(int, int, int);

/*�̳�*/
void Store();
void Trade(Player * palyer, int propId);
void ShowGoods();
void ShowBag();
void BagWalk(char bagWalk);
void PropFlashback(Player * currPlayer);

/*������Ϣ��װ��*/
void Player_Equipment();
void ShowPlayerInformation();
void WearEquipment(Player * currPlayer, int bagY);
void Sell(Player * currPlayer, int bagY);
void TakeOffAllEquipment(Player * currPlayer, int bagY);
void RandBag(Player * currPlayer);
void EquipmentAttribute_add(Prop equipment);
void EquipmentAttribute_minus(Prop equipment);
void SeekRepetition(Bag currPlayerBag);

/*ս��*/
void Fight(int monsterId, Monster  pkMonsters);
