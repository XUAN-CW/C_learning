#include <stdlib.h>
{
	char str[5] = { 0 };
	scanf("%5s", str);	//输入 "123456" 会导致溢出，五个格子，放不了六个字符
	return 0;
