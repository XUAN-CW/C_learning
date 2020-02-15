#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i = 0;
	char a[100][100] = { "你好" "," "中国！" };
	int nums[10] = {11,22};
	while (i < 2)
	{
		printf("%s\n", a[i]);
		i++;
	}
	printf("%d\n", sizeof(a[0]));
	printf("%d\n", strlen(a[0]));//量字符串
	printf("%d\n", sizeof(nums));
	//printf("%d\n", strlen(num));
	system("pause");
	return 0;
}


