#include <stdio.h>
#include <stdlib.h>
#define CARPET 1000			//��̺��Ŀ
#define INFORMATION 4		//��̺��Ϣ �� [0]-a, [1]-b, [2]-g, [3]-k
#define UNFOUND -1

int main()
{
	long long int carpet[CARPET][INFORMATION] = { 0 };

	/** ��̺��Ŀ���� */
	 int n = 0;
	scanf_s("%d", &n);

	/** �����̺��Ϣ */
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lld%lld%lld%lld", &carpet[i][0], &carpet[i][1], &carpet[i][2], &carpet[i][3]);
		carpet[i][2] += carpet[i][0] - 1;
		carpet[i][3] += carpet[i][1] - 1;
	}

	/** �������µĵ�̺���Ӻ���ǰ�� */
	long long int carpetNumber = UNFOUND;
	long long int scratchX, scratchY;
	scanf_s("%lld%lld", &scratchX, &scratchY);
	for ( int i = n - 1; i >= 0; i--)
	{
		if ((scratchX >= carpet[i][0] && scratchX <= carpet[i][2]) &&((scratchY >= carpet[i][1] && scratchY <= carpet[i][3])))
		{
			carpetNumber = (long long int)i + 1;		//��һ���̺�±�Ϊ 0 
			break;
		}
	}

	/** ������ */
	printf("%lld", carpetNumber);

	return 0;
}
