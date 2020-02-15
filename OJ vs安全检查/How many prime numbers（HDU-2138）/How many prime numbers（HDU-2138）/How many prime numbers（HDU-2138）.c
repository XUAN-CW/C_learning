#include<stdio.h>
#include<math.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2138

int IsPrime(int x)
{
	int range = (int)sqrt(x * 1.0);
	for (int i = 2; i <= range; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	while (~scanf_s("%d", &n))
	{
		int primes = 0, currentNum;
		for (int i = 0; i < n; ++i)
		{
			scanf_s("%d", &currentNum);
			if (currentNum == 2)
			{
				primes++;
			}
			else if (currentNum & 1)
			{
				primes += IsPrime(currentNum);
			}
		}
		printf("%d\n", primes);
	}
	return 0;
}