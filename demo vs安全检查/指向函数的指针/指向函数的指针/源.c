#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b);
void(*p)(int*, int*);			//����ָ������ָ�����p
//void(*p)(int *_a, int*_b);	//�β���û�ж�����ν

int main()
{
	int a = 2;
	int b = 5;

	printf("��ʼֵ:\t\ta=%d b=%d\n", a, b);

	swap(&a, &b);
	printf("swap����:\ta=%d b=%d\n", a, b);
	
	p = swap;			//ʹָ�����pָ����swap
	(*p)(&a, &b);		//ͨ��ָ�����p���ú���swap
	printf("(*p)����:\ta=%d b=%d\n", a, b);

	system("pause");
	return 0;
}


void swap(int *a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}