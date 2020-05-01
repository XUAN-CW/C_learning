#include <stdio.h>
#include <stdlib.h>
int main()
{
	//情况一
	int num1 = 9;
	{
		int num1 = 90;
	}
	printf("%d\n",num1);

	//情况二
	int num2 = 9;
	{
		int num2 = 90;
		printf("%d\n", num2);
	}
	
	//情况三
	int num3 = 9;
	{
		int num3_1 = 90;
		printf("%d\n", num3+num3_1);
	}

	//情况四
	int num4 = 9;
	{
		int num4_1 = 90;
	}
	//printf("%d\n", num4 + num4_1);
	/*
		1、变量只存在于定义它们的语句块中 
		2、变量在一个块内声明时创建，在这个块结束时销毁-自动变量
		3、变量存在的时间称为变量的生存期
	*/


	system("pause");
	return 0;
}
