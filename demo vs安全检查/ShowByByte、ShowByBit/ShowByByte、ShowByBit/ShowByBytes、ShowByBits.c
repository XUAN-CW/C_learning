#include <stdio.h>
#include <stdlib.h>

void ShowByBytesAndBits(unsigned char* byte, int length);

int main()
{
	//本机整数以补码表示
	int test = -1;
	ShowByBytesAndBits((unsigned char*)(&test), sizeof(test));

	printf("test == -1 \n%%d打印test == %d\n%%u打印test == %u\n",test,test);
	printf("UINT_MAX == %u\n",UINT_MAX);

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






//布尔型，是说，它的值，仅仅是 0、1。
//它占用的存储空间，应该是一个最小的、基本的分配单元， 即一个字节。布尔型，浪费了其存储单元中的 7 个位
