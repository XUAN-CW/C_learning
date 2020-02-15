#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *read_file;
	FILE *write_file;
	errno_t ok;
	char ch;
	_Bool read[8] = { 0 };
	_Bool write[8] = { 1,1,0,0,1,1 };

	//文本写入
	ok = fopen_s(&write_file, "bool.txt", "w");		//打开成功返回0,失败返回非0
	if (0 == ok)
	{
		for (int i = 0; i < 8; i++)
		{
			fprintf(write_file, "%d", write[i]);
		}
		
	}
	if (0 == ok)
	{
		fclose(write_file);
	}


	//将文本读入数组中
	ok = fopen_s(&read_file, "bool.txt", "r");
	if (ok == 0)
	{
		//逐个读取字符,全部读完,遇 '\0' 停止
		for (int i = 0; (ch = fgetc(read_file)) != EOF; i++)
		{
			read[i] = ch - '0';
		}
	}
	if (0 == ok)
	{
		fclose(read_file);
	}


	system("pause");
	return 0;
}