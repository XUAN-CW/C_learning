#include "equipment.h"

/*
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
*/
int main()
{
	Prop weapons[5] =
	{
		{0,"�󱦽�",Weapon,weapons[0].minAttack=100,weapons[0].maxAttack=100},
		{1,"��������",Weapon,weapons[1].minAttack = 200,weapons[1].maxAttack = 200},

	};

	Player players[5] = 
	{
		{1,"����",100,weapons[0]},
		{2,"�����",100,weapons[1]}
	};

	printf("enum��%d %d %d %d %d\n", Weapon, Armor, Con, card, Frag);
	printf("�ṹ����Ĭ��ֵΪ��%d\n", players[0].A);

	printf("װ��ǰ����Ĺ�������%d\n",players[0].Attack);//  .enum�е�Ԫ�أ���weapon��֮��,ö�ٽṹ��Prop������Ԫ��
	players[0].Attack += players[0].weapon[0].maxAttack;
	printf("װ�������Ĺ�������%d\n",players[0].Attack);

	equip(players[0].Attack, players[0].weapon[0].maxAttack);
	printf("װ�������Ĺ�������%d\n", players[0].Attack);

	//Player * player_ptr = players;
	equip_ptr(&players[0]);
	printf("װ�������Ĺ�������%d\n\n", players[0].Attack);



	printf("װ��ǰ�����Ĺ�������%d\n", players[1].Attack);
	equip_ptr(&players[1]);
	printf("װ��������Ĺ�������%d\n\n", players[1].Attack);





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

