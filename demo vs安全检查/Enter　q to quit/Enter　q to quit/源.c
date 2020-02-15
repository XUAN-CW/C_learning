#include <stdio.h>
double power(double n, int p); // ANSI函数原型
			//，第一个double为返回值类型，power(double n, int p)中的double为参数类型
int main(void)
{
	double x, xpow;
	int exp;
	printf("Enter　a　number　and　the　positive　integer　power to　which the　number　will　be　raised.\n");
	printf("Enter　q to　quit.\n");
	while (scanf_s("%lf%d", &x, &exp) == 2)
		/*
		scanf的返回值由后面的参数决定,scanf("%d%d", &a, &b);
		如果a和b都被成功读入，那么scanf的返回值就是2,如果只有a被成功读入，返回值为1,如果a和b都未被成功读入，返回值为0
		如果遇到错误或遇到end of file，返回值为EOF,且返回值为int型.		(EOF为End Of File的缩写，在操作系统中表示资料源无更多的资料可读取)
		所以两个数的都成功读入时进行循环
		*/
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




