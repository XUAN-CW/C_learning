#include <stdio.h>

//http://acm.hdu.edu.cn/showproblem.php?pid=2075

int main()
{
	int t, a, b;
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d%d", &a, &b);
		printf(a % b == 0 ? "YES\n" : "NO\n");
	}
	return 0;
}