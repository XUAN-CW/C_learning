#include <stdio.h>
#include <stdlib.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2033

typedef struct
{
	int h;
	int min;
	int s;
}Time;

int main()
{
	int N;
	scanf_s("%d", &N);
	//Time* time = (Time*)malloc(sizeof(Time) * N);
	Time time[1000] = { 0 };
	int AH, AM, AS, BH, BM, BS;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d%d%d%d%d%d", &AH, &AM, &AS, &BH, &BM, &BS);
		time[i].s = AS + BS;
		time[i].min = AM + BM;
		time[i].h = AH + BH;
		if (time[i].s >= 60)
		{
			time[i].s -= 60;
			time[i].min++;
		}
		if (time[i].min >= 60)
		{
			time[i].min -= 60;
			time[i].h++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d %d %d\n", time[i].h, time[i].min, time[i].s);
	}
	//free(time);
	return 0;
}
