#include <stdio.h>
#include <stdlib.h>

int MeasureArray();
int array[5];
int main()
{
	//�����Σ�ֱ�ӷ��ʸ�����
	printf("%d\n", MeasureArray());
	system("pause");
	return 0;
}


int MeasureArray()
{
	return  sizeof(array);
}