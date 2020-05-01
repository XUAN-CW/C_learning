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

/*** ������Ϣ�õ�ʱ��� **/
int GetTimeScoreFormInfoemation(char information[], int m);

/*** qsort() ��������  **/
int cmp(const void* a, const void* b);

int main()
{
	int n;	//��Ŀ��
	int m;	//��λ�ͷ���
	scanf_s("%d%d", &n, &m);

	//int n = 2;	//��Ŀ��
	//int m = 1;	//��λ�ͷ���

	char information[15] = { 0 };
	int timeScore;
	int currentACMer = 0;

	/*** ��Ϣ�ɼ��봦�� **/
	for (; EOF != scanf_s("%s", Acmer[currentACMer].name, sizeof(Acmer[currentACMer].name)); currentACMer++)
	{
		Acmer[currentACMer].AC = 0;
		Acmer[currentACMer].timeScore = 0;

		//ACM ��, �����������Ǵ����ļ�����ġ����Զ�����ʱ, �����ļ���Ϊ���, ʵ����������ļ�������
		//Ϊ�˷�����ԣ��ڴ�����һ��ѭ�����ڣ��ύʱ�ǵ�ע�͵�
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

	/*** qsort�༶���� **/
	qsort(Acmer, currentACMer, sizeof(acmer), cmp);

	/*** ��� **/
	for (int j = 0; j < currentACMer; j++)
	{
		printf("%-10s %2d %4d\n", Acmer[j].name, Acmer[j].AC, Acmer[j].timeScore);

		//printf("%2d %4d %-10s\n",Acmer[j].AC,  Acmer[j].timeScore ,Acmer[j].name);
	}

	return 0;

}

/*** ������Ϣ�õ�ʱ��� **/
int GetTimeScoreFormInfoemation(char information[], int m)
{
	/*** û���ԣ�ֱ����� **/
	if ('-' == information[0] || '0' == information[0])
	{
		return 0;
	}

	/*** �����ˣ�ͳ��ʱ��� **/
	int WA = 0;
	int timeSpent = 0;		//ʵ�ʻ��ѵ�ʱ��
	int punishTimes = 0;	//���ִ���
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

/*** qsort() ��������  **/
int cmp(const void* a, const void* b)
{
	/*** ת������Ҫ������ **/
	acmer* A = (acmer*)a;
	acmer* B = (acmer*)b;

	/*** ��������ʽ **/
	if (A->AC != B->AC)
	{
		// A->xxx - B->xxx ������
		// B->xxx - A->xxx ������
		return B->AC - A->AC;
	}
	else if (A->timeScore != B->timeScore)
	{
		return A->timeScore - B->timeScore;
	}
	return strcmp(A->name, B->name);
}

