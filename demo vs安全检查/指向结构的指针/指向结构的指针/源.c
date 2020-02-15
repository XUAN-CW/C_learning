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
	/*一个指针指向结构时，称为结构指针变量 
		结构指针变量中的值是所指向的结构变量的首地址
	*/
	struct Hero hero;
	hero = { 2,"香克斯",10,100,200,"给我个面子", {2018,12,30} };
	struct Hero * ptr_hero = &hero;
	printf("%d\t%s\t%d\t%d\t%d\t%s\t%d.%d.%d\n", hero.id, hero.name, hero.level, hero.hp, hero.mp, hero.skill,
		hero.birth.year, hero.birth.month, hero.birth.day);
	//指针访问结构成员其一	(*结构指针变量).成员变量名
	printf("%d\t%s\t\n", (*ptr_hero).id, (*ptr_hero).name);
	//指针访问结构成员其二	结构指针变量->成员变量名
	printf("%d\t%s\t\n", ptr_hero->id, ptr_hero->name);

	system("pause");
	return 0;
}

