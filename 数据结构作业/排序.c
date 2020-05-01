#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>/*�õ���time����������Ҫ�����ͷ�ļ�*/

#define HIGHT 1
#define LOW 0
#define N  1000

typedef struct {
	int key;
	char otherInformatization[200];
}E;

typedef struct
{
	int n;
	E* record;
}SortObject;

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

//��������
void Quicksort(E r[], int low, int hight, int x)
{

	int i, key;
	E t;

	if (hight <= low)//�����ݹ�
		return;
	//Ѱ����Ŧ
	if (low < hight)
	{
		i = low;
		key = hight;
		t = r[i];

		switch (x)
		{
		case HIGHT://��С���� 
			while (i != key)
			{
				while ((i < key) && (r[key].key >= t.key))	//����ɨ�����ŦС��ֵ
					key--;
				//������Ŧ		
				if (i < key) //��������ʱ������Ŧ����
				{
					r[i] = r[key];
					i++;
				}

				while ((i < key) && (r[i].key <= t.key))	//����ɨ�����Ŧ���ֵ
					i++;
				//С����Ŧ
				if (i < key)	//����������Ŧ����
				{
					r[key] = r[i];
					key--;
				}
			}
			break;

		case LOW://�Ӵ�С 
			while (i != key)
			{
				while ((i < key) && (r[key].key <= t.key))	//����ɨ�����ŦС��ֵ
					key--;
				//������Ŧ		
				if (i < key) //��������ʱ������Ŧ����
				{
					r[i] = r[key];
					i++;
				}

				while ((i < key) && (r[i].key >= t.key))	//����ɨ�����Ŧ���ֵ
					i++;
				//С����Ŧ
				if (i < key)	//����������Ŧ����
				{
					r[key] = r[i];
					key--;
				}
			}
			break;
		}
	}

	r[i] = t;
	Quicksort(r, low, key - 1, x);
	Quicksort(r, key + 1, hight, x);
}


//������������������
void  CreateRandomArray(int n, E r[])
{
	printf("�����������\n");
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

//�鲢���� 
void mergeh(E r[], E t[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	mergeh(r, t, start1, end1);
	mergeh(r, t, start2, end2);
	int temp = start;
	while (start1 <= end1 && start2 <= end2)
		t[temp++] = r[start1].key < r[start2].key ? r[start1++] : r[start2++];
	while (start1 <= end1)
		t[temp++] = r[start1++];
	while (start2 <= end2)
		t[temp++] = r[start2++];
	for (temp = start; temp <= end; temp++)
		r[temp] = t[temp];
}
void mergel(E r[], E t[], int start, int end) {
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	mergel(r, t, start1, end1);
	mergel(r, t, start2, end2);
	int temp = start;
	while (start1 <= end1 && start2 <= end2)
		t[temp++] = r[start1].key > r[start2].key ? r[start1++] : r[start2++];
	while (start1 <= end1)
		t[temp++] = r[start1++];
	while (start2 <= end2)
		t[temp++] = r[start2++];
	for (temp = start; temp <= end; temp++)
		r[temp] = t[temp];
}
void MergeSort(E r[], E t[], int len, int x)
{
	switch (x)
	{
	case HIGHT:
		mergeh(r, t, 1, len);
		break;
	case LOW:
		mergel(r, t, 1, len);
		break;
	}

}

//ѡ�� 
void Selectsort(E r[], int n, int x)
{
	int i, j, k;
	switch (x)
	{
	case HIGHT:
		for (i = 1; i <= n; i++)
		{
			k = i;
			//Ѱ����СԪ��
			for (j = i + 1; j <= n; j++)
				if (r[k].key > r[j].key)
					k = j;
			//������
			if (i != k)
			{
				r[0] = r[k];
				r[k] = r[i];
				r[i] = r[0];
			}

		}
		//PrintfArray(n, r);
		break;

	case LOW:
		for (i = 1; i <= n; i++)
		{
			k = i;
			//Ѱ����СԪ��
			for (j = i + 1; j <= n; j++)
				if (r[k].key < r[j].key)
					k = j;
			//������
			if (i != k)
			{
				r[0] = r[k];
				r[k] = r[i];
				r[i] = r[0];
			}

		}
		//PrintfArray(n, r);
		break;
	}

}

//ð�� 
void BubbleSort(E r[], int n, int x)
{
	int i, j, k;
	switch (x)
	{
	case HIGHT:
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n - i; j++)
			{
				if (r[j].key > r[j + 1].key)
				{
					r[0] = r[j];
					r[j] = r[j + 1];
					r[j + 1] = r[0];
				}
			}

		}
		//PrintfArray(n, r);
		break;
	case LOW:
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n - i; j++)
			{
				if (r[j].key < r[j + 1].key)
				{
					r[0] = r[j];
					r[j] = r[j + 1];
					r[j + 1] = r[0];
				}
			}

		}
		//PrintfArray(n, r);
		break;


	}


}


int main()
{

	E r[N + 1];
	E t[N + 1];
	CreateRandomArray(N + 1, r);//N+1Ϊ����������ĳ��� ����0 λ�ô��-1��
	clock_t start, finish;
	//����1
	start = clock();
	Quicksort(r, 1, N, HIGHT);
	finish = clock();
	printf("������������ :%d ms \n", finish - start);
	//PrintfArray(N, r);

	start = clock();
	Quicksort(r, 1, N, LOW);
	finish = clock();
	printf("����������:%d ms \n", finish - start);
	//PrintfArray(N, r);
	printf("\n\n");
	//����2
	CreateRandomArray(N + 1, r);
	start = clock();
	MergeSort(r, t, N, HIGHT);
	finish = clock();
	printf("�鲢������ :%f ms \n", finish - start);
	//PrintfArray(N, r);

	start = clock();
	MergeSort(r, t, N, LOW);
	finish = clock();
	printf("�鲢������ :%f ms \n", finish - start);
	//PrintfArray(N, r);

	CreateRandomArray(N + 1, r);//N+1Ϊ����������ĳ��� ����0 λ�ô��-1
	//����1
	start = clock();
	Selectsort(r, N, HIGHT);
	Selectsort(r, N, LOW);
	finish = clock();
	printf("ѡ������ :%d ms \n", finish - start);

	CreateRandomArray(N + 1, r);
	//����2
	start = clock();
	BubbleSort(r, N, HIGHT);
	BubbleSort(r, N, LOW);
	finish = clock();
	printf("ð������ :%d ms \n", finish - start);

	return 0;
}
