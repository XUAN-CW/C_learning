#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500
int main()
{
	int choice;
	int count = 0;
	char names[500][20] = {'0'};
	count = 0;
	printf("��ӭʹ�ñ�ϵͳ������������ѡ��\n");
	printf("1�������µ�ͬѧ\n");
	printf("2��ɾ��ĳ��ͬѧ\n");
	printf("3������ĳͬѧ\n");
	printf("4���鿴������\n");
	printf("5���������\n");
	printf("6���˳���ϵͳ\n");
	do {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		//1.����ǰ��Ҫ�ж�������û�пռ�
			if (count < MAX)
			{
				//ִ����Ӳ���
				printf("������ͬѧ�����֣�");
				scanf_s("%s", names[count], sizeof(names));
				count++;
			}
			else
			{
				printf("ͬѧ��Ŀ���������ʧ�ܣ�\n");
			}

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}

	} while (choice == 6);
	
	system("pause");
	return 0;
}
