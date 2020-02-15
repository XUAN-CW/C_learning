#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	for (i = 0; i < 128; i++)
	{
		printf("ASCII码%d对应的字符为 %c\n", i,i);
	}
	system("pause");
	return 0;
}
