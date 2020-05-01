#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b);
void(*p)(int*, int*);			//定义指向函数的指针变量p
//void(*p)(int *_a, int*_b);	//形参有没有都无所谓

int main()
{
	int a = 2;
	int b = 5;

	printf("初始值:\t\ta=%d b=%d\n", a, b);

	swap(&a, &b);
	printf("swap交换:\ta=%d b=%d\n", a, b);
	
	p = swap;			//使指针变量p指向函数swap
	(*p)(&a, &b);		//通过指针变量p调用函数swap
	printf("(*p)交换:\ta=%d b=%d\n", a, b);

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