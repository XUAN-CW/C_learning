#include <stdio.h>
int main(void)
{
	int i;
	char ch;
	for (i = 0, ch = 'A'; i < 6; i++, ch += 2 * i)
	{
		printf("%3c", ch);
	}
	getchar();
	return 0;
}
