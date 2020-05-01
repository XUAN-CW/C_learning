#include <stdio.h>
#include <stdlib.h>
#include "count.h"

/***
 *auto     自动存储   只能用于块作用域的变量声明中，局部变量默认情况下归为自动存储类型 
 *register 寄存器存储 只用于块作用域的变量，请求速度快。对于循环次数较多的循环控制变量及循环体内反复使用的变量均可定义为寄存器变量
 *static   静态存储   载入程序时创建对象，程序结束时对象消失
 *extern   外部变量   说明符表示声明的变量定义在别处。作用域是整个程序，生存期贯穿应用程序的开始和结束
**/
extern char  chs[];
int main()
{
	int count_1 = 0;//
	counter_1();
	counter_1();
	counter_1();
	count_1 = counter_1();
	printf("count_1 =%d\t调用三次结果仍为1\n", count_1);

	int count_2 = 0;//用于接收 counter_2() 中的count
	counter_2();
	counter_2();
	counter_2();
	count_2 = counter_2()-1;
	printf("count_2 =%d\t调用三次结果为调用次数\n", count_2);
	printf("%s\n", chs);

	int value;			//自动变量-执行循环的次数
	register int i;		//将循环变量设置为寄存器存储模式
	printf("测试scanf_s的返回值\n");
	//int result = scanf_s("%d", &value);
	//printf("%d\n", result);
	printf("请输入循环执行的次数（按0退出）\n");
	while (scanf_s("%d", &value) == 1 && value > 0)
		/***
		 *value为数字，scanf_s("%d", &value)返回值为1，否则返回0
		 *若value为浮点型，scanf_s("%d", &value)只读取整数部分，返回值为1
		**/
	{
		for (i = 0; i < value; i++)
		{
			counter_3();
		}
		printf("请输入循环执行的次数（按0退出）\n");
		whileCount++;
	}
	//system("pause");
	return 0;
}
