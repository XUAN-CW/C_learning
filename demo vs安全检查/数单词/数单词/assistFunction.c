#include "assistFunction.h"
#include <string.h>

int IsLetter(char character)
{
	if ((character > 'A'&&character<'Z')||(character>'a'&&character < 'z'))
	{
		return TURE;
	}
	return FALSE;
}

void duplicateCheck(char words[GROUP_MAX][ESSAY_WORDS_MAX][WORD_CHAR_MAX], int currentGroup, int *currentWord)
{
	for (int i = 0; i < *(currentWord); i++)
	{
		int equal=strcmp(words[currentGroup][*(currentWord)], words[currentGroup][*(currentWord)]);
		if (equal == 0)		//��������һģһ��
		{
			//����ǰ����ɾ��,currentWordָ����һ������
			for (int currentChar = 0; words[currentGroup][*(currentWord)][currentChar] != '\0'; currentChar++)
			{
				words[currentGroup][*(currentWord)][currentChar] = '\0';
			}
			*(currentWord)--;
		}
	}
}