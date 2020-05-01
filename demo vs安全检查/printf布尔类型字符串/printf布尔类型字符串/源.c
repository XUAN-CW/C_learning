#include <stdio.h>
#include <stdlib.h>
int main()
{
	_Bool snake[4] = { 1,0,1,0};
	char mode[4] = { '0' };
	//mode[0] = snake[0];
	//mode[1] = snake[1];
	//mode[2] = snake[2];
	//mode[3] = snake[3];
	//snake[1] = mode[0];
	printf("%d", snake[0]);
	printf("%d", snake[1]);
	printf("%d", snake[2]); 
	printf("%d", snake[3]);
	system("pause");
	return 0;
}
