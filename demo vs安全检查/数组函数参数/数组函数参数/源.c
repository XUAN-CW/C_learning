#include <stdio.h>
#include <stdlib.h>
#define N 5
//��дһ��С�͵�ѧ���ɼ�����ϵͳ
//¼�뺯��
void input(double[]);
void sort(double[]);
void show(double[]);
//����������в���num��������ڣ������±꣬�����ڣ�����-1
int find(double *, int);

int main()
{
	//������Ĵ�С
	double test[] = { 1, 2, 3, 4 , 5, 6, 4 };
	printf("test�����Ԫ�ظ�����%d\n", sizeof(test) / sizeof(test[0]));


	double scores[N];
	double findNum; //Ҫ���ҵ�����
	//1��¼��
	input(scores);
	printf("����ǰ��\n");
	show(scores);
	//2������
	sort(scores);
	//3������ĳ�ָ�ʽ��ӡ
	printf("�����\n");
	show(scores);

	printf("������Ҫ���ҵ����֣�");
	scanf_s("%lf", &findNum);
	printf("�ҵ��������±�Ϊ��%d\n", find(scores, findNum));
	system("pause");
	return 0;
}

int find(double * scores, int findNum)
{
	int findIndex = -1;//Ҫ���ҵ��±�
	int i;
	for (i = 0; i < N; i++)
	{
		//if(findNum == *(scores + i))
		if (findNum == scores[i])
		{
			//��¼��Ҫ���ҵ��±꣬�������Ҷ���
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
		printf("�������%d�ſεĳɼ���", i + 1);
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
	printf("����\t��ѧ\tӢ��\t����\t��ѧ\n");
	for (i = 0; i < N; i++)
	{
		printf("%.2lf\t", *(scores + i));
	}
	printf("\n***********************************************\n");
}


