#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Birth
{
	int year;
	int month;
	int day;
};
struct Hero
{
	int id;
	char name[50];
	int level;
	int hp;
	int mp;
	char skill[50];
	struct Birth birth;
};


int main()
{
	/*һ��ָ��ָ��ṹʱ����Ϊ�ṹָ����� 
		�ṹָ������е�ֵ����ָ��Ľṹ�������׵�ַ
	*/
	struct Hero hero;
	hero = { 2,"���˹",10,100,200,"���Ҹ�����", {2018,12,30} };
	struct Hero * ptr_hero = &hero;
	printf("%d\t%s\t%d\t%d\t%d\t%s\t%d.%d.%d\n", hero.id, hero.name, hero.level, hero.hp, hero.mp, hero.skill,
		hero.birth.year, hero.birth.month, hero.birth.day);
	//ָ����ʽṹ��Ա��һ	(*�ṹָ�����).��Ա������
	printf("%d\t%s\t\n", (*ptr_hero).id, (*ptr_hero).name);
	//ָ����ʽṹ��Ա���	�ṹָ�����->��Ա������
	printf("%d\t%s\t\n", ptr_hero->id, ptr_hero->name);

	system("pause");
	return 0;
}

