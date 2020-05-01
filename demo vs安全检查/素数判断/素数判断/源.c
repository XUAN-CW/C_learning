#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>
#include <mmsystem.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
int main()
{
	int i;
	int n;
	int k;
	char ny[10000];
	scanf_s("%d", &n);
	if (n < 3)
		printf("y\n");
	for (i = 2; i < n; i++)
	{
		//可逆，则因子不止两个
		k = n / i;
		if (k*i == n)
			ny[i] = 'n';
		if (k*i != n)
			ny[i] = 'y';
	}
	for (i = 2; i < n; i++)
	{
		if (ny[i] == 'n')//有一个可逆，则不是素数
		{
			printf("n\n");
			break;
		}
	}
	if (i == n && n != 2)
		printf("y\n");
	system("pause");
	return 0;
}