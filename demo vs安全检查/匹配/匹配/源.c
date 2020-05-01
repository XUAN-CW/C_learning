#include<stdio.h>
#include <stdlib.h>
int main()
{
	char A, B, C;
	int i, j;
	//int matching[3][3] =
	//{		// A B C
	//	/*X*/ {0,1,0},
	//	/*Y*/ {1,1,1},
	//	/*Z*/ {1,1,0}
	//};
	printf("A=Z B=X C=Y \n");
	for (i = 0; i < 3; i++)
	{
		A = 'X' + i;
		for (j = 0; j < 2; j++)
		{
			B = 'X' + (i + 1 + j) % 3;
			//C = 'X' + (3 - i - j);
			C   = 3*'Y'-A - B  ;
			if (A != 'X' && C != 'X' && C != 'Z')
				printf("A=%c B=%c C=%c \n", A, B, C);
		}
	}
	system("pause");
	return 0;
}
