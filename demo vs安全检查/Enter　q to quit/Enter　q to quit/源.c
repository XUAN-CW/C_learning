#include <stdio.h>
double power(double n, int p); // ANSI����ԭ��
			//����һ��doubleΪ����ֵ���ͣ�power(double n, int p)�е�doubleΪ��������
int main(void)
{
	double x, xpow;
	int exp;
	printf("Enter��a��number��and��the��positive��integer��power to��which the��number��will��be��raised.\n");
	printf("Enter��q to��quit.\n");
	while (scanf_s("%lf%d", &x, &exp) == 2)
		/*
		scanf�ķ���ֵ�ɺ���Ĳ�������,scanf("%d%d", &a, &b);
		���a��b�����ɹ����룬��ôscanf�ķ���ֵ����2,���ֻ��a���ɹ����룬����ֵΪ1,���a��b��δ���ɹ����룬����ֵΪ0
		����������������end of file������ֵΪEOF,�ҷ���ֵΪint��.		(EOFΪEnd Of File����д���ڲ���ϵͳ�б�ʾ����Դ�޸�������Ͽɶ�ȡ)
		�����������Ķ��ɹ�����ʱ����ѭ��
		*/
	{
		xpow = power(x, exp); // ��������
		printf("%.3g��to��the��power��%d��is��%.5g\n", x, exp, xpow);
		printf("Enter��next��pair��of��numbers��or��q��to��quit.\n");
	}
	printf("Hope��you��enjoyed��this��power��trip��--��bye!\n");
	return 0;
}
double power(double n, int p) // ��������
{
	double pow = 1;
	int i;
	for (i = 1; i <= p; i++)
		pow *= n;
	return pow; // ����pow��ֵ
}




