#include <stdio.h>
#include <stdlib.h>
int main()
{
	char words[] = "Hello";
	printf("%s\n", words);
	char *p = &words[2];
	*p = '\0';
	printf("%s\n", words);
	system("pause");
	return 0;
}