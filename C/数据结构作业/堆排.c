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
}JD;

//输出
void  PrintfArray(int n, JD r[])
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", r[i].key);
	}
	printf("\n");

}
//创建随机待排序的数组
void  CreateRandomArray(int n, JD r[])
{
	//	printf("产生随机数列\n");
	int i;
	srand((unsigned)time(NULL));
	//	r[0].key = -1;
	for (i = 0; i < n; i++)
	{
		r[i].key = (rand() % 1000);//产生随机整数并赋值给字符数组 
	//	printf("%d ", r[i].key);//输出字符数组 
	}
	printf("\n");
}

void Exchange(JD a[], int i, int n)//将最大叶子结点与根结点交换 
{
	int temp;
	temp = a[i].key;
	a[i] = a[n];
	a[n].key = temp;
}

void Heapsorth(JD a[], int n)
{
	if (n == 2)
	{//当只剩两个的时候，直接比较大小 先输出最大的 然后输出最小的 
		if (a[0].key > a[1].key)
		{
			printf("%d %d\n", a[0].key, a[1].key);
		}
		else
			printf("%d %d\n", a[1].key, a[0].key);
		return;
	}
	int i;

	for (i = n / 2 - 1; i >= 0; i--) //比较每一个根结点与其叶子结点的大小   并且将大于根结点的叶子结点与根结点交换 
	{
		//最后一个根结点是第n/2个 但是第一个数下标为0  所以最后一个根结点下标为n/2-1 
		if (a[2 * i + 1].key < a[i].key && 2 * i + 1 < n)	//与左孩子进行比较 
			Exchange(a, i, 2 * i + 1);
		if (a[2 * i + 2].key < a[i].key && 2 * i + 2 < n)	//与右孩子进行比较 
			Exchange(a, i, 2 * i + 2);
	}

	int t;
	t = a[0].key;//将第一个根结点与最后一个叶子结点互换 
	a[0] = a[n - 1];
	a[n - 1].key = t;

	printf("%d ", a[n - 1].key);//输出最大的结点 
	Heapsorth(a, n - 1);//将是输出的结点弹出 
}

void Heapsortl(JD a[], int n)
{
	if (n == 2)
	{//当只剩两个的时候，直接比较大小 先输出最大的 然后输出最小的 
		if (a[0].key > a[1].key)
		{
			printf("%d %d\n", a[0].key, a[1].key);
		}
		else
			printf("%d %d\n", a[1].key, a[0].key);
		return;
	}
	int i;

	for (i = n / 2 - 1; i >= 0; i--) //比较每一个根结点与其叶子结点的大小   并且将大于根结点的叶子结点与根结点交换 
	{
		//最后一个根结点是第n/2个 但是第一个数下标为0  所以最后一个根结点下标为n/2-1 
		if (a[2 * i + 1].key > a[i].key && 2 * i + 1 < n)	//与左孩子进行比较 
			Exchange(a, i, 2 * i + 1);
		if (a[2 * i + 2].key > a[i].key && 2 * i + 2 < n)	//与右孩子进行比较 
			Exchange(a, i, 2 * i + 2);
	}

	int t;
	t = a[0].key;//将第一个根结点与最后一个叶子结点互换 
	a[0] = a[n - 1];
	a[n - 1].key = t;

	printf("%d ", a[n - 1].key);//输出最大的结点 
	Heapsortl(a, n - 1);//将是输出的结点弹出 
}
int main()
{
	JD r[N];
	CreateRandomArray(N, r);//N为创建的数组的长度；
	PrintfArray(N, r);
	printf("\n\n");
	
	clock_t start, finish;
	//测试1
	start = clock();
	Heapsorth(r, N);
	finish = clock();
	printf("堆排序升序 :%d ms \n", finish - start);
	
	CreateRandomArray(N, r);
	start = clock();
	Heapsortl(r, N);
	finish = clock();
	printf("堆排序降序 :%d ms \n", finish - start);
	return 0;
}