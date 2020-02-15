#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

unsigned long long C(SHORT A, SHORT a);

int main()
{
	int n, m, Bx, By;
	/** 获取目的地以及马的坐标 */
	scanf_s("%d%d%d%d", &n, &m, &Bx, &By);
	/**	确定控制点，小心越界 */
	COORD controlPoint[9] =
	{ {Bx,By},
	{Bx + 2,By + 1},{Bx + 2,By - 1},{Bx - 2,By + 1},{Bx - 2,By - 1},
	{Bx + 1,By + 2},{Bx + 1,By - 2},{Bx - 1,By + 2},{Bx - 1,By - 2}, };
	/** 无视控制点，求出A点到B点的所有路径 A—>B */
	unsigned long long AB = C( n, m + n);
	/** 确定有关控制点，求出所有A点到有关控制点、有关控制点到B点的路径 A—>C—>B */
	unsigned long long allOfACB = 0;
	for (int i = 0; i < sizeof(controlPoint) / sizeof(COORD); i++)
	{
		if ((controlPoint[i].X >= 0 && controlPoint[i].Y >= 0) && (controlPoint[i].X <= n && controlPoint[i].X <= m))
		{
			allOfACB += C(controlPoint[i].X, controlPoint[i].X + controlPoint[i].Y) *
				C(Bx - controlPoint[i].X, (Bx - controlPoint[i].X) + (By - controlPoint[i].Y));
		}
	}
	/** 目标路径总数 == A—>B - A—>C—>B */
	printf("%lld", AB - allOfACB);

	return 0;
}

unsigned long long C(SHORT A, SHORT a)
{
	unsigned long long result = 1;
	a = min(a, A - a);	
	if (a == 0)
	{
		return 1;
	}
	for (int i = A, j = 1; i >= A - a + 1; i--, j++)
	{
		result = result * i;
		result = result / j;
	}
	return result;
}



/* https://www.luogu.org/problemnew/show/P1002 */

/* 
题目描述

棋盘上AAA点有一个过河卒，需要走到目标BBB点。
卒行走的规则：可以向下、或者向右。
同时在棋盘上CCC点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，AAA点(0,0)(0, 0)(0,0)、BBB点(n,m)(n, m)(n,m)(nnn, mmm为不超过202020的整数)，同样马的位置坐标是需要给出的。

现在要求你计算出卒从AAA点能够到达BBB点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。
输入输出格式
输入格式：

一行四个数据，分别表示BBB点坐标和马的坐标。

输出格式：

一个数据，表示所有的路径条数。

输入输出样例
输入样例#1： 复制

6 6 3 3

输出样例#1： 复制

6

说明

结果可能很大！
 */