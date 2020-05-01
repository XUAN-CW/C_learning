#include <stdio.h>
#include <stdlib.h>
int count;//全局变量-有默认值,默认值为零
void changeNum()
{
	count++;
}
int main()
{
	changeNum();
	changeNum();
	printf("count=%d\n", count);
	system("pause");
	return 0;
}
