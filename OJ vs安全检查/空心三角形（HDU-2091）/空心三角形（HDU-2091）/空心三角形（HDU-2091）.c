#include <stdio.h>
#include <stdlib.h>

void DrawHollowTriangle(char ch, int n);

int main()
{
	/*** 确定数据类型、结构 **/
	char ch;
	int n;
	/*** 数据采集与处理 **/
	int theAmountOfTriangle = 0;
	char a;	//用来跳过空格和回车
	for (; ; theAmountOfTriangle++)
	{
		scanf_s("%c", &ch, sizeof(ch));
		scanf_s("%c", &a, 1);
		if ('@' == ch)
		{
			break;
		}
		scanf_s("%d", &n);
		scanf_s("%c", &a, 1);
		if (0 != theAmountOfTriangle)
		{
			printf("\n");
		}

		/*** 要输入一个，输出一个，而不是全部输入后输出 **/
		DrawHollowTriangle(ch, n);
		printf("\n");
	}

	return 0;
}


void DrawHollowTriangle(char ch, int n)
{
	/*** 2 ~ n-1 行 **/
	for (int row = 0; row < n - 1; row++)
	{
		for (int i = 0; i < n + row; i++)
		{
			if (i + row + 1 == n || i - row + 1 == n)
			{
				printf("%c", ch);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	/*** 打印最后一行 **/
	for (int i = 0; i < 2 * n - 1; i++)
	{
		printf("%c", ch);
	}
}












//#include <stdio.h>
//#include <stdlib.h>
//
//void DrawHollowTriangle(char ch, int n);
//
//int main()
//{
//	/*** 确定数据类型、结构 **/
//	//最多 41 个三角形，triangles[i][0] — 第 i 个三角形的字符，triangles[i][1] — 第 i 个三角形的高
//	char triangles[100][3] = { 0 };
//
//	/*** 数据采集与处理 **/
//	int theAmountOfTriangle = 0;
//	char a;	//用来跳过空格和回车
//	for (; ; theAmountOfTriangle++)
//	{
//		scanf_s("%c", &triangles[theAmountOfTriangle][0],sizeof(triangles[theAmountOfTriangle][0]));
//		scanf_s("%c", &a,1);
//		if ('@'==triangles[theAmountOfTriangle][0])
//		{
//			break;
//		}
//		scanf_s("%c", &triangles[theAmountOfTriangle][1], sizeof(triangles[theAmountOfTriangle][1]));
//		scanf_s("%c", &a, 1);
//		if (0 != theAmountOfTriangle)
//		{
//			printf("\n");
//		}
//
//
//		/*** 要输入一个，输出一个，而不是全部输入后输出 **/
//		DrawHollowTriangle(triangles[theAmountOfTriangle][0], (int)triangles[theAmountOfTriangle][1] - '0');
//		printf("\n");
//	}
//
//	
//	//theAmountOfTriangle = 1;
//	//for ( int i = 0; i < theAmountOfTriangle; i++)
//	//{
//	//	DrawHollowTriangle(triangles[i][0], (int)triangles[i][1] - '0');
//	//	printf("\n\n");
//	//	//DrawHollowTriangle('2', 41);
//	//	//printf("%c %c", triangles[i][0], triangles[i][1]);
//	//}
//
//	return 0;
//}
//
//
//void DrawHollowTriangle(char ch, int n)
//{
//		/*** 2 ~ n-1 行 **/
//		for (int row = 0; row < n - 1; row++)
//		{
//			for (int i = 0; i < n + row; i++)
//			{
//				if (i + row + 1 == n || i - row + 1 == n)
//				{
//					printf("%c", ch);
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//
//		/*** 打印最后一行 **/
//		for (int i = 0; i < 2 * n - 1; i++)
//		{
//			printf("%c", ch);
//		}
//}


//#include <stdio.h>
//#include <string.h>
//int main() {
//	char a;
//	int b, i, j, k = 0;
//	while ((a = getchar()) != '@')//可换为：while(scanf("%c",&a)&&a!='@')
//	{
//		++k;
//		getchar();//这一句的作用是读取空格！ 
//		scanf_s("%d", &b);
//		getchar();//记住这一句不能省，否则会在第二次输入时a直接变成\n（换行符）！ 
//		if (k != 1)//这个格式很重要，这是在第一个结果的后面先不输出空行，
//			printf("\n");//只有在判断过第二个结果满足条件后，才输出空行，
//					  //此空行依然在第二个结果之前，满足两个空三角形之间有空行的条件！  
//		for (i = 1; i < b; i++)
//		{
//			for (j = 1; j <= b + (i - 1); j++)
//			{
//				if (j == b - (i - 1) || j == b + (i - 1))
//					printf("%c", a);
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//		for (i = 0; i < 2 * b - 1; i++)
//			printf("%c", a);
//		printf("\n");
//	}
//	return 0;
//}