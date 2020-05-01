#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//http://acm.hdu.edu.cn/viewcode.php?rid=29108062

typedef struct acmer
{
	char name[15];
	int timeScore;
	int AC;
}acmer;

acmer Acmer[2000];

/*** 根据信息得到时间分 **/
int GetTimeScoreFormInfoemation(char information[], int m);

/*** qsort() 辅助函数  **/
int cmp(const void* a, const void* b);

int main()
{
	int n;	//题目数
	int m;	//单位惩罚分
	scanf_s("%d%d", &n, &m);

	//int n = 2;	//题目数
	//int m = 1;	//单位惩罚分

	char information[15] = { 0 };
	int timeScore;
	int currentACMer = 0;

	/*** 信息采集与处理 **/
	for (; EOF != scanf_s("%s", Acmer[currentACMer].name, sizeof(Acmer[currentACMer].name)); currentACMer++)
	{
		Acmer[currentACMer].AC = 0;
		Acmer[currentACMer].timeScore = 0;

		//ACM 中, 测试用例都是存在文件里面的。在自动测试时, 会以文件作为输出, 实际输入的是文件的内容
		//为了方便测试，在此设置一个循环出口，提交时记得注释掉
		//if ('0' == Acmer[currentACMer].name[0])		
		//{
		//	break;
		//}

		for (int j = 0; j < n; j++)
		{
			scanf_s("%s", information, sizeof(information));

			timeScore = GetTimeScoreFormInfoemation(information, m);
			if (timeScore > 0)
			{
				Acmer[currentACMer].AC++;
				Acmer[currentACMer].timeScore += timeScore;
			}
		}
	}

	//acmer Acmer[] =
	//{
	//	{"ab",1	,5	},
	//	{"ad",1	,4	},
	//	{"aa",2	,4	},
	//	{"ae",2	,4	},
	//	{"dd",1	,3	},
	//	{"ac",1	,5	},
	//	{"af",3	,5	},
	//	{"ag",4	,5	},
	//	{"de",2	,3	},
	//	{"df",4	,4	},
	//};
	//currentACMer = sizeof(Acmer) / sizeof(acmer);

	/*** qsort多级排序 **/
	qsort(Acmer, currentACMer, sizeof(acmer), cmp);

	/*** 输出 **/
	for (int j = 0; j < currentACMer; j++)
	{
		printf("%-10s %2d %4d\n", Acmer[j].name, Acmer[j].AC, Acmer[j].timeScore);

		//printf("%2d %4d %-10s\n",Acmer[j].AC,  Acmer[j].timeScore ,Acmer[j].name);
	}

	return 0;

}

/*** 根据信息得到时间分 **/
int GetTimeScoreFormInfoemation(char information[], int m)
{
	/*** 没做对，直接零分 **/
	if ('-' == information[0] || '0' == information[0])
	{
		return 0;
	}

	/*** 做对了，统计时间分 **/
	int WA = 0;
	int timeSpent = 0;		//实际花费的时间
	int punishTimes = 0;	//罚分次数
	for (int i = 0; '\0' != information[i]; i++)
	{
		if ('(' == information[i])
		{
			for (i++; ')' != information[i]; i++)
			{
				punishTimes = punishTimes * 10 + (information[i] - '0');
			}

			break;
		}

		timeSpent = timeSpent * 10 + (information[i] - '0');
	}

	return timeSpent + punishTimes * m;
}

/*** qsort() 辅助函数  **/
int cmp(const void* a, const void* b)
{
	/*** 转换成需要的类型 **/
	acmer* A = (acmer*)a;
	acmer* B = (acmer*)b;

	/*** 定义排序方式 **/
	if (A->AC != B->AC)
	{
		// A->xxx - B->xxx ：升序
		// B->xxx - A->xxx ：降序
		return B->AC - A->AC;
	}
	else if (A->timeScore != B->timeScore)
	{
		return A->timeScore - B->timeScore;
	}
	return strcmp(A->name, B->name);
}

