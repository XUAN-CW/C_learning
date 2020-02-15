#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>



typedef struct _prop
{
	int id;         //���߱��
	char name[50];  //��������
	int attack;         //��ҵĹ�����
	int defense;
	int hp;				//health point
	int mp;				//magic point
}Prop;


typedef struct _player
{
	int id;
	char name[50];
	int attack;         //��ҵĹ�����
	int defense;
	int hp;				//health point
	int mp;				//magic point
	Prop weapon;    //���װ��������
	Prop armor;		//���װ���ķ���
	Prop bag[20];
}Player;

void equit(Player*players);
