#include <stdio.h>
#include <stdlib.h>
//计算圆的面积
double calcCircle(double);//圆的面积肯定涉及小数，用double声明，半径也用double类型		第一个double声明了calcCircle,第二个double声明了半径
double calcRectangle(double, double);//计算矩形的面积	double calcRectangle(double double)会如何？
double calcTriangle(double, double);
int validate(double);//验证输入的double类型数据是否为正数
int main()
{
	double radius;
	double width, height;
	double bottom;
	double s;
	int choice;
	printf("请选择要计算面积的图形；\n");
	printf("1、圆\n");
	printf("2、矩形\n");
	printf("3、三角形\n");
	scanf_s("%d", &choice);//不取址会如何？
	switch (choice)
	{
	case 1:
		printf("圆的半径是：");
		do {
			scanf_s("%lf", &radius);
			if (!validate(radius))
			{
				printf("请输入一个正数：");
			}
		} while (!validate(radius));//满足判断条件时跳出循环
		s = calcCircle(radius);//调用自定义函数calcCircle
		printf("图形的面积是：%.2lf\n", s);
		break;
	case 2:
		printf("矩形的宽和高分别是：");
		do {
			scanf_s("%lf %lf", &width, &height);
			if (!validate(width) || !validate(height))
			{
				printf("请输入一个正数：");
			}
		} while (!validate(width) || !validate(height));//满足判断条件时跳出循环
		s = calcRectangle(width, height);//调用自定义函数calcCircle
		printf("图形的面积是：%.2lf\n", s);
		break;
	case 3:
		printf("三角形的底和高分别是：");
		do {
			scanf_s("%lf %lf", &bottom, &height);
			if (!validate(bottom) || !validate(height))
			{
				printf("请输入一个正数：");
			}
		} while (!validate(bottom) || !validate(height));//满足判断条件时跳出循环
		s = calcTriangle(bottom, height);//调用自定义函数calcCircle
		printf("图形的面积是：%.2lf\n", s);
		break;
	default:
		printf("请输入1-3的数字！\n");
	}
	system("pause");
	return 0;
}

double calcCircle(double radius)
{
	double s = 3.14 * radius*radius;
	return s;
}

int validate(double num)
{
	return num > 0;//如果num>0,会返回一个非零值，表示真	输入-1与1的效果相同，为什么？
}

double calcRectangle(double width, double height)//计算矩形的面积 double calcRectangle(double width,double height);多了个冒号会如何？
{
	return width * height;
}

double calcTriangle(double bottom, double height)
{
	return bottom * height / 2;
}
