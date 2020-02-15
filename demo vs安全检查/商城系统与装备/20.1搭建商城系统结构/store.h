#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*
	ģ��ʵ�ֵ��ߵ깺�﹦��(�̵���ʱֻ֧��һ�����͵���Ʒ)
	1����Ʒ�ṹ-���ơ����ۡ������������
	2�������ṹ-��ұ�š���Ʒ[10]��������������������
	3����ҽṹ-��š����ơ����롢��Ǯ��[����]
	ģ����ҹ�����Ϸ����
	1�����ѡ��Ҫ����ĵ���
	2�����ͬ�⽻�׺�۳���Ӧ��Ϸ��
	3����Ӧ��Ʒ���-1
	*4����ұ�����������Ʒ�����Ʒ����+1
*/
/* ��Ʒ�ṹ */
typedef struct _prop {
	int id;         //���ߵ�Ψһ���
	char name[50];  //��������
	double price;   //���ߵ���
	int stock;      //�����������ڱ����У���ʾ�˵��ߵĵ�������
	char desc[200]; //���ߵĹ�������
}Prop;
/* �����ṹ */
typedef struct _bag {
	int playerId;   //������ҵı��
	int count;      //��ǰ�����У����ߵ�����
	int max;        //��ǰ�����Ĳ������-��������������û���rmb����
	Prop props[8];  //��ǰ�����еĵ�������
}Bag;
/* ��ҽṹ */
typedef struct _player {
	int id;         //��ұ��
	char name[50];  //�û���/�ǳ�
	char pass[50];  //����
	Bag bag;        //��ҵı���
	int bagPropCount;//��ұ���������Ŀ
	int bagCapacity=8;	//��ұ�����������
	double gold;    //��ҽ��-������ʾ�����Խ�100000ͭ��ת�������ҡ������ʾ
	double sysee;   //Ԫ������
}Player;
Prop *props;
Player *players;
int propsCount = 0;
int playerCount = 0;

void Init();        //������ʼ����Ϸ����
void ShowProps();
void ShowPlayers();
/**
 * ���׺���
 * ����1�����뽻�׵����ָ��-Ϊ�˷����޸���ҽ��׺�Ľ����
 * ����2����ҹ������Ʒid
 */
void Trade(Player *player, int propId);

void Change(Player *player, int key);