extern int whileCount ;//ȫ�ֱ��������ڼ�¼whileѭ��������
#include <stdio.h>
void counter_3();

void counter_3()
{
	static int count = 0;//��һ��ִ�л����ռ䣬�Ժ�Ͳ��ٷ���
	count++;
	printf("counter��������%d�Σ����˳�������ۼ�\n", count);
	printf("��ǰ��while�ĵ�%d��/n", whileCount);
	return;
}