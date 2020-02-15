#pragma once

#define TURE 1
#define FALSE 0
#define GROUP_MAX 3				//最大组数
#define ESSAY_CHAR_MAX 100		//文章最大字符数
#define ESSAY_WORDS_MAX 20		//文章最大单词数
#define WORD_CHAR_MAX 20		//单词最大字符数

/** 如果是字母,返回TURE,不是就返回FALSE */
int IsLetter(char character);

/** 查找有没有重复的单词 */
void duplicateCheck(char words[GROUP_MAX][ESSAY_WORDS_MAX][WORD_CHAR_MAX], int currentGroup, int *currentWord);