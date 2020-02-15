#include <stdio.h>
#include <stdlib.h>

void ShowByBytesAndBits(unsigned char* byte, int length)
{
	//小端机的大端表示
	for (int i = length - 1; i >= 0; i--)
	{
		//一个字节八位，由两个十六进制数表示
		//printf("%-10.2x", byte[i]);
	}
	//printf("\n");

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


int main()
{
	float f = -11.75;
	for (int i = 0; i < 5; i++)
	{
		printf("\nf == %f\n", f);
		ShowByBytesAndBits((unsigned char*)(&f), sizeof(f));
		f+=10;
	}
	
	return 0;
}

