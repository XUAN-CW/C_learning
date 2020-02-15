#include <stdio.h>
#include <stdlib.h>
int * changeNum()
{
	int nums[] = { 1,2,3,4,5 };
	return nums;
}
//函数执行完毕时，会自动销毁函数内部定义的变量
int main()
{
	int * nums = changeNum();
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", *(nums + i));
	}
	system("pause");
	return 0;
}
