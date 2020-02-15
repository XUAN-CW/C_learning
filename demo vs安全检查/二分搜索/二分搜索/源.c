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
	int left = 0;							//查找范围的最左端
	int right = maxIndex;					//查找范围的最右端
	int mid = (left + right) / 2;			//查找范围的中间
	int count = (int)ceil(sqrt(maxIndex));	//查找次数
	int location = -1;						//该数字在数组中的位置,赋一个不可能的值，表示找不到
	for (i = 0; i <= count ; i++)
	{
		//在中间,找到了
		if(searchNum == nums[mid])
		{
			location = mid;
			break;
		}
		//在左半段
		else if (searchNum < nums[mid])
		{
			right = mid;
			mid = (left + right) / 2;
		}
		//在右半段
		else if (searchNum > nums[mid])
		{
			left = mid;
			mid = (left + right) / 2;
		}
	}	
	//没有找到
	if (-1 == location)
	{
		printf("%-3d->无 \n", searchNum);
	}
	else
	{
		printf("%-3d->第%-d位\n", searchNum, location + 1);
	}
	return location;
}

int BinarySearch_WithoutCount(int searchNum, int nums[], int maxIndex)
{
	int left = 0;							//查找范围的最左端
	int right = maxIndex;					//查找范围的最右端
	int mid = (left + right) / 2;			//查找范围的中间
	int location = -1;						//该数字在数组中的位置,赋一个不可能的值，表示找不到
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
	//没有找到
	if (-1 == location)
	{
		printf("%-3d->无 \n", searchNum);
	}
	else
	{
		printf("%-3d->第%-d位\n", searchNum, location + 1);
	}
	return location;
}