#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	/*** 数组满了就不不了终止符 '\0' 了 **/
	char ok[10] = { 1,1, 1, 1, 1, 1, 1, 1, 1,0 };
	char check[10] = { 1,1, 1, 1, 1, 1, 1, 1, 1,0 };
	printf("%d\n", strcmp(ok, check));
	
	char ok_[10] = { 1,1, 1, 1, 1, 1, 1, 1, 1 };
	char check_[10] = { 1,1, 1, 1, 1, 1, 1, 1, 1 };
	printf("%d\n", strcmp(ok_, check_));

	char test[5];
	char* p_test = test;
	printf("%d", *(p_test + 6));

	//int string[100];
	//scanf_s("%s", string);
	//printf("%s", string);

	return 0;
}
