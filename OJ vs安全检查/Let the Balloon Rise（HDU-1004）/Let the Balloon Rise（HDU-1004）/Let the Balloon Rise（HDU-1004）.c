#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Balloon
{
	char color[20];
	int number;
}Balloon;

int main()
{
	int N;
	for (; scanf_s("%d", &N); )
	{
		if (0 == N)
		{
			return 0;
		}

		Balloon balloon[1000] = { 0 };
		char currentColor[20];
		int numberOfColors = 0;		//气球的数量 - 1
		for (int i = 0; i < N; i++)
		{
			scanf_s("%s", currentColor, sizeof(currentColor));

			int check = 0;
			for (check = 0; check < numberOfColors; check++)
			{
				if (0 == strcmp(currentColor, balloon[check].color))	//有一毛一样的
				{
					balloon[check].number++;							//一模一样的气球数目加一
					check = -1;
					break;
				}
			}
			if (check == numberOfColors)		//没有一毛一样的，添加该颜色
			{
				strcpy_s(balloon[numberOfColors].color, sizeof(currentColor), currentColor);
				balloon[numberOfColors].number = 1;
				numberOfColors++;
			}
		}
		int maxIndex = 0;	//最大气球数的下标
		for (int i = 0; i < numberOfColors + 1; i++)
		{
			maxIndex = balloon[maxIndex].number > balloon[i].number ? maxIndex : i;
		}
		printf("%s\n", balloon[maxIndex].color);
	}
}
