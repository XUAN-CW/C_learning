#include <stdio.h>
#include <stdlib.h>
int yanghui(int, int);
int main()
{
	int n;//������ǵ�����
	int i, j;
	printf("������������ǵ�������");
	scanf_s("%d", &n);
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < i + 1; j++)
		{
			printf("%7u", yanghui(i - 1, j - 1));//��%d��Σ�
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

int yanghui(int n, int m)
//��n�е�m�����ɱ�ʾΪC(n-1��m-1)����Ϊ��n-1����ͬԪ����ȡm-1��Ԫ�ص������
//��n>13ʱ��productUp�������productDown�����������������
{
	unsigned long int productUp = 1, productDown = 1, outcome;//��unsigned long long int ����
	int i;
	if (m > n / 2)//���ޱ��䣬�Ƚ��������������������
	{
		m = n - m;//������ϣ����� == ����� 
	}
	for (i = n; i > n - m; i--)
	{
		productUp = productUp * i;
	}
	for (i = 1; i < m + 1; i++)
	{
		productDown = productDown * i;
	}
	outcome = productUp / productDown;
	return outcome;
}


/*
int yanghui(int n, int m)
//��n�е�m�����ɱ�ʾΪC(n-1��m-1)����Ϊ��n-1����ͬԪ����ȡm-1��Ԫ�ص������
//��n>13ʱ��productUp�������productDown�����������������
{
	int productUp=1, productDown=1,outcome;
	int i;
	for (i = n; i > n - m ; i--)
	{
		productUp = productUp * i;
	}
	for (i = 1; i < m + 1; i++)
	{
		productDown = productDown * i;
	}
	outcome = productUp / productDown;
	return outcome;
}
*/