#include <stdio.h>
#include<stdlib.h>
int main()
{
	char ch;//chֻ�ܴ���һ���ַ�
	char chArray[10] = { 0 };//����ch
	scanf_s("%c", &ch, sizeof(ch));
	chArray[1] = ch;
	printf("%c", ch);
	system("pause");
	return 0;
}
