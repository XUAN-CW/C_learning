#include <stdio.h>
#include <stdlib.h>
void text(int array[]);
void text_2(int *array);
int main()
{
	int i;
	int array[]	  = { 0,1,2,3,4,5,6,7 };
	int array_2[] = { 0,1,2,3,4,5,6,7 };
	int array_3[] = { 0,1,2,3,4,5,6,7 };
	int array_4[] = { 0,1,2,3,4,5,6,7 };
	int array_5[] = { 0,1,2,3,4,5,6,7 };
	int *p_array_3 = array_3;
	int *p_array_4_2= &array_4[2];

	
	text(array);
	for ( i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		printf("%-4d", array[i]);
	}
	printf("\n");

	text_2(array_2);
	for (i = 0; i < sizeof(array_2) / sizeof(array_2[0]); i++)
	{
		printf("%-4d", array_2[i]);
	}
	printf("\n");

	p_array_3[2] = -1;
	for (i = 0; i < sizeof(array_3) / sizeof(array_3[0]); i++)
	{
		printf("%-4d", array_3[i]);
	}
	printf("\n");

	p_array_4_2[2] = -1;
	for (i = 0; i < sizeof(array_4) / sizeof(array_4[0]); i++)
	{
		printf("%-4d", array_4[i]);
	}

	printf("\n");
	*array_5 = -1;
	for (i = 0; i < sizeof(array_5) / sizeof(array_5[0]); i++)
	{
		printf("%-4d", array_5[i]);
	}

	system("pause");
	return 0;
}
void text(int array[])
{
	array[3] = -1;
}

void text_2(int *array)
{
	array[3] = -1;
}