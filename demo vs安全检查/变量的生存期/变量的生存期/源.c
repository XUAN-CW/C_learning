#include <stdio.h>
#include <stdlib.h>
#include "count.h"

/***
 *auto     �Զ��洢   ֻ�����ڿ�������ı��������У��ֲ�����Ĭ������¹�Ϊ�Զ��洢���� 
 *register �Ĵ����洢 ֻ���ڿ�������ı����������ٶȿ졣����ѭ�������϶��ѭ�����Ʊ�����ѭ�����ڷ���ʹ�õı������ɶ���Ϊ�Ĵ�������
 *static   ��̬�洢   �������ʱ�������󣬳������ʱ������ʧ
 *extern   �ⲿ����   ˵������ʾ�����ı��������ڱ𴦡����������������������ڹᴩӦ�ó���Ŀ�ʼ�ͽ���
**/
extern char  chs[];
int main()
{
	int count_1 = 0;//
	counter_1();
	counter_1();
	counter_1();
	count_1 = counter_1();
	printf("count_1 =%d\t�������ν����Ϊ1\n", count_1);

	int count_2 = 0;//���ڽ��� counter_2() �е�count
	counter_2();
	counter_2();
	counter_2();
	count_2 = counter_2()-1;
	printf("count_2 =%d\t�������ν��Ϊ���ô���\n", count_2);
	printf("%s\n", chs);

	int value;			//�Զ�����-ִ��ѭ���Ĵ���
	register int i;		//��ѭ����������Ϊ�Ĵ����洢ģʽ
	printf("����scanf_s�ķ���ֵ\n");
	//int result = scanf_s("%d", &value);
	//printf("%d\n", result);
	printf("������ѭ��ִ�еĴ�������0�˳���\n");
	while (scanf_s("%d", &value) == 1 && value > 0)
		/***
		 *valueΪ���֣�scanf_s("%d", &value)����ֵΪ1�����򷵻�0
		 *��valueΪ�����ͣ�scanf_s("%d", &value)ֻ��ȡ�������֣�����ֵΪ1
		**/
	{
		for (i = 0; i < value; i++)
		{
			counter_3();
		}
		printf("������ѭ��ִ�еĴ�������0�˳���\n");
		whileCount++;
	}
	//system("pause");
	return 0;
}
