#include <stdio.h>
#include <stdlib.h>
int main()
{
	int temp = 2;
	const int *p1 = &temp;	//ֵ	���ܱ��޸�
	int const *p2 = &temp;	//ֵ	���ܱ��޸�
	int *const p3 = &temp;	//ָ��	���ܱ��޸�
	//�ж��ĸ���const�˵ı�־��const��*ǰ������*��

	//*p1 += 1;			// *  ���ȼ����� += ���Ȳ���ָ��� *p1+=1; 
	printf("ָ��++ǰ����ַ��%p\tֵ��%d\n", p1,*p1);
	*p1++;				// ++ ���ȼ����� *  ���� p1++ �� *p
	printf("ָ��++�󣺵�ַ��%p\tֵ��%d\n", p1,*p1);
	p1--;
	printf("ָ��--�󣺵�ַ��%p\tֵ��%d\n", p1, *p1);


	system("pause");
	return 0;
}