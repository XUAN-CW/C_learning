#include <stdio.h>
#include <stdlib.h>

void ShowByBytesAndBits(unsigned char* byte, int length)
{
	//С�˻��Ĵ�˱�ʾ
	for (int i = length - 1; i >= 0; i--)
	{
		//һ���ֽڰ�λ��������ʮ����������ʾ
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

