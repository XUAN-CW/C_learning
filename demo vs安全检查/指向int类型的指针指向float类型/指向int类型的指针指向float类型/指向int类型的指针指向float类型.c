#include <stdio.h>
#include <stdlib.h>

int main()
{
	//三个数一样说明三个指向不同数据类型的指针大小一致
	printf("%d ", sizeof(char*));
	printf("%d ", sizeof(int*));
	printf("%d ", sizeof(double*));
	printf("\n");

	double test = 100;
	void* p_int = (void*)(&test);
	void* p_double = (void*)(&test);
	if (p_int == p_double)
	{
		printf("%d\n", *((int*)p_int));
		printf("%lf\n", *((double*)p_double));
	}

	//double test = 100;
	//int* p_int = (int*)(&test);
	//double* p_double = &test;
	//if (p_int == p_double)
	//{
	//	printf("%d\n", *p_int);
	//	printf("%lf\n", *p_double);
	//}
	
	
	

	return 0;
}
