#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/** 定义节点 */
typedef struct _number_node_
{
	char value;
	struct NumberNode *nextWei;		//下一位，十位百位的位
}NumberNode;

/** 定义大数结构 */
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
	/** 初始化数据，默认为正数 */
	LargeNumber num1, num2;
	InitNum(&num1);
	InitNum(&num2);
	do
	{
		printf("1");
	} while (0);
	/** 数据采集 */

	/** 数据处理 */
	


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
	/** 输入第一个数字 */
	if (ch == '+' || ch == '-')
	{
		num1->plusOrMinus = ch;
	}
	do
	{
		ch = _getch();
		if (ch != '-' && ch != '+')//遇到正负号时跳出循环
		{
			break;
		}

	} while (1);	
	
}