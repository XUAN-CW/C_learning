#include <stdio.h>
#include <stdlib.h>

//https://zhidao.baidu.com/question/1694991703176327708.html

int main()
{
	int range;
	for (;scanf_s("%d",&range); )
	{
		if (-1 == range)
		{
			break;
		}
		long long int fn_2 = 0;
		long long int fn_1 = 1;
		long long int fn = 1;
		if (0 == range)
		{
			fn = 0;
		}

		if (1 == range)
		{
			fn = 1;
		}
		if (range > 1)
		{
			for (int i = 1; i < range; i++)
			{
				long long int temp = fn_1;
				fn = fn_2 + temp;
				fn_1 = fn;
				fn_2 = temp;
			}
		}
		printf("%lld\n", fn);
	}
	return 0;
}
