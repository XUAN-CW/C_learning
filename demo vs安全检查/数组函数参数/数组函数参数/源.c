#include <stdio.h>
#include <stdlib.h>
#define N 5
//书写一个小型的学生成绩管理系统
//录入函数
void input(double[]);
void sort(double[]);
void show(double[]);
//向传入的数组中查找num，如果存在，返回下标，不存在，返回-1
int find(double *, int);

int main()
{
	//量数组的大小
	double test[] = { 1, 2, 3, 4 , 5, 6, 4 };
	printf("test数组的元素个数：%d\n", sizeof(test) / sizeof(test[0]));


	double scores[N];
	double findNum; //要查找的数字
	//1、录入
	input(scores);
	printf("排序前：\n");
	show(scores);
	//2、排序
	sort(scores);
	//3、按照某种格式打印
	printf("排序后：\n");
	show(scores);

	printf("请输入要查找的数字：");
	scanf_s("%lf", &findNum);
	printf("找到的数字下标为：%d\n", find(scores, findNum));
	system("pause");
	return 0;
}

int find(double * scores, int findNum)
{
	int findIndex = -1;//要查找的下标
	int i;
	for (i = 0; i < N; i++)
	{
		//if(findNum == *(scores + i))
		if (findNum == scores[i])
		{
			//记录下要查找的下标，结束查找动作
			findIndex = i;
			break;
		}
	}
	return findIndex;
}


void input(double  scores[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("请输入第%d门课的成绩：", i + 1);
		scanf_s("%lf", &scores[i]);
		//scanf("%lf", (scores + i));
	}
}
void sort(double scores[])
{
	int i, j;
	double temp;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (scores[j] > scores[j + 1])
			{
				temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;
			}
		}
	}
}

void show(double scores[])
{
	int i;
	printf("***********************************************\n");
	printf("语文\t数学\t英语\t物理\t化学\n");
	for (i = 0; i < N; i++)
	{
		printf("%.2lf\t", *(scores + i));
	}
	printf("\n***********************************************\n");
}


