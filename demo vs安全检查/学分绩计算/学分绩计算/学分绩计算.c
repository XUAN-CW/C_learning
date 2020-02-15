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
		{"��ѧӢ��1", 85,4},
		{"�ߵ���ѧA1",82,5.5},
		{"�������ѧ����",88,2.5},
		{"˼��",83,3},
		{"����1",69,2},
		{"���Դ���",62,3},
		{"����������",93,0.5},

		{"��ɢ��ѧA1",78,2.5},
		{"����2",72,2},
		{"�й�����ʷ��Ҫ",88,3},
		{"C���Գ������",94,3.5},
		//{"�ߵ���ѧA2",95,5.5},
		//{"��ѧ����",95,4.5},
		//{"��ѧӢ��2", 93,1.5},
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
