#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int *p_i = &i;
	int address_i = (int)p_i;
	printf("p_i��ֵΪ                 ��%p\n",p_i);
	printf("address_iʮ�����Ƶ�ֵΪ   ��%x\n", address_i);
	printf("��ָ����ʽ��ӡaddress_i   ��%p\n", address_i);
	printf("����i��ֵ:");
	scanf_s("%d", address_i);
	printf("i��ֵΪ��%d\n",i);
	system("pause");
	return 0;
}





