#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *text = NULL;

	if (!text)
	{
		printf("NULL为假！\n");
	}

	text = (int*)malloc(sizeof(text));
	if (text)
	{
		printf("malloc之后不为空！\n");
	}
	system("pause");
	return 0;
}