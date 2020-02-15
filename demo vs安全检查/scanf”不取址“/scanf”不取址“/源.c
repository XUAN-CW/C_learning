#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int *p_i = &i;
	int address_i = (int)p_i;
	printf("p_i的值为                 ：%p\n",p_i);
	printf("address_i十六进制的值为   ：%x\n", address_i);
	printf("以指针形式打印address_i   ：%p\n", address_i);
	printf("输入i的值:");
	scanf_s("%d", address_i);
	printf("i的值为：%d\n",i);
	system("pause");
	return 0;
}





