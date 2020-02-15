#include <stdio.h>
#include <stdlib.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2071

int main()
{
	int groups;
	int peoples;
	double maxNum[2000] = { 0 };
	scanf_s("%d", &groups);
	int i;
	for (i = 0; i < groups; i++)
	{
		scanf_s("%d", &peoples);
		for (int j = 0; j < peoples; j++)
		{
			double currentHigh;
			scanf_s("%lf", &currentHigh);
			maxNum[i] = maxNum[i] > currentHigh ? maxNum[i] : currentHigh;
		}

	}
	for (int k = 0; k < groups; k++)
	{
		printf("%.2lf\n", maxNum[k]);
	}
	return 0;
}
