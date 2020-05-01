#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a, b, c;
	for ( a = 191; a < 333; a++)
	{
		b = a * 2;
		c = a * 3;
		char ok[60] = { 1, 1,1, 1, 1, 1, 1, 1, 1, 1,0 };
		char check[60] = { 1,0 };
		check[ a / 100 ]		++;		//取百位
		check[(a % 100) / 10 ]	++;		//取十位
		check[ a % 10 ]			++;		//取个位
		check[ b / 100]			++;
		check[(b % 100) / 10]	++;
		check[ b % 10]			++;
		check[ c / 100]			++;
		check[(c % 100) / 10]	++;
		check[ c % 10]			++;
		if (strcmp(check, ok) == 0)
		{
			printf("%d %d %d\n", a, b, c);
		}

	}
	return 0;
}


/* https://www.luogu.org/problemnew/show/P1008 */


