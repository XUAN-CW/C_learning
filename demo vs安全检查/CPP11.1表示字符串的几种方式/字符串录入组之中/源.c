#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char MSG[] = "I　am　a　symbolic　string　constant.";
	char words[] = "I　am　a　string　in　an　array.";
	const char * pt1 = "Something is pointing at me.";
	puts("Here　are　some　strings:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);
	system("pause");
	return 0;
}
