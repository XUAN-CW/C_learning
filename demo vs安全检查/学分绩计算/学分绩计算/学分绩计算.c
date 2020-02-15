#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[30];
	double totalScore;
	double credit;
}Subject;

int main()
{
	Subject mySubjects[] =
	{
		{"大学英语1", 85,4},
		{"高等数学A1",82,5.5},
		{"计算机科学导论",88,2.5},
		{"思修",83,3},
		{"体育1",69,2},
		{"线性代数",62,3},
		{"形势与政策",93,0.5},

		{"离散数学A1",78,2.5},
		{"体育2",72,2},
		{"中国近代史纲要",88,3},
		{"C语言程序设计",94,3.5},
		//{"高等数学A2",95,5.5},
		//{"大学物理",95,4.5},
		//{"大学英语2", 93,1.5},
	};
	double grade = 0;
	double theSumOfCredits = 0;
	for (int i = 0; i < sizeof(mySubjects)/sizeof(mySubjects[0]); i++)
	{
		grade += (mySubjects[i].totalScore) * (mySubjects[i].credit);
		theSumOfCredits += mySubjects[i].credit;
	}
	printf("%.2lf", grade / theSumOfCredits);
	return 0;
}
