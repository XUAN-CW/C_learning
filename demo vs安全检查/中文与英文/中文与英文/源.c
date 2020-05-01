#include <stdio.h>
#include <stdlib.h>
#define LOANER ' '

int main()
{
	char Chinese[255] = "你好!";		//经观察,在此编译环境下,中文的值为负
	char English[255]="AZaz!";
	char test[255] = "山H水e有l相l逢o";
	int i = 0;
	int j = 0;
	int k = 0;

	//用 LOANER 代替中文,保留英文
	while (test[i]!='\0')
	{
		if (test[i] < 0)
		{
			test[i] = LOANER;
		}
		i++;
	}
	printf("%s\n", test);

	//删除 LOANER
	for ( j = 0; test[j] != '\0'; j++)
	{
		if (test[j]==LOANER)
		{
			for ( k=j; test[k] != '\0'; k++)
			{
				test[k] = test[k + 1];
			}
			j--;		//复位,下一轮 j 与本轮 j 相同,防止多个LOANER导致删除失误
		}
	}
	printf("%s\n", test);




	system("pause");
	return 0;
}
