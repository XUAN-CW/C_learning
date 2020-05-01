#pragma once
int counter_1();
int counter_2();
void counter_3();
static int whileCount = 1;

int counter_1()
{
	int count = 0;
	count++;
	return count;
}

int counter_2()
{
	static int count = 0;//第一次执行会分配空间，以后就不再分配
	count++;
	return count;
}

void counter_3()
{
	static int count = 0;//第一次执行会分配空间，以后就不再分配
	
	count++;
	printf("counter被调用了%d次，不退出则次数累加,当前是while的第%d轮\n", count, whileCount);
	return ;
}