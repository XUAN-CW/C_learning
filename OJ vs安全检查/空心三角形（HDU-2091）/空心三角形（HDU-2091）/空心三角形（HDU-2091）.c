#include <stdio.h>
#include <stdlib.h>

void DrawHollowTriangle(char ch, int n);

int main()
{
	/*** ȷ���������͡��ṹ **/
	char ch;
	int n;
	/*** ���ݲɼ��봦�� **/
	int theAmountOfTriangle = 0;
	char a;	//���������ո�ͻس�
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

		/*** Ҫ����һ�������һ����������ȫ���������� **/
		DrawHollowTriangle(ch, n);
		printf("\n");
	}

	return 0;
}


void DrawHollowTriangle(char ch, int n)
{
	/*** 2 ~ n-1 �� **/
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

	/*** ��ӡ���һ�� **/
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
//	/*** ȷ���������͡��ṹ **/
//	//��� 41 �������Σ�triangles[i][0] �� �� i �������ε��ַ���triangles[i][1] �� �� i �������εĸ�
//	char triangles[100][3] = { 0 };
//
//	/*** ���ݲɼ��봦�� **/
//	int theAmountOfTriangle = 0;
//	char a;	//���������ո�ͻس�
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
//		/*** Ҫ����һ�������һ����������ȫ���������� **/
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
//		/*** 2 ~ n-1 �� **/
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
//		/*** ��ӡ���һ�� **/
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
//	while ((a = getchar()) != '@')//�ɻ�Ϊ��while(scanf("%c",&a)&&a!='@')
//	{
//		++k;
//		getchar();//��һ��������Ƕ�ȡ�ո� 
//		scanf_s("%d", &b);
//		getchar();//��ס��һ�䲻��ʡ��������ڵڶ�������ʱaֱ�ӱ��\n�����з����� 
//		if (k != 1)//�����ʽ����Ҫ�������ڵ�һ������ĺ����Ȳ�������У�
//			printf("\n");//ֻ�����жϹ��ڶ���������������󣬲�������У�
//					  //�˿�����Ȼ�ڵڶ������֮ǰ������������������֮���п��е�������  
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