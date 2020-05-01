#include <stdio.h>
void display(char cr, int lines, int width);
int main(void)
{
	int ch;				/* 待打印字符　*/
	int rows, cols;		/* 行数和列数 */
	printf("Enter　a　character　and　two　integers:\n");
	while ((ch  = getchar()) != '\n') 
	{
		//scanf_s("%d　%d", &rows, &cols);
		scanf_s("%d", &rows);
		scanf_s("%d", &cols);
		display(ch, rows, cols);
		printf("Enter　another　character　and　two　integers;\n");
		printf("Enter　a　newline　to　quit.\n");
	}
	printf("Bye.\n");
	getchar();
	return 0;
}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row  = 1; row  <= lines; row++)
	{
		for (col  = 1; col  <= width; col++)
			putchar(cr);
		putchar('\n');/* 结束一行并开始新的一行 */
	}
}

/*
	该程序开始时运行良好。你输入c 2 3，程序打印c字符2行3列。然后，
	程序提示输入第2组数据，还没等你输入数据程序就退出了！这是什么情
	况？又是换行符在捣乱，这次是输入行中紧跟在 3 后面的换行符。scanf()函
	数把这个换行符留在输入队列中。和 scanf()不同，getchar()不会跳过换行
	符，所以在进入下一轮迭代时，你还没来得及输入字符，它就读取了换行
	符，然后将其赋给ch。而ch是换行符正式终止循环的条件。
	要解决这个问题，程序要跳过一轮输入结束与下一轮输入开始之间的所
	有换行符或空格。另外，如果该程序不在getchar()测试时，而在scanf()阶段
	终止程序会更好。修改后的版本如程序清单8.6所示。
*/

