#include <stdio.h>
#include <stdlib.h>
void changeNum()
{
	int num1 = 5, num2 = 8;
	num1 = 55;
	num2 = 288;
}
int main()
{
	int num1 = 4, num2 = 6;
	changeNum();
	printf("num1=%d\tnum2=%d\n", num1, num2);
	system("pause");
	return 0;
}
