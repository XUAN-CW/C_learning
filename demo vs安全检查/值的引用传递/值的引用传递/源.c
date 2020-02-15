#include <stdio.h>
#include <stdlib.h>
#include "num.h"
int main()
{
	int num = 9;
	change_1(num);
		printf("%d\n", num);
		/*按值传递 
		  给函数传递变元（参数）时，变元（参数）值不会直接传递给函数，
		  而是先制作变元（参数）值的副本，存储在栈上，再使这个副本可用于函数，而不是使用初始值。
		*/

		change_2(&num);
		printf("%d\n", num);
		/*引用传递 
		  值在调用函数时将实际参数的地址传递到函数中，那么在函数中对参数所进行的修改，将影响到实际参数。
		*/

	system("pause");
	return 0;
}
