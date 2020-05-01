#include <stdio.h>
#include <stdlib.h>

void ShowByBytesAndBits(unsigned char* byte, int length);

int main()
{
	/** 扩展 */
	//正数扩展补 0 
	short shortPositiveNumber = 100;
	ShowByBytesAndBits((unsigned char*)(&shortPositiveNumber), sizeof(shortPositiveNumber));
	int intPositiveNumber = shortPositiveNumber;
	ShowByBytesAndBits((unsigned char*)(&intPositiveNumber), sizeof(intPositiveNumber));
	printf("\n");
	//负数扩展补 1 
	short shortNegativeNumber = -100;
	ShowByBytesAndBits((unsigned char*)(&shortNegativeNumber), sizeof(shortNegativeNumber));
	int intNegativeNumber = shortNegativeNumber;
	ShowByBytesAndBits((unsigned char*)(&intNegativeNumber), sizeof(intNegativeNumber));
	printf("\n---------------------------------------------------------\n\n");

	/** 截断-无论正负，由低位读取，舍弃高位 */
	int intValue = -100;
	ShowByBytesAndBits((unsigned char*)(&intValue), sizeof(intValue));
	short shortValue = intValue;
	ShowByBytesAndBits((unsigned char*)(&shortValue), sizeof(shortValue));
	printf("intValue == %d shortValue == %d\n", intValue,shortValue);
	printf("\n");

	intValue = -40000;
	ShowByBytesAndBits((unsigned char*)(&intValue), sizeof(intValue));
	shortValue = intValue;
	ShowByBytesAndBits((unsigned char*)(&shortValue), sizeof(shortValue));
	printf("intValue == %d shortValue == %d\n", intValue, shortValue);
	return 0;
}

void ShowByBytesAndBits(unsigned char* byte, int length)
{
	//小端机的大端表示
	for (int i = length - 1; i >= 0; i--)
	{
		//一个字节八位，由两个十六进制数表示
		printf("%-10.2x", byte[i]);
	}
	printf("\n");
	char translation[16][5] =
	{
		"0000","0001","0010", "0011",
		"0100","0101","0110", "0111",
		"1000","1001","1010", "1011",
		"1100","1101","1110", "1111"
	};
	for (int i = length - 1; i >= 0; i--)
	{
		printf("%s ", translation[byte[i] / 16]);
		printf("%s ", translation[byte[i] % 16]);
	}
	printf("\n");
}

