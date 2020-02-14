#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[20][20] = { 0 };
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		a[i][1] = 1;
		a[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= N; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}

	printf("%d", a[N][N]);
	return 0;
}