#include <stdio.h>
#include <stdlib.h>
/** 字符串逆序 */
void ReverseOrder(char string[],int length);

int main()
{
	char A[100] = { 0 }, B[100] = { 0 }, C[100] = { 0 };
	scanf_s("%s", A, sizeof(A));
	scanf_s("%s", B, sizeof(B));

	/** 为使个位在左边，逆序 */
	ReverseOrder(A, sizeof(A));
	ReverseOrder(B, sizeof(B));
	int currentWei;			//wei—>位，十位百位的位
	/** A * B */
	for (int Awei = 0; '\0' != A[Awei]; Awei++)		
	{
		for (int Bwei = 0; '\0' != B[Bwei]; Bwei++)
		{
			C[Awei + Bwei] += (A[Awei] - '0') * (B[Bwei] - '0');			//ASCII码对应字符—>ASCII码的值
			/** 进位 */
			for (currentWei = Awei + Bwei; C[currentWei] > 9; currentWei++)
			{
				/** 进位 */
				C[currentWei + 1] += C[currentWei] / 10;
				C[currentWei] = C[currentWei] % 10;
			}
		}

	}
	
	int endOfString;		//字符串的终止符，即 '\0'
	for (endOfString = sizeof(A) / sizeof(A[0]) - 1;; endOfString--)
	{
		if (C[endOfString] != 0)
		{
			break;
		}
	}
	/** 从最大一位输出，到个位停止 */
	for (endOfString; endOfString >= 0; endOfString--)
	{
		printf("%d", C[endOfString]);
	}
	
	return 0;
}

void ReverseOrder(char string[],int length)
{
	int endOfString = 0;		//字符串的终止符，即 '\0'
	for ( ;;endOfString++)
	{
		if (string[endOfString] == 0)
		{
			break;
		}
	}
	for (int i = 0; i < (endOfString) / 2; i++)
	{
		char temp = string[i];
		string[i] = string[(endOfString - 1) - i];
		string[(endOfString - 1) - i] = temp;
	}
}