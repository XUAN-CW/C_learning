#include <stdio.h>
#include <stdlib.h>
int divide(int  a, int b, int *result);
int main()
{
	//ͨ��ʹ������������Ĳ�������Ч��Χ�ڵ�ֵ����ʾ������ 0��-1
	//���κ���ֵ������Ч�Ŀ��ܽ��ʱ���ֿ�����
	int a = 5;		//������
	int b = 0;		//����
	int result;
	if (divide(a, b, &result))
	{
		printf("%d/%d=%d\n", a, b, result);
	}
	else
	{
		printf("�����򱻳�������Ϊ��!\n");
	}
	system("pause");
	return 0;
}
int divide(int  a, int b, int *result)
{
	int ret = 1;
	if (a == 0 || b == 0 )
	{
		ret = 0;
	}
	else
	{
		*result = a / b;
	}
	return ret;
}