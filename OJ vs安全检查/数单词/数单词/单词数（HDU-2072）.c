#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char ch = 0;
	while (1)
	{
		/*** 信息采集 **/
		char paragraph[10000] = { 0 };
		gets(paragraph);

		if ('#' == paragraph[0])
		{
			return 0;
		}


		/*** 初始化或重置数据 **/
		char words[1000][100] = { 0 };
		int currentWordNum = 0;
		int i = 0;

		/*** 将本组数据分割、比较 **/
		for (i = 0; '\0' != paragraph[i]; i++)
		{
			/*** 分割获得一个单词：currentWord  **/
			char currentWord[50] = { 0 };
			if ('a' <= paragraph[i] && paragraph[i] <= 'z')
			{
				for (int j = 0; 'a' <= paragraph[i] && paragraph[i] <= 'z'; i++, j++)
				{
					currentWord[j] = paragraph[i];
				}
			}

			/***  查重 **/
			int check = 0;
			for (; check < currentWordNum; check++)
			{
				if (0 == strcmp(currentWord, words[check]))
				{
					check = -1;                        ////有一毛一样的单词
					break;
				}
			}
			if (0 != currentWord[0])
			{
				if (check == currentWordNum)        //没有一毛一样的单词
				{
					strcpy(words[currentWordNum], currentWord);
					currentWordNum++;
				}
			}

		}

		/*** 输出结果 **/
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
//		/*** 初始化或重置数据 **/
//		char words[100][50] = { 0 };
//		char temp[50] = { 0 };
//		int currentWordNum = 0;
//		int i = 0;
//
//		while (1)
//		{
//			ch = getchar();
//			
//			if ('a' <= ch && 'z' >= ch)		//是字母
//			{
//				temp[i++] = ch;
//			}
//			else							//不是字母
//			{
//				temp[i] = '\0';				//使 temp 成为字符串
//				i = 0;						
//				/*** 比较与保存 **/
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
//					if (j < currentWordNum)		//如果有一毛一样的
//					{
//						continue;
//					}
//					else						//如果没有一毛一样的
//					{
//						strcpy_s(words[currentWordNum], temp);
//						currentWordNum++;
//					}
//				}
//			
//				//本组数据结束
//				if ('\n' == ch)
//				{
//					printf("%d\n", currentWordNum);
//					break;				//跳出循环重置数据		
//				}
//				//输入结束
//				if ('#' == ch)
//				{
//					return 0;
//				}
//			}
//		}
//	}
//}




