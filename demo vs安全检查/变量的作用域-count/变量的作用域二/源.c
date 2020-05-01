#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	//情况一
	int count = 0; 
	do{
		int count = 0;
		count++;
		printf("count1=%d\n", count);
		count++;
	}while(count < 1);
	printf("count = %d\n", count);
	//情况二



	system("pause");
	return 0;

}
