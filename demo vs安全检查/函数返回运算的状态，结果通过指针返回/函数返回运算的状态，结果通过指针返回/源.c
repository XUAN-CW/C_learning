#include <stdio.h>
#include <stdlib.h>
int divide(int  a, int b, int *result);
int main()
{
	//通常使函数返回特殊的不属于有效范围内的值来表示出错，如 0、-1
	//当任何数值都是有效的可能结果时，分开返回
	int a = 5;		//被除数
	int b = 0;		//除数
	int result;
	if (divide(a, b, &result))
	{
		printf("%d/%d=%d\n", a, b, result);
	}
	else
	{
		printf("除数或被除数不能为零!\n");
	}
	system("pause");
	return 0;
}
int divide(int  a, int b, int *result)
{
	int ret = 1;
	if (a == 0 || b == 0 )
	{
		ret = 0;
	}
	else
	{
		*result = a / b;
	}
	return ret;
}