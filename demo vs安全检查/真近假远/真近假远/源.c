/* paint.c -- ʹ����������� */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int sq_feet;
	int cans;
	int caver = 350; // ÿ�������ˢ���������λ��ƽ��Ӣ�ߣ�
	printf("Enter number of square feet to be painted:\n");
	while (scanf_s("%d", &sq_feet) == 1)
	{
		cans = sq_feet / caver;
		cans += ((sq_feet % caver == 0)) ? 0 : 1;
		printf("You need %d %s of paint.\n", cans,cans == 1 ? "can" : "cans");
		printf("Enter next value (q to quit):\n"); 
	}
	return 0;
}