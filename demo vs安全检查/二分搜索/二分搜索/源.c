#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinarySearch_Count(int searchNum,int nums[], int length);
int BinarySearch_WithoutCount(int searchNum, int nums[], int length);

int main()
{
	int nums[] = { 2,3,5,7,11,12,14,17,20 };
	int searchNum;
	for ( searchNum = 0; searchNum < 25; searchNum++)
	{
		//BinarySearch_Count(searchNum, nums, sizeof(nums) / sizeof(nums[0]) - 1);
		BinarySearch_WithoutCount(searchNum, nums, sizeof(nums) / sizeof(nums[0]) - 1);
	}
	system("pause");
}

int BinarySearch_Count(int searchNum, int nums[], int maxIndex)
{
	int i;
	int left = 0;							//���ҷ�Χ�������
	int right = maxIndex;					//���ҷ�Χ�����Ҷ�
	int mid = (left + right) / 2;			//���ҷ�Χ���м�
	int count = (int)ceil(sqrt(maxIndex));	//���Ҵ���
	int location = -1;						//�������������е�λ��,��һ�������ܵ�ֵ����ʾ�Ҳ���
	for (i = 0; i <= count ; i++)
	{
		//���м�,�ҵ���
		if(searchNum == nums[mid])
		{
			location = mid;
			break;
		}
		//������
		else if (searchNum < nums[mid])
		{
			right = mid;
			mid = (left + right) / 2;
		}
		//���Ұ��
		else if (searchNum > nums[mid])
		{
			left = mid;
			mid = (left + right) / 2;
		}
	}	
	//û���ҵ�
	if (-1 == location)
	{
		printf("%-3d->�� \n", searchNum);
	}
	else
	{
		printf("%-3d->��%-dλ\n", searchNum, location + 1);
	}
	return location;
}

int BinarySearch_WithoutCount(int searchNum, int nums[], int maxIndex)
{
	int left = 0;							//���ҷ�Χ�������
	int right = maxIndex;					//���ҷ�Χ�����Ҷ�
	int mid = (left + right) / 2;			//���ҷ�Χ���м�
	int location = -1;						//�������������е�λ��,��һ�������ܵ�ֵ����ʾ�Ҳ���
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (nums[mid] == searchNum)
		{
			location = mid;
			break;
		}
		if (nums[mid] < searchNum)
		{
			left = mid + 1;
		}
		if (nums[mid] > searchNum)
		{
			right = mid - 1;
		}
	}
	//û���ҵ�
	if (-1 == location)
	{
		printf("%-3d->�� \n", searchNum);
	}
	else
	{
		printf("%-3d->��%-dλ\n", searchNum, location + 1);
	}
	return location;
}