#include <stdio.h>
#include <stdlib.h>
#include "hotal.h"

extern char hotalNames[4][50];

int main()
{
	int choice; //�û���ѡ��
	int nights; //�û���ס������
	double totalCost;   //�û�֧�����ܷ���
	double currCost;    //�û���ǰ��ס�Ƶ�ķ��ѵ���

	while ((choice = Menu()) != 5)
	{
		switch (choice)
		{
		case 1://�û���ס��һ�ҾƵ�
			currCost = HOTAL1;
			break;
		case 2://�û���ס�ڶ��ҾƵ�
			currCost = HOTAL2;
			break;
		case 3://�û���ס�����ҾƵ�
			currCost = HOTAL3;
			break;
		case 4://�û���ס���ļҾƵ�
			currCost = HOTAL4;
			break;
		default:
			currCost = 0;
		}
		//�õ��û���ס������
		nights = GetNights();
		//�����ܷ���
		ShowPrice(nights, currCost);
	}
	printf("��лʹ�ñ�ϵͳ���ٻᣡ\n");
	return 0;
}
