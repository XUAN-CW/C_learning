#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


int main()
{
	bool test;

	test = 0;
	test++;
	printf("%d\n", test);

	test = 5;
	test -= 1;
	printf("%d\n", test);


	system("pause");
	return 0;
}
