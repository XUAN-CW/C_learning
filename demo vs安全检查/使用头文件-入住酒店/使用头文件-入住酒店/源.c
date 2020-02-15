#include <stdio.h>
#include <stdlib.h>
#include "hotal.h"

extern char hotalNames[4][50];

int main()
{
	int choice; //用户的选择
	int nights; //用户入住的天数
	double totalCost;   //用户支付的总房费
	double currCost;    //用户当前入住酒店的房费单价

	while ((choice = Menu()) != 5)
	{
		switch (choice)
		{
		case 1://用户入住第一家酒店
			currCost = HOTAL1;
			break;
		case 2://用户入住第二家酒店
			currCost = HOTAL2;
			break;
		case 3://用户入住第三家酒店
			currCost = HOTAL3;
			break;
		case 4://用户入住第四家酒店
			currCost = HOTAL4;
			break;
		default:
			currCost = 0;
		}
		//得到用户入住的天数
		nights = GetNights();
		//计算总费用
		ShowPrice(nights, currCost);
	}
	printf("感谢使用本系统，再会！\n");
	return 0;
}
