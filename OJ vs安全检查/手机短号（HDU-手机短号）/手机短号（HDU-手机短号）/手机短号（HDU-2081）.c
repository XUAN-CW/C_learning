#include <stdio.h>
#include <stdlib.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2081

/*** �ⷨһ��ָ��ָ�����λ **/
int main()
{
	int N;
	/*** ���������Ŀ **/
	scanf_s("%d", &N);

	char phoneNumbers[200][15];
	/*** ���������Ϣ **/
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

/*** �ⷨ���������һ��λ��ֱ����Ϊ6������λ����ʮ��λ�ƶ����ڶ�������λ **/
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int N;
//	/*** ���������Ŀ **/
//	scanf_s("%d", &N);
//
//	char phoneNumbers[200][15];
//	/*** ���������Ϣ **/
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