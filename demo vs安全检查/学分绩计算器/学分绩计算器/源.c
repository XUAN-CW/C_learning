#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;			
	double grade[]  =	{ 88,   93,   83,   60,   85,    85};	//�γ̳ɼ�
	double credit[] =	{ 2.5,  0.5,   3,   3,    4,    5.5};	//�ÿγ�ѧ��
	double GPA = 0;					//ѧ�ּ�
	double currGPA = 0;				//��ǰ��Ŀ��ѧ�ּ�
	double creditSum = 0;			//ѧ��֮��
	//��ѧ��֮��
	for (i = 0; i < sizeof(grade)/sizeof(grade[0]); i++)
	{
		creditSum += credit[i];
	}
	//����GPA
	for (i = 0; i < sizeof(grade) / sizeof(grade[0]); i++)
	{
		currGPA=credit[i] * grade[i]/ creditSum;
		GPA += currGPA;
	}
	printf("����ѧ�ּ�Ϊ��%lf\n\n", GPA);
	system("pause");
	return 0;
}