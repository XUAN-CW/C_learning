#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=0;
	char a[100][100] = {"ÄãºÃ" "," "ÖÐ¹ú£¡" };
	while (i < 2)
	{
		printf("%s\n\n", a[i]);
		i++;
	}
	system("pause");
	return 0;
}


