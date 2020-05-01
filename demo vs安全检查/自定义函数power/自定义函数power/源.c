#include <stdio.h>
double power(double n, int p); // ANSI函数原型
			//，第一个double为返回值类型，power(double n, int p)中的double为参数类型
int main(void)
{
	double x, xpow;
	int exp;
	printf("Enter　a　number　and　the　positive　integer　power");
	printf("　to　which\nthe　number　will　be　raised.　Enter　q");
	printf("　to　quit.\n");
	while (scanf_s("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp); // 函数调用
		printf("%.3g　to　the　power　%d　is　%.5g\n", x, exp, xpow);
		printf("Enter　next　pair　of　numbers　or　q　to　quit.\n");
	}
	printf("Hope　you　enjoyed　this　power　trip　--　bye!\n");
	return 0;
}
double power(double n, int p) // 函数定义
{
	double pow = 1;
	int i;
	for (i = 1; i <= p; i++)
		pow *= n;
	return pow; // 返回pow的值
}