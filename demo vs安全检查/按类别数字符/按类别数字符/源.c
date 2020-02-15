#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
int main()
{
	char chars[1024];
	gets_s(chars,sizeof(chars));
	int alphabetNum = 0;
	int blankNum = 0;
	int numberNum = 0;
	int otherCharNum = 0;
	for (char i = 0; chars[i] != '\0'; i++)
	{
		if ((chars[i] >= 'a'&&chars[i] <= 'z') || (chars[i] >= 'A'&&chars[i] <= 'Z'))
		{
			alphabetNum++;
		}
		else if (' ' == chars[i] )
		{
			blankNum++;
		}
		else if (chars[i] >= '0'&&chars[i] <= '9')
		{
			numberNum++;
		}
		else
		{
			otherCharNum++;
		}
	}
	printf("alphabetNum\t=\t%d\n", alphabetNum);
	printf("blankNum\t=\t%d\n", blankNum);
	printf("numberNum\t=\t%d\n", numberNum);
	printf("otherCharNum\t=\t%d\n", otherCharNum);
	system("pause");
	return 0;
}
