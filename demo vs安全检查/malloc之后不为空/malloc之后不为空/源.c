#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *text = NULL;

	if (!text)
	{
		printf("NULLΪ�٣�\n");
	}

	text = (int*)malloc(sizeof(text));
	if (text)
	{
		printf("malloc֮��Ϊ�գ�\n");
	}
	system("pause");
	return 0;
}