#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x = 1, y = -1;
	int num = 1, nums = 1;
	int array[100][100] = { 0 };
	int n;
	int i = 0;
	printf("�����뷽��Ľ�����");
	scanf_s("%d",&n);
	while  (nums < n+1)
	{
		switch (nums % 2)
		{
			case 1://����

				for (i=0; i < nums; num++, i++)
				{
					y++;//��
					x--;//��
					array[x][y] = num;
		

				}//��¼���
				y++;//����
				break;
			case 0://ż��
				for (i = 0; i < nums; num++,i++)
				{
					array[x][y] = num;
					y--;//��
					x++;//��


				}//��¼���
				x++;//����

				break;
		}
		nums++;
	}
	//�°벿��
	nums -= 2;
	if (nums % 2 == 1)//ȥ����������
	{
		x--;
		y++;
	}
	while (nums > 0)
	{

		switch (nums % 2)
		{
			case 1://����
				for (i = 0; i < nums; num++, i++)
				{
					y++;//��
					x--;//��
					array[x][y] = num;


				}//��¼���
				y++;//right
				break;
			case 0://ż��
				for (i = 0; i < nums; num++, i++)
				{
					y--;//��
					x++;//��
					array[x][y] = num;

				}//��¼���
				x++;//dowm
				break;
		}

		nums--;
	}
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			printf("%d \t", array[x][y]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
