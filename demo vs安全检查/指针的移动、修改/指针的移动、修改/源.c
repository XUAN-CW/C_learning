#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char * words = "abcd";
	char chs[50];
	printf("指针移动前:%s\n", words);
	words += 1;
	printf("指针移动后:%s\n", words);
	words = "你好";
	printf("指针再次赋值:%s\n", words);
	scanf_s("%s", chs,50);
	words = chs;
	printf("指针的动态录入:%s\n", words);





	//char emperorName[50];   //皇帝的名号
	//printf("请输入当前登基的皇帝名号：");
	//scanf_s("%s", emperorName, 40);   //录入字符串时，不需要&符号
	//printf("皇帝《%s》驾临,有事上奏，无事退朝！\n", emperorName);




	system("pause");
	return 0;
}



