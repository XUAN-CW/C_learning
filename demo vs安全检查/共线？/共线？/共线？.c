

#include<stdio.h>
int main()
{
	/** 
	 * 母牛总数目 == 可生产母牛数目 + 小母牛数目
	 * cow0 — 0`1岁牛
	 */
	
	int i = 0;
	int year[5] = { 0 };
	/** 采集年份 */
	for (i = 0; 0 != year[i - 1]; i++)
	{
		//scanf("%d", &year[i]);
		scanf_s("%d", &year[i]);
	}
	//跳出循环时有 i 个年份（包括零）









	/** 数据处理，保存结果 */
	int inTheEndCows[5] = { 0 };		//最后牛的数量
	for (int j = 0; j < i-1; j++)
	{
		/** 计算某n年后的母牛数量 */
		int cow1 = 0, cow2 = 0, cow3 = 0;		
		int cow4 = 1;		//生牛的牛
		int newCow = 0;		//新生牛
		for (int currentYear = 1; currentYear <= year[j]; currentYear++)
		{
			newCow = cow4;
			cow4 += cow3;
			cow3 = cow2;
			cow2 = cow1;
			cow1 = newCow;
		}
		/** 记录某n年后的母牛数量 */
		inTheEndCows[j] = cow1 + cow2 + cow3 + cow4 ;
	}





	/** 数据输出 */
	for (int k = 0; k < i - 1; k++)
	{
		printf("%d\n", inTheEndCows[k]);
	}
	system("pause");//
	return 0;
}


