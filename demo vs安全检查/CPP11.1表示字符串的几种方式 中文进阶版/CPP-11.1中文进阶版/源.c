#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char MSG[100] = "����һ�������ַ�������.";
	char words[100] = "����һ�������ַ�����";
	const char * ptr1 = "ptr1ָ������.";
	char words_2[100] = "ptr2ָ������.";
	char * ptr2;
	ptr2 = words_2;
	puts("������һЩ�ַ���");
	puts(MSG);
	puts(words);
	puts(ptr1);
	//puts(words_2);
	//puts(ptr2);
	//printf("%s\n", ptr1);
	printf("%s\n", ptr2);

	system("pause");
	return 0;
}
