#pragma once

#define TURE 1
#define FALSE 0
#define GROUP_MAX 3				//�������
#define ESSAY_CHAR_MAX 100		//��������ַ���
#define ESSAY_WORDS_MAX 20		//������󵥴���
#define WORD_CHAR_MAX 20		//��������ַ���

/** �������ĸ,����TURE,���Ǿͷ���FALSE */
int IsLetter(char character);

/** ������û���ظ��ĵ��� */
void duplicateCheck(char words[GROUP_MAX][ESSAY_WORDS_MAX][WORD_CHAR_MAX], int currentGroup, int *currentWord);