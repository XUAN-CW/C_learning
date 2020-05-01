#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int main()
{
	int question;
	int choice;					//选择需要的功能
	char answer[20];			//对问题的回答
	char trigonometric[6][5] = { "sinx","cosx","tanx","cotx","secx","cscx" };
	/* 打印菜单 */
	printf("1、三角函数中的倒数关系\n");

	/* 选择功能 */
	choice = _getch()-48;
	/* 功能实现 */
	switch (choice)
	{
		//1、三角函数中的倒数关系
	case 1:
		do
		{
			srand(time(NULL));	//time(NULL)函数，获取从1970年1月1日00:00 : 00到现在为止经过了多少秒
								//https://blog.csdn.net/u013745804/article/details/82379266
			question = rand() % 5; 
			//去掉某个问题
			if (question == 2 || question == 3 || question == 1 || question == 4)
			{
				continue;
			}
			printf("          %s的倒数是: ", trigonometric[question]);
			scanf_s("%s", &answer,sizeof(answer));
			/*判断回答是否正确*/
			if (strcmp(answer, trigonometric[5 - question]) == 0)	//回答正确
			{
				printf("          回答正确！\n");
			}
			else									//回答错误
			{
				printf("          %s的倒数是%s\n", trigonometric[question], trigonometric[5 - question]);
			}
			printf("\n");
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