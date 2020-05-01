#include <stdio.h>
#include <stdlib.h>

void ShowByBytesAndBits(unsigned char* byte, int length);

int main()
{
	//���������Բ����ʾ
	int test = -1;
	ShowByBytesAndBits((unsigned char*)(&test), sizeof(test));

	printf("test == -1 \n%%d��ӡtest == %d\n%%u��ӡtest == %u\n",test,test);
	printf("UINT_MAX == %u\n",UINT_MAX);

	return 0;
}

void ShowByBytesAndBits(unsigned char* byte, int length)
{
	//С�˻��Ĵ�˱�ʾ
	for (int i = length - 1; i >= 0; i--)
	{
		//һ���ֽڰ�λ��������ʮ����������ʾ
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






//�����ͣ���˵������ֵ�������� 0��1��
//��ռ�õĴ洢�ռ䣬Ӧ����һ����С�ġ������ķ��䵥Ԫ�� ��һ���ֽڡ������ͣ��˷�����洢��Ԫ�е� 7 ��λ
