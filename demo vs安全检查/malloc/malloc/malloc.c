/**
 * void* malloc(size_t size);
 * ����Ŀռ����ֽ�Ϊ��λ
 * ���ص�������void*����Ҫ����ת�����磺array=(int*)malloc(n*sizeof(int))
 * ����ǵ��ͷ��ڴ棬�磺free(array)
 * array�������׵�ַ�ü���
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int number;
	int * ar;
	int i;
	scanf_s("%d", &number);
	ar = (int*)malloc(number * sizeof(int));
	for ( i = 0; i < number; i++)
	{
		scanf_s("%d", &ar[i]);
	}
	for ( i = 0; i < number; i++)
	{
		printf("%d", ar[i]);
	}
	free(ar);
	system("pause");
	return 0;
}