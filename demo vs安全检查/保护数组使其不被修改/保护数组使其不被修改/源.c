#include <stdio.h>
#include <stdlib.h>
void text(const int array[]);
int main()
{
	int array[] = { 1,2,3,4,5 };
	//传一个指针,函数会自动将int*转为函数中的const int*
	text(array);
	system("pause");
	return 0;
}

void text(const int array[])
{
	int a;
	a += array[2];
}
