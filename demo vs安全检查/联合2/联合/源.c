#include <stdio.h>
#include <stdlib.h>
typedef union
{
	int i;
	char ch[sizeof(int)];
}CHI;

int main()
{
	/* ���ϣ�����ͬһ�ռ� */
	int j;
	CHI chi;
	chi.i = 1234;		//1234(10) == 000004D2(16)
	//С�ˣ���λ��ǰ
	for ( j = 0; j < sizeof(int); j++)
	{
		printf("%02hhx ", chi.ch[j]);
	}
	system("pause");
	return 0;
}