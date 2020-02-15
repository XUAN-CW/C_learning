#include <stdio.h>
#include <stdlib.h>

#define TEST_MAX 10000		//最大文本容量
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
	

	//将文本读入数组中
	ok = fopen_s(&p_f_read,"read.txt", "r");		//打开成功返回0,失败返回非0
	if (ok == 0)
	{
		//逐个读取字符,全部读完
		while ((ch = fgetc(p_f_read)) != EOF)
		{
			text[i] = ch;
			i++;
		}
		text[i] = '\0';
	}

	//处理字符串文本

	//用 LOANER 代替中文,保留英文
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

	////删除 LOANER
	//for (j = 0; text[j] != '\0'; j++)
	//{
	//	if (text[j] == LOANER && text[j] < 0)
	//	{
	//		for (k = j; text[k] != '\0'; k++)
	//		{
	//			text[k] = text[k + 1];
	//		}
	//		j--;		//复位,下一轮 j 与本轮 j 相同,防止多个LOANER导致删除失误
	//	}
	//}
	//printf("%s", text);

	//文本写入
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
