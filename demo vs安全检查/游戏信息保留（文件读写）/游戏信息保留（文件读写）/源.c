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

	//�ı�д��
	ok = fopen_s(&write_file, "snakeAbility.txt", "w");		//�򿪳ɹ�����0,ʧ�ܷ��ط�0
	if (0 == ok)
	{
		fprintf(write_file, "%s", write);
		//fprintf(write_file, "%c", write[0]);
	}
	if (0 == ok)
	{
		fclose(write_file);
	}
	

	//���ı�����������
	ok = fopen_s(&read_file, "snakeAbility.txt", "r");	
	if (ok == 0)
	{
		//�����ȡ�ַ�,ȫ������,�� '\0' ֹͣ
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