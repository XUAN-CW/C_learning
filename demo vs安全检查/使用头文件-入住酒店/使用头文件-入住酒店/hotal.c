//对应hotal.h的实现文件

#include <stdio.h>
//包含自定义头文件时，使用双引号
#include "hotal.h"

char hotalNames[4][50] = {
	"贝罗酒店", "香榭丽舍广场酒店", "阿斯图里亚斯特拉奥佩拉酒店", "斯克里布索菲特酒店"
};
char hotalPrice[4][20] = {
	"872.0￥/天","1838.0￥/天","789.0￥/天","1658.0￥/天"
};

int Menu(void)
{
	int choice; //用户的选择
	int result; //用户输入后的结果判断 0 表示非法，1表示真
	int i;
	printf("请选择入住的酒店：\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d、%-25s\t%s\n", i + 1, hotalNames[i],hotalPrice[i]);
	}
	printf("5、退出程序\n");
	printf("请输入您的选择：");
	//当用户输入的值不合法时，要求重新输入
	while ((result = scanf_s("%d", &choice)) != 1 || choice < 1 || choice > 5)
		//输入失败，继续循环
		//输入成功，跳出循环
	{
		if (result != 1)//如果用户输入的不是数字类型
		{
			scanf_s("%*s"); //用来处理非整数的输入。*表示输入项在读入后不赋值给对应的变量
			fflush(stdin);//清空缓冲区
		}
		printf("必须输入1-5之间的整数：");
	}
	//1、用户的选择不能是非数字
	//2、用户必须输入1-5之间
	return choice;
}

//返回用预定的天数
int GetNights(void)
{
	int nights; //用户入住的天数
	int night;//判断是否合法
	printf("先生/女士，请输入要入住的天数：");
	while ((night = scanf_s("%d", &nights)) != 1 || nights < 0)//while (scanf_s("%d", &nights) != 1 || nights < 0) 输入负数会如何？
	{
		if (night != 1 )//(scanf_s("%d", &night) != 1)
		{
			scanf_s("%*s");//取消赋值
			fflush(stdin);//清空缓冲区
		}
		printf("请输入正确的天数，必须是非负整数！\n");
	}
	return nights;//return night;
}

void ShowPrice(int nights, double price)
{
	//总价格=累加前一天的95%
	double total = 0;
	int i;
	for (i = 0; i < nights; i++)
	{
		total += price;
		price = price * DISCOUNT;//0.95
	}
	printf("入住%d天，共花费：￥%.2lf\n", nights, total);
}




