#include <stdio.h>
#include <stdlib.h>
#include <string.h> //֧���ַ�������
#include <windows.h>
#include <mmsystem.h>
//#define MAX 200   //����MAX��ʾϵͳҪ������ͬѧ����
int main()
{
	int i = 5;
	char names[200][20] = { "����", "����", "��֪����", "��ʩ", "����" };
	for (i; strcmp("q", names[i - 1]) != 0; i++)
		//0-�����ַ�����ȣ�1-ǰһ�����ں�һ����-1-ǰһ��С�ں�һ��
	{
		printf("1��������ͬѧ�����֣�\t\t�����ӹ��ܣ�\n");
		scanf_s("%s", names[i], sizeof(names));
	}
	system("pause");
	return 0;
}