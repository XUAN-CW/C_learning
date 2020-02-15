#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array[100][100] = { 0 };
	int x = 0, y = 0;
	int num = 1;
	int n, m, k = 0;
	printf("请输入您要的方阵阶数：");
	scanf_s("%d", &n);
	m = n;
	while (n > 0)
	{
		for (x; x < n + k; x++)
		{
			array[x][y] = num;
			num++;
		}
		x--;
		num--;
		for (y; y < n + k; y++)
		{
			array[x][y] = num;
			num++;
		}
		y--;
		num--;
		for (x; x > k - 1; x--)
		{
			array[x][y] = num;
			num++;
		}
		x++;
		y--;
		for (y; y > k; y--)
		{
			array[x][y] = num;
			num++;
		}
		x++;
		y++;
		k++;
		n -= 2;
	}
	for (x = 0; x < m; x++)
	{
		for (y = 0; y < m; y++)
		{
			printf("%d \t", array[x][y]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}