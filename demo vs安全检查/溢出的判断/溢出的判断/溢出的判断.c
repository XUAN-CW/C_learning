#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned int x = UINT_MAX - 2, y = 20;
	if (x + y >= x)
	{
		printf("δ���\n");
	}
	else
	{
		printf("���\n");
	}

	
	//x < y ������ x - y < 0
	x = 1;
	y = 2;
	if ((x < y) == (x - y < 0))
	{
		printf("x < y ���� x - y < 0");
	}
	else
	{
		printf("x < y ������ x - y < 0");
	}



	return 0;
}
