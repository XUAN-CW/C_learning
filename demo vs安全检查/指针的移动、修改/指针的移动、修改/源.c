#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char * words = "abcd";
	char chs[50];
	printf("ָ���ƶ�ǰ:%s\n", words);
	words += 1;
	printf("ָ���ƶ���:%s\n", words);
	words = "���";
	printf("ָ���ٴθ�ֵ:%s\n", words);
	scanf_s("%s", chs,50);
	words = chs;
	printf("ָ��Ķ�̬¼��:%s\n", words);





	//char emperorName[50];   //�ʵ۵�����
	//printf("�����뵱ǰ�ǻ��Ļʵ����ţ�");
	//scanf_s("%s", emperorName, 40);   //¼���ַ���ʱ������Ҫ&����
	//printf("�ʵۡ�%s������,�������࣬�����˳���\n", emperorName);




	system("pause");
	return 0;
}



