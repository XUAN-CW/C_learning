#include <stdio.h>
#include <stdlib.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2081

/*** 解法一：指针指向第六位 **/
int main()
{
	int N;
	/*** 输入号码数目 **/
	scanf_s("%d", &N);

	char phoneNumbers[200][15];
	/*** 输入号码信息 **/
	for (int i = 0; i < N; i++)
	{
		scanf_s("%s", &phoneNumbers[i], sizeof(phoneNumbers[i]));
		phoneNumbers[i][5] = '6';
	}
	char* p;
	for (int i = 0; i < N; i++)
	{
		p = &phoneNumbers[i][5];
		printf("%s\n", p);
	}

	return 0;
}

/*** 解法二：数组第一个位置直接置为6，第七位到第十二位移动到第二到第七位 **/
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int N;
//	/*** 输入号码数目 **/
//	scanf_s("%d", &N);
//
//	char phoneNumbers[200][15];
//	/*** 输入号码信息 **/
//	for (int i = 0; i < N; i++)
//	{
//		scanf_s("%s", &phoneNumbers[i], sizeof(phoneNumbers[i]));
//
//		phoneNumbers[i][0] = '6';
//		for (int j = 6, k = 1; k < 7; j++, k++)
//		{
//			phoneNumbers[i][k] = phoneNumbers[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		printf("%s\n", phoneNumbers[i]);
//	}
//
//	return 0;
//}