#include <stdio.h>
#include <stdlib.h>
#include <string.h> //支持字符串操作

#include <windows.h>
#include <mmsystem.h>
#include "fei.h"



#define MAX 6   //常量MAX表示系统要求的最大妃子数量
int main()
{
	//使用字符数组表示字符串
	int i, j, temp;            //循环变量和临时整型变量
	int count = 5;          //当前未打入冷宫的嫔妃个数
	int choice;             //皇帝的选择1-4之间
	int searchIndex = -1;   //用来存放查找到元素的下标
	char emperorName[50];   //皇帝的名号
	char tempName[20];      //用来存放临时字符串的字符数组
	char names[MAX][20] = { "貂蝉", "杨玉环", "不知火舞", "西施", "柳岩" };
	//嫔妃的级别数组
	char levelNames[][10] = { "贵人", "嫔妃", "贵妃", "皇贵妃", "皇后" };
	//用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
	int levels[MAX] = { 1, 1, 0, 0, 4, -9999 };
	//loves数组中的每个元素对应每个妃子的好感度，初始情况，每个人的好感度都为100
	int loves[MAX] = { 100, 100, 100, 100, 100, -9999 };
	printf("\n***********************************************\n");
	printf("测试代码：查看当前嫔妃的状态\n");
	printf("%-12s级别\t好感度\n", "姓名");
	for (i = 0; i < count; i++)
	{
		printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
	}
	printf("***********************************************\n");


	printf("请输入当前登基的皇帝名号：");
	scanf_s("%s", emperorName,40);   //录入字符串时，不需要&符号



	printf("皇帝《%s》驾临,有事上奏，无事退朝！\n", emperorName);
	printf("1、皇帝下旨选妃：\t\t（增加功能）\n");
	printf("2、翻牌宠幸：\t\t（修改状态功能）\n");
	printf("3、打入冷宫！\t\t（删除功能）\n");
	printf("4、单独召见爱妃去小树林做纯洁的事。\n");
	printf("陛下请选择：");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1://皇帝下旨选妃：\t\t（增加功能）

		//1.增加前需要判断数组有没有空间
		//2.增加数组元素（names、loves、levels）
		if (count < MAX)//如果当前的妃子数量小于系统最大值
		{
			//执行添加操作
			printf("请输入娘娘的名讳：");
			scanf_s("%s", names[count],sizeof(names));
			//将第count个元素的状态初始化
			levels[count] = 0;  //级别初始为0
			loves[count] = 100; //好感度初始为100
			count++;            //添加完元素后，记得增加计数器
		}
		else
		{
			printf("陛下，要注意龙体啊，后宫已经人满为患！\n添加失败！\n");
		}

		break;
	case 2://翻牌宠幸：\t\t（修改状态功能）
		//1.找到要宠幸妃子的下标
		//2.修改这个妃子的状态 好感度+10， 级别升1级，如果最高级就不再升级
		//3.修改其他妃子的状态 由于羡慕嫉妒恨，其他妃子好感度-10
		//需要解决的bug：未支持姓名不存在的情况，请自行脑补完成
		printf("陛下，请输入要今天翻牌娘娘的名讳：");
		scanf_s("%s", tempName,50);
		//字符串的查找strcmp，需要引入<string.h>
		//strcmp(tempName, "abc")   0-两个字符串相等；1-前一个大于后一个；-1-前一个小于后一个
		for (i = 0; i < count; i++)
		{
			if (strcmp(tempName, names[i]) == 0)//如果输入的姓名刚好等于数组中的某个姓名
			{
				loves[i] += 10;
				//级别要注意，不能超过5级（0-4之间）
				levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;
			}
			else
			{
				loves[i] -= 10;
			}
		}
		break;
	case 3:
		printf("3、打入冷宫！\t\t（删除功能）\n");
		//1.查找
		//2.后面一个赋给前面一个元素
		//3.总数--
		//4.修改其他妃子的状态，好感度-20
		printf("陛下，请输入要打入冷宫的姓名：");
		scanf_s("%s", tempName,sizeof(tempName));
		//循环查找
		for (i = 0; i < count; i++)
		{
			if (strcmp(tempName, names[i]) == 0)//比较字符串是否相等
			{
				//记录下要查找的下标
				searchIndex = i;
				break;
			}
		}
		if (-1 == searchIndex)//如果searchIndex的值为初值-1，表示没有找到
		{
			printf("虚惊一场，无人打入冷宫，该吃吃该喝喝！\n");
		}
		else
		{
			for (i = searchIndex; i < count - 1; i++)
			{
				//names[i] = names[i + 1]; 因为是字符数组，C语言中不支持数组的直接赋值
				//我们需要使用strcpy函数实现数组的赋值，后续课程会详细讲解，这里只需要了解是什么功能即可
				strcpy_s(names[i], names[i + 1]);
				loves[i] = loves[i + 1];
				levels[i] = levels[i + 1];
			}
			count--;
		}
		break;
	case 4://单独召见爱妃去小树林做纯洁的事
		//1.查找
		//2.增加好感度即可
		//3.可以使用数组设计诗歌，使用随机数字的方式，表现皇帝的文采

		break;
	default:
		printf("君无戏言，陛下请再次确认！\n");
	}
	//最后打印所有妃子状态前，以级别进行排序，使用冒泡排序
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (levels[j] < levels[j + 1])
			{
				//需要交换姓名、级别和好感度
				temp = levels[j];
				levels[j] = levels[j + 1];
				levels[j + 1] = temp;
				temp = loves[j];
				loves[j] = loves[j + 1];
				loves[j + 1] = temp;
				//注意字符串的交换
				strcpy_s(tempName, names[j]);
				strcpy_s(names[j], names[j + 1]);
				strcpy_s(names[j + 1], tempName);
			}
		}
	}

	
		printf("\n***********************************************\n");
		printf("测试代码：查看当前嫔妃的状态\n");
		printf("%-12s级别\t好感度\n", "姓名");
		for(i = 0; i < count; i++)
		{
			printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
		}
		printf("***********************************************\n");
	
	system("pause");
	return 0;
}
