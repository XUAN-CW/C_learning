#include <stdio.h>
#include <stdlib.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2031

int main()
{
	int N;
	int R;
	for (  ; EOF != scanf_s("%d%d",&N,&R); )
	{
		int num[20] = { 0 };
		int i;
		if (N < 0)
		{
			printf("-");
			N = -N;
		}
		for (i = 0; 0 != N; i++)
		{
			num[i] = N % R;
			N /= R;
		}
		for (i--; i >= 0; i--)
		{
			if (num[i] >= 10)
			{
				num[i] = num[i] - '0' + 'A' - 10;
			}
			printf("%c", num[i] + '0');
		}
		printf("\n");
	}
	return 0;
}
