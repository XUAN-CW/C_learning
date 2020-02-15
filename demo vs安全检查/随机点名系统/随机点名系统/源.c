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
	printf("欢迎使用本系统，请输入您的选择：\n");
	printf("1、增加新的同学\n");
	printf("2、删除某个同学\n");
	printf("3、查找某同学\n");
	printf("4、查看花名册\n");
	printf("5、随机点名\n");
	printf("6、退出本系统\n");
	do {
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		//1.增加前需要判断数组有没有空间
			if (count < MAX)
			{
				//执行添加操作
				printf("请输入同学的名字：");
				scanf_s("%s", names[count], sizeof(names));
				count++;
			}
			else
			{
				printf("同学数目已满，添加失败！\n");
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
