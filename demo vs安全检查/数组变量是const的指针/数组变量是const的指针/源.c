#include <stdio.h>
#include <stdlib.h>
int main()
{
	int array[] = { 1,2,3,4,5 };
	int temp;
	int *p_temp = &temp;
	int *p_array = array;
	//int array[] <==> int const *array=... ...
	//�����ֵ���Ըģ������ַ���ܸ�
	array++;

	printf("arrayָ��ĵ�ַ    %p���õ�ַ�е�ֵΪ��%d\n", array,*array);
	p_array++;
	printf("p_arrayָ��ĵ�ַ��%p���õ�ַ�е�ֵΪ��%d\n",p_array, *p_array);

	system("pause");
	return 0;
}