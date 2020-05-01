#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>/*用到了time函数，所以要有这个头文件*/

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

//输出
void  PrintfArray(int n, E r[])
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n");

}

//快速排序
void Quicksort(E r[], int low, int hight, int x)
{

	int i, key;
	E t;

	if (hight <= low)//结束递归
		return;
	//寻找枢纽
	if (low < hight)
	{
		i = low;
		key = hight;
		t = r[i];

		switch (x)
		{
		case HIGHT://从小到大 
			while (i != key)
			{
				while ((i < key) && (r[key].key >= t.key))	//向左扫描比枢纽小的值
					key--;
				//大于枢纽		
				if (i < key) //当不满足时，与枢纽交换
				{
					r[i] = r[key];
					i++;
				}

				while ((i < key) && (r[i].key <= t.key))	//向右扫描比枢纽大的值
					i++;
				//小于枢纽
				if (i < key)	//不满足与枢纽交换
				{
					r[key] = r[i];
					key--;
				}
			}
			break;

		case LOW://从大到小 
			while (i != key)
			{
				while ((i < key) && (r[key].key <= t.key))	//向左扫描比枢纽小的值
					key--;
				//大于枢纽		
				if (i < key) //当不满足时，与枢纽交换
				{
					r[i] = r[key];
					i++;
				}

				while ((i < key) && (r[i].key >= t.key))	//向右扫描比枢纽大的值
					i++;
				//小于枢纽
				if (i < key)	//不满足与枢纽交换
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


//创建随机待排序的数组
void  CreateRandomArray(int n, E r[])
{
	printf("产生随机数列\n");
	int i;
	srand((unsigned)time(NULL));/*播种子*/
	r[0].key = -1;
	for (i = 1; i < n; i++)
	{
		r[i].key = (rand() % 1000);//产生随机整数并赋值给字符数组 
		//printf("%d ", r[i].key);//输出字符数组 
	}
	printf("\n");
}

//归并排序 
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

//选择 
void Selectsort(E r[], int n, int x)
{
	int i, j, k;
	switch (x)
	{
	case HIGHT:
		for (i = 1; i <= n; i++)
		{
			k = i;
			//寻找最小元素
			for (j = i + 1; j <= n; j++)
				if (r[k].key > r[j].key)
					k = j;
			//做交换
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
			//寻找最小元素
			for (j = i + 1; j <= n; j++)
				if (r[k].key < r[j].key)
					k = j;
			//做交换
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

//冒泡 
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
	CreateRandomArray(N + 1, r);//N+1为创建的数组的长度 其中0 位置存放-1；
	clock_t start, finish;
	//测试1
	start = clock();
	Quicksort(r, 1, N, HIGHT);
	finish = clock();
	printf("快速排序升序 :%d ms \n", finish - start);
	//PrintfArray(N, r);

	start = clock();
	Quicksort(r, 1, N, LOW);
	finish = clock();
	printf("快速排序降序:%d ms \n", finish - start);
	//PrintfArray(N, r);
	printf("\n\n");
	//测试2
	CreateRandomArray(N + 1, r);
	start = clock();
	MergeSort(r, t, N, HIGHT);
	finish = clock();
	printf("归并排序降序 :%f ms \n", finish - start);
	//PrintfArray(N, r);

	start = clock();
	MergeSort(r, t, N, LOW);
	finish = clock();
	printf("归并排序降序 :%f ms \n", finish - start);
	//PrintfArray(N, r);

	CreateRandomArray(N + 1, r);//N+1为创建的数组的长度 其中0 位置存放-1
	//测试1
	start = clock();
	Selectsort(r, N, HIGHT);
	Selectsort(r, N, LOW);
	finish = clock();
	printf("选择排序 :%d ms \n", finish - start);

	CreateRandomArray(N + 1, r);
	//测试2
	start = clock();
	BubbleSort(r, N, HIGHT);
	BubbleSort(r, N, LOW);
	finish = clock();
	printf("冒泡排序 :%d ms \n", finish - start);

	return 0;
}
