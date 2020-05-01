#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != '.')
	{
		if (ch == '*')
		{
			i++;
		}
	}
	printf("%d", i);
	system("pause");

	return 0;
}