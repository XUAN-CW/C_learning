#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
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