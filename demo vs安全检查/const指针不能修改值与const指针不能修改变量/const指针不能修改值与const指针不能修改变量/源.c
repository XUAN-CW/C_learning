#include <stdio.h>
#include <stdlib.h>
int main()
{
	int temp = 2;
	const int *p1 = &temp;	//值	不能被修改
	int const *p2 = &temp;	//值	不能被修改
	int *const p3 = &temp;	//指针	不能被修改
	//判断哪个被const了的标志是const在*前还是在*后

	//*p1 += 1;			// *  优先级高于 += ，先操作指针后 *p1+=1; 
	printf("指针++前：地址：%p\t值：%d\n", p1,*p1);
	*p1++;				// ++ 优先级高于 *  ，先 p1++ 后 *p
	printf("指针++后：地址：%p\t值：%d\n", p1,*p1);
	p1--;
	printf("指针--后：地址：%p\t值：%d\n", p1, *p1);


	system("pause");
	return 0;
}