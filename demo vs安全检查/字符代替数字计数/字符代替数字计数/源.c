#include <stdio.h>
#include<stdlib.h>
int main()
{
	char ch;//ch只能储存一个字符
	for (ch ='a'; ch <='z';ch++)
	{
		printf("The　ASCII　value　for　%c　is　%d.\n", ch, ch);
	}
	system("pause");
	return 0;
}
