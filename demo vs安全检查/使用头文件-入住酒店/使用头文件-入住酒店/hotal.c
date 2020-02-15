//��Ӧhotal.h��ʵ���ļ�

#include <stdio.h>
//�����Զ���ͷ�ļ�ʱ��ʹ��˫����
#include "hotal.h"

char hotalNames[4][50] = {
	"���޾Ƶ�", "�������㳡�Ƶ�", "��˹ͼ����˹�����������Ƶ�", "˹���ﲼ�����ؾƵ�"
};
char hotalPrice[4][20] = {
	"872.0��/��","1838.0��/��","789.0��/��","1658.0��/��"
};

int Menu(void)
{
	int choice; //�û���ѡ��
	int result; //�û������Ľ���ж� 0 ��ʾ�Ƿ���1��ʾ��
	int i;
	printf("��ѡ����ס�ľƵ꣺\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d��%-25s\t%s\n", i + 1, hotalNames[i],hotalPrice[i]);
	}
	printf("5���˳�����\n");
	printf("����������ѡ��");
	//���û������ֵ���Ϸ�ʱ��Ҫ����������
	while ((result = scanf_s("%d", &choice)) != 1 || choice < 1 || choice > 5)
		//����ʧ�ܣ�����ѭ��
		//����ɹ�������ѭ��
	{
		if (result != 1)//����û�����Ĳ�����������
		{
			scanf_s("%*s"); //������������������롣*��ʾ�������ڶ���󲻸�ֵ����Ӧ�ı���
			fflush(stdin);//��ջ�����
		}
		printf("��������1-5֮���������");
	}
	//1���û���ѡ�����Ƿ�����
	//2���û���������1-5֮��
	return choice;
}

//������Ԥ��������
int GetNights(void)
{
	int nights; //�û���ס������
	int night;//�ж��Ƿ�Ϸ�
	printf("����/Ůʿ��������Ҫ��ס��������");
	while ((night = scanf_s("%d", &nights)) != 1 || nights < 0)//while (scanf_s("%d", &nights) != 1 || nights < 0) ���븺������Σ�
	{
		if (night != 1 )//(scanf_s("%d", &night) != 1)
		{
			scanf_s("%*s");//ȡ����ֵ
			fflush(stdin);//��ջ�����
		}
		printf("��������ȷ�������������ǷǸ�������\n");
	}
	return nights;//return night;
}

void ShowPrice(int nights, double price)
{
	//�ܼ۸�=�ۼ�ǰһ���95%
	double total = 0;
	int i;
	for (i = 0; i < nights; i++)
	{
		total += price;
		price = price * DISCOUNT;//0.95
	}
	printf("��ס%d�죬�����ѣ���%.2lf\n", nights, total);
}




