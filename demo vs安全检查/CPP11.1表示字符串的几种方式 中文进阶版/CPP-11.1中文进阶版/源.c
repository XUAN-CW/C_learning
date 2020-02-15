#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char MSG[100] = "我是一个符号字符串常量.";
	char words[100] = "我是一段中文字符串！";
	const char * ptr1 = "ptr1指向了我.";
	char words_2[100] = "ptr2指向了我.";
	char * ptr2;
	ptr2 = words_2;
	puts("这里有一些字符串");
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
