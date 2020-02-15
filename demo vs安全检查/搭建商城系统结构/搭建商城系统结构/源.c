#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int main()
{
	//��ʼ����Ϸ����
	Init();
	printf("\n*********����ǰ************************\n");
	//2����ӡ��Щ��ʼ������
	ShowProps();
	ShowPlayers();

	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 3); Trade(&players[0], 3); Trade(&players[0], 3);
	Trade(&players[0], 4);
	Trade(&players[0], 5);

	Trade(&players[3], 1);

	printf("\n\n*********���׺�************************\n");
	ShowProps();
	ShowPlayers();
	return 0;
}
/**
 * ���׺���
 * ����1�����뽻�׵����ָ��-Ϊ�˷����޸���ҽ��׺�Ľ����
 * ����2����ҹ������Ʒid
 */
void Trade(Player *player, int propId)
{
	int i;
	//��Ҫ�жϣ���Ʒ�Ŀ�棬�������������ұ����ռ乻����
	Prop *tradeProp = NULL;//Ҫ�������Ʒָ��
	for (i = 0; i < propsCount; i++)
	{
		if (propId == props[i].id) {
			tradeProp = &props[i];//tradeProp = props + i;
			break;
		}
	}
	if (tradeProp->stock <= 0)
	{
		printf("�����Ҷ�û���������̵궼���������\n");
		return;
	}
	if (player->gold < tradeProp->price)
	{
		printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣡ��\n");
		return;
	}
	if (player->bag.count >= player->bag.max && player->bag.count != 0)
	{
		printf("��������������ʧ�ܣ�\n");
		return;
	}
	//���㽻��������ִ�н��׵�ҵ�����
	//1����Ʒ���-1
	tradeProp->stock--;
	//2����ҽ��-��Ʒ����
	player->gold -= tradeProp->price;
	//*3����ұ�����������
	//�ж���ұ������Ƿ����и���Ʒ

	//����и���Ʒ�������еĸ���Ʒ����+1
	for (i = 0; i < player->bag.count; i++)
	{
		//���Ҫ�������Ʒid �� �����е�ĳ����Ʒid��ͬ
		if (propId == player->bag.props[i].id)
		{
			player->bag.props[i].stock++;
			break;
		}
	}
	if (i == player->bag.count)//���û�и���Ʒ������Ʒ��ӵ������м���
	{
		//�򱳰��д���һ����Ʒ-����һ��Ҫ���׵���Ʒ��Ϣ��������
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
	//1����ʼ������
	static Prop propArray[] = {
		{1, "˫�����鿨", 3000, 10, "˫��666"},
		{2, "���õĵ���", 5000, 8,  "ֻ��Զ�۲������棡"},
		{3, "���������", 8000, 10, "����ר��"},
		{4, "�޼���",     13000, 5, "��ǹ���룬ˮ����"},
		{5, "ֱ��1����",  83000, 10, "�����Ժ�׼�����ٳ��ٳ��ٳԡ�����"},
	};
	propsCount = sizeof(propArray) / sizeof(Prop);
	props = propArray;//�趨ָ���ָ��
	static Player playerArray[] = {
		{1, "����ëë��", "123456",.gold = 5000000,.bag.max = 8},
		{2, "���ް�����", "123456",.gold = 150000,.bag.max = 8},
		{3, "Ԫʼ����֮ͽ", "123456",.gold = 500000,.bag.max = 8},
		{4, "�Ǻ�", "123456",.gold = 1150000,.bag.max = 8}
	};
	playerCount = 4;
	players = playerArray;

}
void ShowProps()
{
	int i;
	if (props == NULL) return;
	printf("%-5s%-14s%-7s\t���\t��Ʒ����\n", "���", "����", "����");
	for (i = 0; i < propsCount; i++)
	{
		printf("%-5d%-14s%-7.0lf\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
	}
}
void ShowPlayers()
{
	int i, j;
	if (players == NULL) return;
	printf("���\t%-14s���\n", "����");
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







