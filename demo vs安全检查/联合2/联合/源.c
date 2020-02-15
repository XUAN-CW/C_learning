#include <stdio.h>
#include <stdlib.h>
typedef union
{
	int i;
	char ch[sizeof(int)];
}CHI;

int main()
{
	/* 联合，共用同一空间 */
	int j;
	CHI chi;
	chi.i = 1234;		//1234(10) == 000004D2(16)
	//小端，低位在前
	for ( j = 0; j < sizeof(int); j++)
	{
		printf("%02hhx ", chi.ch[j]);
	}
	system("pause");
	return 0;
}