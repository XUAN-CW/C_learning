#include <stdio.h>
#include <stdlib.h>
int main()
{
	double i = 1;
	int j;
	for (; j < 101; j++)
	{
		i *= 1.08;

	}
	for (; i < 101; i++)
	{
		i *= 1.08;
	}
	printf("%lf", i);
	system("pause");
	return 0;
}