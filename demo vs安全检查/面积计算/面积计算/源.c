#include <stdio.h>
#include <stdlib.h>
//����Բ�����
double calcCircle(double);//Բ������϶��漰С������double�������뾶Ҳ��double����		��һ��double������calcCircle,�ڶ���double�����˰뾶
double calcRectangle(double, double);//������ε����	double calcRectangle(double double)����Σ�
double calcTriangle(double, double);
int validate(double);//��֤�����double���������Ƿ�Ϊ����
int main()
{
	double radius;
	double width, height;
	double bottom;
	double s;
	int choice;
	printf("��ѡ��Ҫ���������ͼ�Σ�\n");
	printf("1��Բ\n");
	printf("2������\n");
	printf("3��������\n");
	scanf_s("%d", &choice);//��ȡַ����Σ�
	switch (choice)
	{
	case 1:
		printf("Բ�İ뾶�ǣ�");
		do {
			scanf_s("%lf", &radius);
			if (!validate(radius))
			{
				printf("������һ��������");
			}
		} while (!validate(radius));//�����ж�����ʱ����ѭ��
		s = calcCircle(radius);//�����Զ��庯��calcCircle
		printf("ͼ�ε�����ǣ�%.2lf\n", s);
		break;
	case 2:
		printf("���εĿ�͸߷ֱ��ǣ�");
		do {
			scanf_s("%lf %lf", &width, &height);
			if (!validate(width) || !validate(height))
			{
				printf("������һ��������");
			}
		} while (!validate(width) || !validate(height));//�����ж�����ʱ����ѭ��
		s = calcRectangle(width, height);//�����Զ��庯��calcCircle
		printf("ͼ�ε�����ǣ�%.2lf\n", s);
		break;
	case 3:
		printf("�����εĵ׺͸߷ֱ��ǣ�");
		do {
			scanf_s("%lf %lf", &bottom, &height);
			if (!validate(bottom) || !validate(height))
			{
				printf("������һ��������");
			}
		} while (!validate(bottom) || !validate(height));//�����ж�����ʱ����ѭ��
		s = calcTriangle(bottom, height);//�����Զ��庯��calcCircle
		printf("ͼ�ε�����ǣ�%.2lf\n", s);
		break;
	default:
		printf("������1-3�����֣�\n");
	}
	system("pause");
	return 0;
}

double calcCircle(double radius)
{
	double s = 3.14 * radius*radius;
	return s;
}

int validate(double num)
{
	return num > 0;//���num>0,�᷵��һ������ֵ����ʾ��	����-1��1��Ч����ͬ��Ϊʲô��
}

double calcRectangle(double width, double height)//������ε���� double calcRectangle(double width,double height);���˸�ð�Ż���Σ�
{
	return width * height;
}

double calcTriangle(double bottom, double height)
{
	return bottom * height / 2;
}
