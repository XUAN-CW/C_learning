#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>/*用到了time函数，所以要有这个头文件*/

#define HIGHT 1
#define LOW 0
#define N  2000

//简单插入排序
typedef struct {
	int key;
	float info;
}E;

//简单插入排序
void SimpleInsertSort(E r[], int n, int x)
{
	int i, j;
	switch (x)
	{
	case HIGHT:
		//从小到大
		for (i = 2; i <= n; i++)//控制插入的数组元素
		{
			r[0] = r[i];
			j = i - 1;

			while (r[0].key < r[j].key)//负责定位
			{
				r[j + 1] = r[j];//后移
				j--;
			}
			r[j + 1] = r[0];
		}
		break;

	case LOW:
		//从大到小
		for (i = 2; i <= n; i++)//控制插入的数组元素
		{
			r[0] = r[i];
			j = i - 1;

			while (r[0].key > r[j].key)//负责定位
			{
				r[j + 1] = r[j];//后移
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
//创建随机待排序的数组
void  CreateRandomArray(int n, E r[])
{
	//printf("产生随机数列\n");
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


int main()
{

	E r[N + 1];

	CreateRandomArray(N + 1, r);//N+1为创建的数组的长度 其中0 位置存放-1；
	clock_t start, finish;
	//测试1
	start = clock();
	SimpleInsertSort(r, N, HIGHT);
	finish = clock();
	printf("简单直接插入排序 :%d ms \n", finish - start);

	CreateRandomArray(N + 1, r);
	start = clock();
	SimpleInsertSort(r, N, LOW);
	finish = clock();
	printf("简单直接插入排序 :%d ms \n", finish - start);


	return 0;
}













