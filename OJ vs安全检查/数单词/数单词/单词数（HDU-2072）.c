#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char ch = 0;
	while (1)
	{
		/*** ��Ϣ�ɼ� **/
		char paragraph[10000] = { 0 };
		gets(paragraph);

		if ('#' == paragraph[0])
		{
			return 0;
		}


		/*** ��ʼ������������ **/
		char words[1000][100] = { 0 };
		int currentWordNum = 0;
		int i = 0;

		/*** ���������ݷָ�Ƚ� **/
		for (i = 0; '\0' != paragraph[i]; i++)
		{
			/*** �ָ���һ�����ʣ�currentWord  **/
			char currentWord[50] = { 0 };
			if ('a' <= paragraph[i] && paragraph[i] <= 'z')
			{
				for (int j = 0; 'a' <= paragraph[i] && paragraph[i] <= 'z'; i++, j++)
				{
					currentWord[j] = paragraph[i];
				}
			}

			/***  ���� **/
			int check = 0;
			for (; check < currentWordNum; check++)
			{
				if (0 == strcmp(currentWord, words[check]))
				{
					check = -1;                        ////��һëһ���ĵ���
					break;
				}
			}
			if (0 != currentWord[0])
			{
				if (check == currentWordNum)        //û��һëһ���ĵ���
				{
					strcpy(words[currentWordNum], currentWord);
					currentWordNum++;
				}
			}

		}

		/*** ������ **/
		printf("%d\n", currentWordNum);

	}
}

//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char a[10000], b[1000][100];
//	int i, j, m, n, l, sum, p, q;
//	while (cin.getline(a, 10000) && a[0] != '#')
//	{
//
//
//		sum = 0;
//		i = j = m = 0;
//		while (a[i] != '\0')
//		{
//			if (a[i] != ' ')
//			{
//				for (j = i, n = 0; a[j] != '\0' && a[j] != ' '; j++, n++)
//					b[m][n] = a[j];
//				b[m][n] = '\0';
//
//				m++;
//				i = j;
//
//			}
//			else
//				i++;
//
//		}
//
//		for (p = 1; p <= m; p++)
//		{
//			q = 1;
//			for (l = 0; l < p; l++)
//
//				if (strcmp(b[p], b[l]) == 0)
//				{
//					q = 0; break;
//				}
//			if (q == 1)
//				sum++;
//		}
//		cout << sum << endl;
//
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//int main()
//{
//	char ch = 0;
//	while (1)
//	{
//		/*** ��ʼ������������ **/
//		char words[100][50] = { 0 };
//		char temp[50] = { 0 };
//		int currentWordNum = 0;
//		int i = 0;
//
//		while (1)
//		{
//			ch = getchar();
//			
//			if ('a' <= ch && 'z' >= ch)		//����ĸ
//			{
//				temp[i++] = ch;
//			}
//			else							//������ĸ
//			{
//				temp[i] = '\0';				//ʹ temp ��Ϊ�ַ���
//				i = 0;						
//				/*** �Ƚ��뱣�� **/
//				int j = 0;
//				for ( ; j < currentWordNum; j++)
//				{
//					if (0 == strcmp(temp,words[j]))
//					{
//						break;
//					}
//				}
//
//				if ('\0' != temp[0])
//				{
//					if (j < currentWordNum)		//�����һëһ����
//					{
//						continue;
//					}
//					else						//���û��һëһ����
//					{
//						strcpy_s(words[currentWordNum], temp);
//						currentWordNum++;
//					}
//				}
//			
//				//�������ݽ���
//				if ('\n' == ch)
//				{
//					printf("%d\n", currentWordNum);
//					break;				//����ѭ����������		
//				}
//				//�������
//				if ('#' == ch)
//				{
//					return 0;
//				}
//			}
//		}
//	}
//}




