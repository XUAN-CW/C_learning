#include <stdio.h>
#include <stdlib.h>

int main()
{
	char test[] = "test";

	test[sizeof(test) / sizeof(test[0]) - 1] = '-';
	printf("%s\n", test);
	for (int i = 0; test[i] != '\0'; i++)
	{
		printf("%c", test[i]);
	}
	printf("\n");

	//test[sizeof(test) / sizeof(test[0])] = '\0';
	*(test + sizeof(test) / sizeof(test[0])) = '\0';
	printf("%s\n", test);
	for (int i = 0; test[i] != '\0'; i++)
	{
		printf("%c", test[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}



/*** 结果证明，printf 不到'\0' 不会停止 **/