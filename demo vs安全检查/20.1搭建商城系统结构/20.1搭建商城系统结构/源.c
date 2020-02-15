#include "store.h"
int main()
{
	int key;
	//��ʼ����Ϸ����
	Init();
	printf("\n*********����ǰ************************\n\n");
	//2����ӡ��Щ��ʼ������
	ShowProps();
	ShowPlayers();
	while (1)
	{
		
		key = _getch() - 48;//����48��key==�����ַ���ASCII��

		if (key == 0)
		{
			break;
		}
		if (key < 0 || key>10)
		{
			printf("������0-4֮�����!\n");
			continue;
		}
	
		Trade(&players[0], key);
		system("cls");//���ø��Ƿ��Ż�
		printf("\n\n*********���׺�************************\n");
		ShowProps();
		ShowPlayers();
		printf("��0�������ף�\n");
	}
	


	system("pause");
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
		if (propId == props[i].id) 
		{
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
		if (propId == props[i].id) 
		printf("Ǯ�����Ǳ�ģ�������ǿ�Ǯ����ᣬ%s������\n", props[propId-1].name);
		return;
	}
	if (player->bag.props[7].id != 0)//player->bag.props[7].id Ĭ��ֵΪ�㣬���е��ߣ�player->bag.props[7].id != 0
		//(player->bag.count >= player->bag.max && player->bag.count != 0)
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
		strcpy_s(player->bag.props[newIndex].name, tradeProp->name);
		strcpy_s(player->bag.props[newIndex].desc, tradeProp->desc);
		player->bag.count++;
	}
}
void Init()
{
	//1����ʼ������
	static Prop propArray[] = 
	{
		{1, "˫�����鿨", 3000, 20, "˫��666"},
		{2, "���õĵ���", 5000, 20,  "ֻ��Զ�۲������棡"},
		{3, "���������", 8000, 20, "����ר��"},
		{4, "�޼���",     13000, 20, "��ǹ���룬ˮ����"},
		{5, "�����",  99999, 20, "����������ʮ��λ������������"},
		{6, "3�����鿨", 3000, 20, "˫��6666"},
		{7, "����", 5000, 20,  "��ǹ���룬ˮ�����"},
		{8, "������", 8000, 20, "һ���˿��ò���"},
		{9, "�޼���",     13000, 20, "��ǹ���룬ˮ����"},
	

	};

	static Player playerArray[] = 
	{
		{1, "����", "123456"},
		{2, "�����", "123456",playerArray[1].bag.max = 8},
		{3, "�����", "123456",playerArray[2].gold = 200000,playerArray[2].bag.max = 8},
		{4, "�ı��", "123456",playerArray[3].gold = 400000,playerArray[3].bag.max = 8}
	};
	playerArray[0].gold = 100000;
	playerArray[0].bag.max = 8;
	playerArray[1].gold = 200000;


	propsCount = sizeof(propArray) / sizeof(Prop);
	playerCount = sizeof(playerArray) / sizeof(Player);
	props = propArray;//�趨ָ���ָ��
	players = playerArray;//�趨ָ���ָ��
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
	printf("\n");
}

void ShowPlayers()
{
	int i;//��i�����
	int j;//��j������
	if (players == NULL) return;
	printf("���\t%-14s���\t\t����\n", "����");
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
