#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned int x = UINT_MAX - 2, y = 20;
	if (x + y >= x)
	{
		printf("未溢出\n");
	}
	else
	{
		printf("溢出\n");
	}

	
	//x < y 不等于 x - y < 0
	x = 1;
	y = 2;
	if ((x < y) == (x - y < 0))
	{
		printf("x < y 等于 x - y < 0");
	}
	else
	{
		printf("x < y 不等于 x - y < 0");
	}



	return 0;
}
