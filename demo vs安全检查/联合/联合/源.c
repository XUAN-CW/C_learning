#include <stdio.h>
#include <stdlib.h>
typedef union try_union
{
	int i;
	double d;
	char c;
}Union;

typedef struct  _people
{
	char name[50];
	union
	{
		int i;
		double d;
		char c;
	};
}People;

int main()
{
	Union test;
	printf("%d\n", sizeof(test));
	test.c = 'a';
	test.d = 0.2;
	test.i = 1;
	printf("%d\n", sizeof(test));
	printf("%d\n", sizeof(test.c));
	printf("%d\n", sizeof(test.i));

	People people;
	people = { "lll",0 };

	int temp = (int)test.d;
	printf("%d\n", test.d);
	printf("%d\n", temp);

	system("pause");
	return 0;
}
