#include <stdio.h>
#include <stdlib.h>

int MeasureArray();
int array[5];
int main()
{
	//不传参，直接访问该数组
	printf("%d\n", MeasureArray());
	system("pause");
	return 0;
}


int MeasureArray()
{
	return  sizeof(array);
}