#include <stdio.h>
#include <stdlib.h>
#define LOANER ' '

int main()
{
	char Chinese[255] = "���!";		//���۲�,�ڴ˱��뻷����,���ĵ�ֵΪ��
	char English[255]="AZaz!";
	char test[255] = "ɽHˮe��l��l��o";
	int i = 0;
	int j = 0;
	int k = 0;

	//�� LOANER ��������,����Ӣ��
	while (test[i]!='\0')
	{
		if (test[i] < 0)
		{
			test[i] = LOANER;
		}
		i++;
	}
	printf("%s\n", test);

	//ɾ�� LOANER
	for ( j = 0; test[j] != '\0'; j++)
	{
		if (test[j]==LOANER)
		{
			for ( k=j; test[k] != '\0'; k++)
			{
				test[k] = test[k + 1];
			}
			j--;		//��λ,��һ�� j �뱾�� j ��ͬ,��ֹ���LOANER����ɾ��ʧ��
		}
	}
	printf("%s\n", test);




	system("pause");
	return 0;
}
