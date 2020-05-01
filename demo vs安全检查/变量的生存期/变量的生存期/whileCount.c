extern int whileCount ;//全局变量，用于记录while循环的轮数
#include <stdio.h>
void counter_3();

void counter_3()
{
	static int count = 0;//第一次执行会分配空间，以后就不再分配
	count++;
	printf("counter被调用了%d次，不退出则次数累加\n", count);
	printf("当前是while的第%d轮/n", whileCount);
	return;
}