#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef enum _direction
{
	UP = 72,			// �Ϸ���
	DOWN = 80,			// �·���
	LEFT = 75,			// ����
	RIGHT = 77			// �ҷ���
}Direction;

int main()
{
	char key[8];
	//�����а˸�λ�ã�Ϊʲô���ĸ������������ѭ���ˣ�
	//������ĸ�����ּ���ȷʵ���԰��˸���
	for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
	{
		key[i] = _getch();
	}
	for (int i = 0; i < sizeof(key) / sizeof(key[0]); i++)
	{
		int temp = (char)key[i];
		printf("%d\n", temp);
	}
	system("pause");
	return 0;
}