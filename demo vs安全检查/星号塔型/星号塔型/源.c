#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i, j;
	i = 0;
	for (i; i <= 4; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

