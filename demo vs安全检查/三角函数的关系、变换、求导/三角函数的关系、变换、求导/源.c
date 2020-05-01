#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int main()
{
	int choice;			//选择需要的功能
	int triangle;		//出现的三角函数
	const char * answer;		//对问题的回答
	const char * rightAnswer;	//正确答案
	/* 打印菜单 */
	printf("1、三角函数中的倒数关系");
	/* 选择功能 */
	choice = getch();
	/* 功能实现 */
	switch (choice)
	{
	case 1:
		do
		{
			srand(time(NULL));
			triangle = rand() % 5;
			switch (triangle)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
			}
			printf("的倒数是: ");
			scanf_s("%c", &answer);
			/*判断回答是否正确*/
			if (strcmp(answer, rightAnswer) == 0)	//回答正确
			{
				printf("回答正确！");
			}
			else									//回答错误
			{
				printf("的倒数是%s", rightAnswer);
			}
		} while (1);
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
	return 0;
}