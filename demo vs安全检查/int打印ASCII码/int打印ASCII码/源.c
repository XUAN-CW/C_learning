#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	for (i = 0; i < 128; i++)
	{
		printf("ASCII��%d��Ӧ���ַ�Ϊ %c\n", i,i);
	}
	system("pause");
	return 0;
}
