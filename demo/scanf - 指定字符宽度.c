#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char str[5] = { 0 };
	scanf("%5s", str);	//输入 "123456" 会导致溢出，五个格子，放不了六个字符
	printf("%s",str);
	return 0;
}