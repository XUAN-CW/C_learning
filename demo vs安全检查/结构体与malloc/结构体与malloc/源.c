#include <stdio.h>
#include <stdlib.h>

typedef struct People
{
	int money;
	int weith;
}People;

int main()
{
	//分配空间
	People * text = (People*)malloc(sizeof(People));
	text->money = 10000;
	text->weith = 100;
	printf("%d\n", text->money);

	//不分配空间
	People * text_2;
	text_2->money = 10000;
	text_2->weith = 100;
	printf("%d\n", text_2->money);


	system("pause");
	return 0;
}
