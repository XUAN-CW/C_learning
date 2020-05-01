#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "assistFunction.h"


int main()
{
	char essay[ESSAY_CHAR_MAX] = { '\0' };
	int groups = 0;

	//数据输入
	for (int i = 0; i< ESSAY_CHAR_MAX; i++)		
	{
		essay[i] = _getch();
		printf("%c", essay[i]);				//观察输入了什么,没有这条也可以
		if (essay[i]=='#')					//计算组数
		{
			groups++;
		}
		if ('\r' == essay[i])				//回车结束输入
		{
			essay[i] = '\0';
			break;
		}
	}


	//数据处理
	char words[GROUP_MAX][ESSAY_WORDS_MAX][WORD_CHAR_MAX] = { '\0' };
	int currentGroup = 0;
	int currentWord = 0;
	int currentChar = 0;
	for (int i = 0; essay[i] != '\0'; i++)
	{
		if (IsLetter(essay[i]))
		{
			words[currentGroup][currentWord][currentChar] = essay[i];
			currentChar++;	
		}
		else if (essay[i]==' ')
		{
			currentChar = 0;
			duplicateCheck(words, currentGroup, &currentWord);
			currentWord++;
		}
		else if (essay[i]=='#')
		{
			printf("\n第%d组单词数:%d\n", currentGroup + 1, currentWord+1);
			currentChar = 0;
			currentWord = 0;
			currentGroup++;
			
		}
	}


	system("pause");
    return 0;
}
