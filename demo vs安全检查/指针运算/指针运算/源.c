#include <stdio.h>
#include <stdlib.h>
int main()
{
	//ָ��ӵĲ���1����sizeof(ָ����ָ����)
	char ac[] = { 1,2,3,4,5 };
	char *p_ac = ac;
	printf("p_ac  ָ��%p\n", p_ac);
	printf("p_ac+1ָ��%p\n", p_ac+1);
	int ai[] = { 1,2,3,4,5 };
	int *p_ai = ai;
	printf("p_ai  ָ��%p\n", p_ai);
	printf("p_ai+1ָ��%p\n", p_ai + 1);
	printf("\n");

	//ָ���ƶ�
	int move[] = { 0,1,2,3,4 };
	int *p_move = move;
	*(p_move + 3) += 100;
	printf("*(p_move + 3) = %d\n",*(p_move + 3));
	printf("\n");

	//ָ������õ�����ַ֮��/sizeof(��ָ����)
	int text[] = { 1,2,3,4,5,6 };
	int *p_text = text;
	int *p_textEnd = &text[sizeof(text) / sizeof(text[0]) - 1];
	printf("p_textָ��   ��%p\n",p_text);
	printf("p_textEndָ��%p\n", p_textEnd);
	printf("p_textEnd - p_text = %d\n", p_textEnd - p_text);
	printf("\n");

	//*p++��(*p)++
	int array1[] = { 2,4,6,8 };
	int array2[] = { 2,4,6,8 };
	int *p_1 = array1;
	int *p_2 = array2;
	printf("*p_1++  ǰ��p_1ָ��%p��ֵΪ��%d\n", p_1, *p_1);
	printf("(*p_2)++ǰ��p_2ָ��%p��ֵΪ��%d\n", p_2, *p_2);
	*p_1++;
	(*p_2)++;
	printf("*p_1++  ��p_1ָ��%p��ֵΪ��%d\n",p_1,*p_1); 
	printf("(*p_2)++��p_2ָ��%p��ֵΪ��%d\n", p_2, *p_2);
	printf("\n");

	system("pause");
	return 0;
}