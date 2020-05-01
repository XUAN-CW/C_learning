/**
 * malloc没free->长时间运行内存逐渐下降
 */





#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p1 = NULL;
	p1 = (int*)malloc(100 * sizeof(int));
	p1++;
	//free(p1);		//p1没有指向原来申请来的空间的首地址，触发断点

	int i;
	int *p2 = &i;
	//free(p2);		//p2不是申请来的空间的首地址，触发断点

	int *p3 = NULL;
	free(p3);		//可以free(NULL)

	int *p4 = NULL;
	p4 = (int*)malloc(1024 * sizeof(int));
	free(p4);
	free(p4);		//free过了再free，触发断点


	system("pause");
	return 0;
}