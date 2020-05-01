#include <stdio.h>
#include<stdlib.h>
int main()
{
	char ch;//ch只能储存一个字符
	char chArray[10] = { 0 };//监视ch
	scanf_s("%c", &ch, sizeof(ch));
	chArray[1] = ch;
	printf("%c", ch);
	system("pause");
	return 0;
}
