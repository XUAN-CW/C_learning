#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array[] = { 1,2,3,4,5 };
	int temp;
	int *p_temp = &temp;
	int *p_array = array;
	//int array[] <==> int const *array=... ...
	//数组的值可以改，但其地址不能改
	array++;

	printf("array指向的地址    %p，该地址中的值为：%d\n", array,*array);
	p_array++;
	printf("p_array指向的地址是%p，该地址中的值为：%d\n",p_array, *p_array);

	system("pause");
	return 0;
}