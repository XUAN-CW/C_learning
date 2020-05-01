#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 2048
#define N 2048
short a[M][N];
void assign_array_rows()
{
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			a[i][j] = 0;
}
void assign_array_cols()
{
	int i, j;

	for (j = 0; j < N; j++)
		for (i = 0; i < M; i++)
			a[i][j] = 0;
}

int main()
{
	clock_t start, finish;
	double  duration;

	/** assign_array_rows */
	start = clock();
	assign_array_rows();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("行优先用时： %f seconds\n", duration);

	/** assign_array_cols */
	start = clock();
	assign_array_cols();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("列优先用时： %f seconds\n", duration);

	system("pause");
	return 0;
}