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
	static int count = 0;//��һ��ִ�л����ռ䣬�Ժ�Ͳ��ٷ���
	count++;
	return count;
}

void counter_3()
{
	static int count = 0;//��һ��ִ�л����ռ䣬�Ժ�Ͳ��ٷ���
	
	count++;
	printf("counter��������%d�Σ����˳�������ۼ�,��ǰ��while�ĵ�%d��\n", count, whileCount);
	return ;
}