#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x = 1, y = -1;
	int num = 1, nums = 1;
	int array[100][100] = { 0 };
	int n;
	int i = 0;
	printf("请输入方阵的阶数：");
	scanf_s("%d",&n);
	while  (nums < n+1)
	{
		switch (nums % 2)
		{
			case 1://奇数

				for (i=0; i < nums; num++, i++)
				{
					y++;//右
					x--;//上
					array[x][y] = num;
		

				}//记录完毕
				y++;//右移
				break;
			case 0://偶数
				for (i = 0; i < nums; num++,i++)
				{
					array[x][y] = num;
					y--;//左
					x++;//下


				}//记录完毕
				x++;//下移

				break;
		}
		nums++;
	}
	//下半部分
	nums -= 2;
	if (nums % 2 == 1)//去掉本行试试
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
					y++;//右
					x--;//上
					array[x][y] = num;


				}//记录完毕
				y++;//right
				break;
			case 0://偶数
				for (i = 0; i < nums; num++, i++)
				{
					y--;//左
					x++;//下
					array[x][y] = num;

				}//记录完毕
				x++;//dowm
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
