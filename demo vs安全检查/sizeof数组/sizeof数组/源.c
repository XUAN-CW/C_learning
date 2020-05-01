#include <stdio.h>
#include <stdlib.h>

int globalVariable_Array[4];

int GlobalVariable_Array();
int LocalVariable(int localVariable[]);
int Array_2D_WithNumber(int array_2D[4][3]);
int ArrayWithNumber(int array[4]);
int main()
{
	int localVariable[4] = { 0 };
	int array_2D[4][3];
	printf("做全局变量的数组在函数中sizeof的结果：%d\n", GlobalVariable_Array());
	printf("做局部变量的数组在函数中sizeof的结果：%d\n", LocalVariable(localVariable));
	printf("做局部变量的带数字数组在函数中sizeof的结果：%d\n", ArrayWithNumber(localVariable));
	printf("做局部变量的带数字二维数组在函数中sizeof的结果：%d\n", Array_2D_WithNumber(array_2D));
	system("pause");
	return 0;
}

int GlobalVariable_Array()
{
	return (sizeof(globalVariable_Array) / sizeof(globalVariable_Array[0]));
}

int LocalVariable(int localVariable[])
{
	return (sizeof(localVariable) / sizeof(localVariable[0]));
}

int Array_2D_WithNumber(int array_2D[4][3])
{
	return (sizeof(array_2D) / sizeof(array_2D[0]));
}

int ArrayWithNumber(int array[4])
{
	return (sizeof(array) / sizeof(array[0]));
}