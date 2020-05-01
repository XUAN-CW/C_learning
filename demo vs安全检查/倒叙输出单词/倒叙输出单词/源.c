#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char ch; // 读入字符
	char chs[100] = {0}; 
	//char chsSpy[10] = {0};
	int i = 0;
	int n;
	while ((ch = getchar()) !='\n')
	{
			chs[i] = ch;
			i++;
	}
	n = i;//记录 i 
	for (i = 0; i < n; i++)
	{
		//chsSpy[i] = chs[n - 1 - i];
		printf("%c", chs[n -1 - i]);
	}
	system("pause");
	return 0;
}

/***
 *while((c=getchar())!='\n')的意思就是录入的字符不是回车键字符就执行循环里面的命令！直到录入回车键字符 就退出循环。
 *先输入数据，之后getchar()的返回值一个接一个赋给c, 然后比较c是不是不等于'回车键，如果不等于回车键就会执行循环。如果等于就会结束
 *这是getchar()啊，作用就是每次从控制台读入一个字符,你输入的时候是一起输入的,但是他放在了那个缓存里,一次读入一个
 ***/
 /*
	 C语言 while((c=getchar())!='\n')与while(c=getchar()!='\n')的区别?
	 因为赋值符的优先级最低，所以前面那个c获取的是输入的字符，后面那个得到的是getchar()!='\n'表达式判断结果。
	 追问：后面那个得到的是getchar()!='\n'表达式判断结果，结果会是什么呢？比如我输入abc<回车>scanf("%s",&s);
	 追答：
	 对于
	 while(c=getchar()!='\n')
	 {
	 //循环体
	 }
	 当你输入的不等于回车时，条件条件成立，执行循环体
	 等于回车，条件不成立，执行循环体后面的语句
 */