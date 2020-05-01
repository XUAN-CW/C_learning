#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *read_file;
	FILE *write_file;
	errno_t ok;
	int i = 0;
	char ch;
	char read[8] = { 0 };
	char write[8] = {1,0,1,0,1};

	//文本写入
	ok = fopen_s(&write_file, "snakeAbility.txt", "w");		//打开成功返回0,失败返回非0
	if (0 == ok)
	{
		fprintf(write_file, "%s", write);
		//fprintf(write_file, "%c", write[0]);
	}
	if (0 == ok)
	{
		fclose(write_file);
	}
	

	//将文本读入数组中
	ok = fopen_s(&read_file, "snakeAbility.txt", "r");	
	if (ok == 0)
	{
		//逐个读取字符,全部读完,遇 '\0' 停止
		while ((ch = fgetc(read_file)) != EOF)
		{
			read[i] = ch;
			i++;
		}

		//if ((ch = fgetc(read_file)) != EOF)
		//{
		//	read[i] = ch;
		//	i++;
		//}
		//if ((ch = fgetc(read_file)) != EOF)
		//{
		//	read[i] = ch;
		//	i++;
		//}

	}

	printf("%s\n", read);
	if (0 == ok)
	{
		fclose(read_file);
	}


	system("pause");
	return 0;
}