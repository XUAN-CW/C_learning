#include <stdio.h>
#include <stdlib.h>
int main()
{
	//指针加的不是1，是sizeof(指针所指类型)
	char ac[] = { 1,2,3,4,5 };
	char *p_ac = ac;
	printf("p_ac  指向：%p\n", p_ac);
	printf("p_ac+1指向：%p\n", p_ac+1);
	int ai[] = { 1,2,3,4,5 };
	int *p_ai = ai;
	printf("p_ai  指向：%p\n", p_ai);
	printf("p_ai+1指向：%p\n", p_ai + 1);
	printf("\n");

	//指针移动
	int move[] = { 0,1,2,3,4 };
	int *p_move = move;
	*(p_move + 3) += 100;
	printf("*(p_move + 3) = %d\n",*(p_move + 3));
	printf("\n");

	//指针相减得到：地址之差/sizeof(所指类型)
	int text[] = { 1,2,3,4,5,6 };
	int *p_text = text;
	int *p_textEnd = &text[sizeof(text) / sizeof(text[0]) - 1];
	printf("p_text指向   ：%p\n",p_text);
	printf("p_textEnd指向：%p\n", p_textEnd);
	printf("p_textEnd - p_text = %d\n", p_textEnd - p_text);
	printf("\n");

	//*p++与(*p)++
	int array1[] = { 2,4,6,8 };
	int array2[] = { 2,4,6,8 };
	int *p_1 = array1;
	int *p_2 = array2;
	printf("*p_1++  前：p_1指向：%p，值为：%d\n", p_1, *p_1);
	printf("(*p_2)++前：p_2指向：%p，值为：%d\n", p_2, *p_2);
	*p_1++;
	(*p_2)++;
	printf("*p_1++  后：p_1指向：%p，值为：%d\n",p_1,*p_1); 
	printf("(*p_2)++后：p_2指向：%p，值为：%d\n", p_2, *p_2);
	printf("\n");

	system("pause");
	return 0;
}