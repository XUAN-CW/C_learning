#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int main()
{
	int question;
	int choice;					//ѡ����Ҫ�Ĺ���
	char answer[20];			//������Ļش�
	char trigonometric[6][5] = { "sinx","cosx","tanx","cotx","secx","cscx" };
	/* ��ӡ�˵� */
	printf("1�����Ǻ����еĵ�����ϵ\n");

	/* ѡ���� */
	choice = _getch()-48;
	/* ����ʵ�� */
	switch (choice)
	{
		//1�����Ǻ����еĵ�����ϵ
	case 1:
		do
		{
			srand(time(NULL));	//time(NULL)��������ȡ��1970��1��1��00:00 : 00������Ϊֹ�����˶�����
								//https://blog.csdn.net/u013745804/article/details/82379266
			question = rand() % 5; 
			//ȥ��ĳ������
			if (question == 2 || question == 3 || question == 1 || question == 4)
			{
				continue;
			}
			printf("          %s�ĵ�����: ", trigonometric[question]);
			scanf_s("%s", &answer,sizeof(answer));
			/*�жϻش��Ƿ���ȷ*/
			if (strcmp(answer, trigonometric[5 - question]) == 0)	//�ش���ȷ
			{
				printf("          �ش���ȷ��\n");
			}
			else									//�ش����
			{
				printf("          %s�ĵ�����%s\n", trigonometric[question], trigonometric[5 - question]);
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