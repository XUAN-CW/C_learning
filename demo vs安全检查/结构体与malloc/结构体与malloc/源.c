#include <stdio.h>
#include <stdlib.h>

typedef struct People
{
	int money;
	int weith;
}People;

int main()
{
	//����ռ�
	People * text = (People*)malloc(sizeof(People));
	text->money = 10000;
	text->weith = 100;
	printf("%d\n", text->money);

	//������ռ�
	People * text_2;
	text_2->money = 10000;
	text_2->weith = 100;
	printf("%d\n", text_2->money);


	system("pause");
	return 0;
}
