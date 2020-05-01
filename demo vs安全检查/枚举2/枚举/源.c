#include <stdio.h>
#include <stdlib.h>

enum colors
{
	RED,YELLOW,GREEN,NumCOLORS		//NumCOLORS 枚举的自动计数
};
enum animal
{
	tiger = 1, lion, Elephant = 5
};

int main()
{
	printf("%d\n", RED);
	printf("%d\n", lion);
	system("pause");
	return 0;
}