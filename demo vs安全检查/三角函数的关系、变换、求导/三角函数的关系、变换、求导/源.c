#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int main()
{
	int choice;			//ѡ����Ҫ�Ĺ���
	int triangle;		//���ֵ����Ǻ���
	const char * answer;		//������Ļش�
	const char * rightAnswer;	//��ȷ��
	/* ��ӡ�˵� */
	printf("1�����Ǻ����еĵ�����ϵ");
	/* ѡ���� */
	choice = getch();
	/* ����ʵ�� */
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
			printf("�ĵ�����: ");
			scanf_s("%c", &answer);
			/*�жϻش��Ƿ���ȷ*/
			if (strcmp(answer, rightAnswer) == 0)	//�ش���ȷ
			{
				printf("�ش���ȷ��");
			}
			else									//�ش����
			{
				printf("�ĵ�����%s", rightAnswer);
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