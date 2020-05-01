#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch;
	ch = getchar();
	putchar(ch);
	printf("\n");

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	printf("EOF\n");
	system("pause");
	return 0;
}