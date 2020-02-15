#include <stdio.h>
#include <stdlib.h>
int main()
{
	void *p;
	int count = 0;
	while ((p=malloc(100*1024*1024)))
	{
		count++;
	}
	printf("分配了%d00M的空间\n", count);
	system("pause");
	return 0;
}