#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 7;
	unsigned char* pc = &i;

	printf("%d\n", i);

	for (int j = 0; j < 4; j++) {
		*pc = 0;
		pc++;
	}

	printf("%d\n", i);

	return 0;
}