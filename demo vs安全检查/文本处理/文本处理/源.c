#include <stdio.h>
#include <stdlib.h>

#define TEST_MAX 10000		//����ı�����
#define LOANER '^'

int main()
{

	FILE *p_f_read;
	FILE *p_f_write;
	errno_t ok;
	int i = 0;
	int j = 0;
	int k = 0;
	char ch;
	char text[TEST_MAX] = { 0 };
	

	//���ı�����������
	ok = fopen_s(&p_f_read,"read.txt", "r");		//�򿪳ɹ�����0,ʧ�ܷ��ط�0
	if (ok == 0)
	{
		//�����ȡ�ַ�,ȫ������
		while ((ch = fgetc(p_f_read)) != EOF)
		{
			text[i] = ch;
			i++;
		}
		text[i] = '\0';
	}

	//�����ַ����ı�

	//�� LOANER ��������,����Ӣ��
	for ( i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '\n')
		{
			text[i] == 120;
			for (int j = i; text[j] != '\n'; j++)
			{
				text[j] = text[j +1];
			}

		}
	}

	////ɾ�� LOANER
	//for (j = 0; text[j] != '\0'; j++)
	//{
	//	if (text[j] == LOANER && text[j] < 0)
	//	{
	//		for (k = j; text[k] != '\0'; k++)
	//		{
	//			text[k] = text[k + 1];
	//		}
	//		j--;		//��λ,��һ�� j �뱾�� j ��ͬ,��ֹ���LOANER����ɾ��ʧ��
	//	}
	//}
	//printf("%s", text);

	//�ı�д��
	ok = fopen_s(&p_f_write,"write.txt", "w");
	if (ok == 0)
	{
		fprintf(p_f_write, text);
	}

	fclose(p_f_read);
	fclose(p_f_write);

	system("pause");
    return 0;
}
