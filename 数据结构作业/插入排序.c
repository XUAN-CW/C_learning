#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>/*�õ���time����������Ҫ�����ͷ�ļ�*/

#define HIGHT 1
#define LOW 0
#define N  2000

//�򵥲�������
typedef struct {
	int key;
	float info;
}E;

//�򵥲�������
void SimpleInsertSort(E r[], int n, int x)
{
	int i, j;
	switch (x)
	{
	case HIGHT:
		//��С����
		for (i = 2; i <= n; i++)//���Ʋ��������Ԫ��
		{
			r[0] = r[i];
			j = i - 1;

			while (r[0].key < r[j].key)//����λ
			{
				r[j + 1] = r[j];//����
				j--;
			}
			r[j + 1] = r[0];
		}
		break;

	case LOW:
		//�Ӵ�С
		for (i = 2; i <= n; i++)//���Ʋ��������Ԫ��
		{
			r[0] = r[i];
			j = i - 1;

			while (r[0].key > r[j].key)//����λ
			{
				r[j + 1] = r[j];//����
				j--;
			}
			r[j + 1] = r[0];
		}
		break;

	default:
		break;
	}
	//PrintfArray(n, r);
}


//���
void  PrintfArray(int n, E r[])
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n");

}
//������������������
void  CreateRandomArray(int n, E r[])
{
	//printf("�����������\n");
	int i;
	srand((unsigned)time(NULL));/*������*/
	r[0].key = -1;
	for (i = 1; i < n; i++)
	{
		r[i].key = (rand() % 1000);//���������������ֵ���ַ����� 
		//printf("%d ", r[i].key);//����ַ����� 
	}
	printf("\n");
}


int main()
{

	E r[N + 1];

	CreateRandomArray(N + 1, r);//N+1Ϊ����������ĳ��� ����0 λ�ô��-1��
	clock_t start, finish;
	//����1
	start = clock();
	SimpleInsertSort(r, N, HIGHT);
	finish = clock();
	printf("��ֱ�Ӳ������� :%d ms \n", finish - start);

	CreateRandomArray(N + 1, r);
	start = clock();
	SimpleInsertSort(r, N, LOW);
	finish = clock();
	printf("��ֱ�Ӳ������� :%d ms \n", finish - start);


	return 0;
}













