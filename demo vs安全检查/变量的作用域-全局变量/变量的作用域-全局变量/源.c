#include <stdio.h>
#include <stdlib.h>
int count;//ȫ�ֱ���-��Ĭ��ֵ,Ĭ��ֵΪ��
void changeNum()
{
	count++;
}
int main()
{
	changeNum();
	changeNum();
	printf("count=%d\n", count);
	system("pause");
	return 0;
}
