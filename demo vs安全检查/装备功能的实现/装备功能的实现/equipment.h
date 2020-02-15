#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/*********************   ��Ϸ�Ľṹ���Ͷ���   *******************************/

//��ҡ���ͼ��װ��������
/* ��Ϸ��ͼ�ṹ ��Ϸ��ͼ
  ��š����ơ����ܡ���ҵĽ���ȼ� */

/* ��Ϸ��������ö�� - ���������ߡ�����Ʒ����Ƭ����Ƭ */
typedef enum _proptype {
	Weapon, Armor, Con, card, Frag
}PropType;

/* ��Ϸ���� - ���������ߡ�����Ʒ����Ƭ */
typedef struct _prop 
{
	int id;         //���߱��
	char name[50];  //��������
	PropType type;  //���ߵ�����
	union {//���� - ��ѡ1
		int minAttack; //������������Ͷ�Ӧ������
		int minDefence;//����Ƿ��ߣ��Ͷ�Ӧ������
		int minPower;  //�����Ѫƿ������Ʒ���Ͷ�Ӧ���ӵ�����ֵ
	};
	union {//���� - ��ѡ1
		int maxAttack; //������������Ͷ�Ӧ������
		int maxDefence;//����Ƿ��ߣ��Ͷ�Ӧ������
		int maxPower;  //�����Ѫƿ������Ʒ���Ͷ�Ӧ���ӵ�����ֵ
	};
}Prop;


typedef struct _player 
{
	int id;
	char name[50];
	int Attack;         //��ҵĹ�����
	Prop weapon[5];    //���װ��������
	int A;
	//��ҵı���
}Player;


int equip(int player_Attack ,int weapon_maxAttack);
int equip(int player_Attack, int weapon_maxAttack)
{
	player_Attack += weapon_maxAttack;
	return player_Attack;
}

void equip_ptr(Player * player_ptr);
void equip_ptr(Player * player_ptr)
{
	player_ptr->Attack += player_ptr->weapon[0].maxAttack;
}