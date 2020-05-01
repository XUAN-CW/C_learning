#include <stdio.h>
#include <stdlib.h>
#include <string.h> //支持字符串操作
#include <windows.h>
#include <mmsystem.h>
//#define MAX 200   //常量MAX表示系统要求的最大同学数量
int main()
{
	int i = 5;
	char names[200][20] = { "貂蝉", "杨玉环", "不知火舞", "西施", "柳岩" };
	for (i; strcmp("q", names[i - 1]) != 0; i++)
		//0-两个字符串相等；1-前一个大于后一个；-1-前一个小于后一个
	{
		printf("1、请输入同学的名字：\t\t（增加功能）\n");
		scanf_s("%s", names[i], sizeof(names));
	}
	system("pause");
	return 0;
}