#include <stdio.h>
#include <stdlib.h>
int yanghui(int, int);
int main()
{
	int n;//杨辉三角的行数
	int i, j;
	printf("请输入杨辉三角的行数：");
	scanf_s("%d", &n);
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < i + 1; j++)
		{
			printf("%7u", yanghui(i - 1, j - 1));//用%d如何？
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

int yanghui(int n, int m)
//第n行的m个数可表示为C(n-1，m-1)，即为从n-1个不同元素中取m-1个元素的组合数
//当n>13时，productUp先溢出，productDown后溢出，造成运算错误
{
	unsigned long int productUp = 1, productDown = 1, outcome;//用unsigned long long int 试试
	int i;
	if (m > n / 2)//若无本句，比较容易溢出，造成运算错误
	{
		m = n - m;//排列组合：五抽二 == 五抽三 
	}
	for (i = n; i > n - m; i--)
	{
		productUp = productUp * i;
	}
	for (i = 1; i < m + 1; i++)
	{
		productDown = productDown * i;
	}
	outcome = productUp / productDown;
	return outcome;
}


/*
int yanghui(int n, int m)
//第n行的m个数可表示为C(n-1，m-1)，即为从n-1个不同元素中取m-1个元素的组合数
//当n>13时，productUp先溢出，productDown后溢出，造成运算错误
{
	int productUp=1, productDown=1,outcome;
	int i;
	for (i = n; i > n - m ; i--)
	{
		productUp = productUp * i;
	}
	for (i = 1; i < m + 1; i++)
	{
		productDown = productDown * i;
	}
	outcome = productUp / productDown;
	return outcome;
}
*/