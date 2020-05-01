/**
 * void* malloc(size_t size);
 * 申请的空间以字节为单位
 * 返回的类型是void*，需要类型转换。如：array=(int*)malloc(n*sizeof(int))
 * 用完记得释放内存，如：free(array)
 * array当数组首地址用即可
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number;
	int * ar;
	int i;
	scanf_s("%d", &number);
	ar = (int*)malloc(number * sizeof(int));
	for ( i = 0; i < number; i++)
	{
		scanf_s("%d", &ar[i]);
	}
	for ( i = 0; i < number; i++)
	{
		printf("%d", ar[i]);
	}
	free(ar);
	system("pause");
	return 0;
}