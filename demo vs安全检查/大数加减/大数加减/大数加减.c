#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/** ����ڵ� */
typedef struct _number_node_
{
	char value;
	struct NumberNode *nextWei;		//��һλ��ʮλ��λ��λ
}NumberNode;

/** ��������ṹ */
typedef struct _large_number_
{
	char plusOrMinus;
	NumberNode *theUnit;
	int length;
}LargeNumber;

void InitNum(LargeNumber *largeNumber);

void InputNumber(LargeNumber* num1, LargeNumber* num2);

int main()
{
	/** ��ʼ�����ݣ�Ĭ��Ϊ���� */
	LargeNumber num1, num2;
	InitNum(&num1);
	InitNum(&num2);
	do
	{
		printf("1");
	} while (0);
	/** ���ݲɼ� */

	/** ���ݴ��� */
	


	system("pause");
	return 0;
}

 void InitNum(LargeNumber *largeNumber)
{
	largeNumber->length = 0;
	largeNumber->plusOrMinus = '+';
	largeNumber->theUnit = NULL;
}

void InputNumber(LargeNumber* num1, LargeNumber* num2)
{
	char ch;
	ch = _getch();
	/** �����һ������ */
	if (ch == '+' || ch == '-')
	{
		num1->plusOrMinus = ch;
	}
	do
	{
		ch = _getch();
		if (ch != '-' && ch != '+')//����������ʱ����ѭ��
		{
			break;
		}

	} while (1);	
	
}