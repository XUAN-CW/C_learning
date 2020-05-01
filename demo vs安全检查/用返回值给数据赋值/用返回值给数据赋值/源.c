#include <stdio.h>
#include <stdlib.h>
int *text(int *num);
int main()
{
	int nums[] = { 0,0 };
	printf("nums[0]=%d,nums[1]=%d\n", nums[0], nums[1]);
	nums[1] = *text(nums) + 100;
	printf("nums[0]=%d,nums[1]=%d\n",nums[0],nums[1]);
	system("pause");
	return 0;
}
int *text(int *num)
{
	(*num)++;
	return num;
}