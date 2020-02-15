#include <stdio.h>
int main()
{
	char ch;
	scanf_s("%c", &ch, sizeof(ch));
	while (ch != 'g')
	{
		printf("%c", ch);
		scanf("%c", &ch);
	}
	return 0;
}