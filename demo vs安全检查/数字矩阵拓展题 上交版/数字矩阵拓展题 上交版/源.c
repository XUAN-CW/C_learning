#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x = 1, y = -1;
	int num = 1;
	int nums = 1;//对角线up的数字数目
	int array[5][5] = { };
	int n;
	int i = 0;
	printf("请输入方阵的阶数：");
	scanf_s("%d", &n);
	while (nums < n + 1)
	{
		switch (nums % 2)
		{
		case 1://奇数
			for (i = 0; i < nums; num++, i++)
			{
				y++;//right
				x--;//up
				array[x][y] = num;
			}//本对角线打印完毕
			y++;//right
			break;
		case 0://偶数
			for (i = 0; i < nums; num++, i++)
			{
				array[x][y] = num;
				y--;//left
				x++;//down
			}//本对角线打印完毕
			x++;//down
			break;
		}
		nums++;
	}
	//下半部分
	nums -= 2;
	if (nums % 2 == 1)
	{
		x--;
		y++;
	}
	while (nums > 0)
	{
		switch (nums % 2)
		{
		case 1://奇数
			for (i = 0; i < nums; num++, i++)
			{
				y++;//right
				x--;//up
				array[x][y] = num;
			}//本对角线打印完毕
			y++;//right
			break;
		case 0://偶数
			for (i = 0; i < nums; num++, i++)
			{
				y--;//left
				x++;//down
				array[x][y] = num;
			}//本对角线打印完毕
			x++;//down
			break;
		}
		nums--;
	}
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			printf("%d \t", array[x][y]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
