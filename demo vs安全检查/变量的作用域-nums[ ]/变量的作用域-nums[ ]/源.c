#include <stdio.h>
#include <stdlib.h>
int * changeNum()
{
	int nums[] = { 1,2,3,4,5 };
	return nums;
}
//����ִ�����ʱ�����Զ����ٺ����ڲ�����ı���
int main()
{
	int * nums = changeNum();
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", *(nums + i));
	}
	system("pause");
	return 0;
}
