

#include<stdio.h>
int main()
{
	/** 
	 * ĸţ����Ŀ == ������ĸţ��Ŀ + Сĸţ��Ŀ
	 * cow0 �� 0`1��ţ
	 */
	
	int i = 0;
	int year[5] = { 0 };
	/** �ɼ���� */
	for (i = 0; 0 != year[i - 1]; i++)
	{
		//scanf("%d", &year[i]);
		scanf_s("%d", &year[i]);
	}
	//����ѭ��ʱ�� i ����ݣ������㣩









	/** ���ݴ��������� */
	int inTheEndCows[5] = { 0 };		//���ţ������
	for (int j = 0; j < i-1; j++)
	{
		/** ����ĳn����ĸţ���� */
		int cow1 = 0, cow2 = 0, cow3 = 0;		
		int cow4 = 1;		//��ţ��ţ
		int newCow = 0;		//����ţ
		for (int currentYear = 1; currentYear <= year[j]; currentYear++)
		{
			newCow = cow4;
			cow4 += cow3;
			cow3 = cow2;
			cow2 = cow1;
			cow1 = newCow;
		}
		/** ��¼ĳn����ĸţ���� */
		inTheEndCows[j] = cow1 + cow2 + cow3 + cow4 ;
	}





	/** ������� */
	for (int k = 0; k < i - 1; k++)
	{
		printf("%d\n", inTheEndCows[k]);
	}
	system("pause");//
	return 0;
}


