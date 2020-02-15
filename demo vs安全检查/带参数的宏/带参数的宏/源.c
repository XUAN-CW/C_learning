#include <stdio.h>
#include <stdlib.h>

/***** 宏的替换，原封不动！ *****/

#define cube(x) ((x)*(x)*(x))
#define RADTODGE_1(x) (x * 57.29578)
#define RADTODGE_2(x) (x) * 57.29578
#define RADTODGE_3(x) ((x) * 57.29578)
#define MIN(a,b) ((a)>(b)?(b):(a))				//宏可以带多个参数，也可以组合（嵌套）其他的宏
//宏定义千万不要用分号
int main()
{
	int i = 10;

	printf("%d\n\n", cube(5));

	//scanf_s("%d", &i);
	printf("%d\n\n", cube(i));

	//scanf_s("%d", &i);
	printf("%d\n\n", cube(i+2));

	/*** 带参数的宏的原则 ***
	 * 一切都要括号
	 * 整个值要括号
	 * 参数出现的每个地方都要括号
	 */
	printf("%f\n", RADTODGE_1(5 + 2));			//等效于 printf("%f\n", 5+2 * 57.29578);	
	printf("%f\n", 180 / RADTODGE_2(1));		//printf("%f\n", 180 / (1) * 57.29578);
	printf("%f\n\n", 180 / RADTODGE_3(1+1));

	printf("%d\n\n", MIN(1,3));

	system("pause");
	return 0;
}