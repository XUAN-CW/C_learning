#include<stdio.h>
int main()
{
	long long a, b;
	for (; scanf_s("%llx%llx", &a, &b) != EOF;)
	{
		//printf(a + b < 0 ? "-%I64X\n" : "%I64X\n", a + b < 0 ? -a - b : a + b);
		if (a + b < 0)
		{
			/*** %llx —  打印小写，%llX —  打印大写 **/
			//printf("-%llx\n", - a - b);
			printf("-%llX\n", - a - b);
		}
		else
		{
			printf("%llX\n", a + b);
		}
	}
	return 0;
}