#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
	int ch;				/* ����ӡ�ַ���*/
	int rows, cols;		/* ���������� */
	printf("Enter��a��character��and��two��integers:\n");
	while ((ch  = getchar()) != '\n') 
	{
		//scanf_s("%d��%d", &rows, &cols);
		scanf_s("%d", &rows);
		scanf_s("%d", &cols);
		display(ch, rows, cols);
		printf("Enter��another��character��and��two��integers;\n");
		printf("Enter��a��newline��to��quit.\n");
	}
	printf("Bye.\n");
	getchar();
	return 0;
}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row  = 1; row  <= lines; row++)
	{
		for (col  = 1; col  <= width; col++)
			putchar(cr);
		putchar('\n');/* ����һ�в���ʼ�µ�һ�� */
	}
}

/*
	�ó���ʼʱ�������á�������c 2 3�������ӡc�ַ�2��3�С�Ȼ��
	������ʾ�����2�����ݣ���û�����������ݳ�����˳��ˣ�����ʲô��
	�������ǻ��з��ڵ��ң�������������н����� 3 ����Ļ��з���scanf()��
	����������з�������������С��� scanf()��ͬ��getchar()������������
	���������ڽ�����һ�ֵ���ʱ���㻹û���ü������ַ������Ͷ�ȡ�˻���
	����Ȼ���丳��ch����ch�ǻ��з���ʽ��ֹѭ����������
	Ҫ���������⣬����Ҫ����һ�������������һ�����뿪ʼ֮�����
	�л��з���ո����⣬����ó�����getchar()����ʱ������scanf()�׶�
	��ֹ�������á��޸ĺ�İ汾������嵥8.6��ʾ��
*/

