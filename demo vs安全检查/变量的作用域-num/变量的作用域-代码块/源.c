#include <stdio.h>
#include <stdlib.h>
int main()
{
	//���һ
	int num1 = 9;
	{
		int num1 = 90;
	}
	printf("%d\n",num1);

	//�����
	int num2 = 9;
	{
		int num2 = 90;
		printf("%d\n", num2);
	}
	
	//�����
	int num3 = 9;
	{
		int num3_1 = 90;
		printf("%d\n", num3+num3_1);
	}

	//�����
	int num4 = 9;
	{
		int num4_1 = 90;
	}
	//printf("%d\n", num4 + num4_1);
	/*
		1������ֻ�����ڶ������ǵ������� 
		2��������һ����������ʱ����������������ʱ����-�Զ�����
		3���������ڵ�ʱ���Ϊ������������
	*/


	system("pause");
	return 0;
}
