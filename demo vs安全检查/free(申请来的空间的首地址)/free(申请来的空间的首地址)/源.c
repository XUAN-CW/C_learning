/**
 * mallocûfree->��ʱ�������ڴ����½�
 */





#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p1 = NULL;
	p1 = (int*)malloc(100 * sizeof(int));
	p1++;
	//free(p1);		//p1û��ָ��ԭ���������Ŀռ���׵�ַ�������ϵ�

	int i;
	int *p2 = &i;
	//free(p2);		//p2�����������Ŀռ���׵�ַ�������ϵ�

	int *p3 = NULL;
	free(p3);		//����free(NULL)

	int *p4 = NULL;
	p4 = (int*)malloc(1024 * sizeof(int));
	free(p4);
	free(p4);		//free������free�������ϵ�


	system("pause");
	return 0;
}