#include <stdio.h>
#include <stdlib.h>

/***** ����滻��ԭ�ⲻ���� *****/

#define cube(x) ((x)*(x)*(x))
#define RADTODGE_1(x) (x * 57.29578)
#define RADTODGE_2(x) (x) * 57.29578
#define RADTODGE_3(x) ((x) * 57.29578)
#define MIN(a,b) ((a)>(b)?(b):(a))				//����Դ����������Ҳ������ϣ�Ƕ�ף������ĺ�
//�궨��ǧ��Ҫ�÷ֺ�
int main()
{
	int i = 10;

	printf("%d\n\n", cube(5));

	//scanf_s("%d", &i);
	printf("%d\n\n", cube(i));

	//scanf_s("%d", &i);
	printf("%d\n\n", cube(i+2));

	/*** �������ĺ��ԭ�� ***
	 * һ�ж�Ҫ����
	 * ����ֵҪ����
	 * �������ֵ�ÿ���ط���Ҫ����
	 */
	printf("%f\n", RADTODGE_1(5 + 2));			//��Ч�� printf("%f\n", 5+2 * 57.29578);	
	printf("%f\n", 180 / RADTODGE_2(1));		//printf("%f\n", 180 / (1) * 57.29578);
	printf("%f\n\n", 180 / RADTODGE_3(1+1));

	printf("%d\n\n", MIN(1,3));

	system("pause");
	return 0;
}