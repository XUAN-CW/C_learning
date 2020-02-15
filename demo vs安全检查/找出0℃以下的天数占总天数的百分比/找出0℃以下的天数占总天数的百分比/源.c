#include <stdio.h>
int main(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf("Enter the list of daily low temperatures.\n");
	printf("Use Celsius, and enter q to quit.\n");
	while (scanf("%f", &temperature) == 1)
		/*
			scanf()函数返回成功赋值的数据项数
			这里while(scanf("%f", &score) == 1)语句中，scanf只给一个变量赋值，成功返回1，不成功则返回0
			也就是说 你输入有误（比如说你输入字符、字符串型）就不能成功给score赋值，就会返回0
		*/
	{
		all_days++;
		if (temperature < FREEZING)
		{
			cold_days++;
		}
	}
	if (all_days != 0)
	{
		printf("%d days total: %.1f%% were below freezing.\n",all_days, 100.0 * (float)cold_days / all_days);
	}
	if (all_days == 0)
	{
		printf("No data entered!\n");
	}
	getchar();
	return 0;
}