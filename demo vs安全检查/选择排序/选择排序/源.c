#include <stdio.h>
#include <stdlib.h>
//�ҳ���������������±�
int NumsMax_Index(int nums[],int length);
int main()
{
	int nums[] = { 15,24,58,78,36,48,36,89,65,25,14 };
	int i;
	int length = sizeof(nums) / sizeof(nums[0]) ;			//���鳤��
	int maxIndex;											//������������е��±�
	int temp;
	for  (i = 0; i < sizeof(nums)/sizeof(nums[0]); i++,length--)
	{
		//�õ�������������е��±�
		maxIndex = NumsMax_Index(nums, length);		
		//����
		temp = nums[maxIndex];
		nums[maxIndex] = nums[length - 1];
		nums[length - 1] = temp;
	}
	for ( i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	system("pause");
	return 0;
}

int NumsMax_Index(int nums[], int length)
{
	int i;
	int maxIndex = 0;
	for (i = 0; i < length; i++)
	{
		if (nums[i] > nums[maxIndex])
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}
