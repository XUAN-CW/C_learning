#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;			
	double grade[]  =	{ 88,   93,   83,   60,   85,    85};	//课程成绩
	double credit[] =	{ 2.5,  0.5,   3,   3,    4,    5.5};	//该课程学分
	double GPA = 0;					//学分绩
	double currGPA = 0;				//当前科目的学分绩
	double creditSum = 0;			//学分之和
	//求学分之和
	for (i = 0; i < sizeof(grade)/sizeof(grade[0]); i++)
	{
		creditSum += credit[i];
	}
	//计算GPA
	for (i = 0; i < sizeof(grade) / sizeof(grade[0]); i++)
	{
		currGPA=credit[i] * grade[i]/ creditSum;
		GPA += currGPA;
	}
	printf("您的学分绩为：%lf\n\n", GPA);
	system("pause");
	return 0;
}