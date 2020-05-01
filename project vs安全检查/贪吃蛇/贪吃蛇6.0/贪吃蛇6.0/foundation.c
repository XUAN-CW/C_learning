#include "foundation.h"

/*** 设置前景色与背景色 **/
void SetColor(int color)
{
	/*** 设置文字颜色 **
	 * 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝
	 * 10-淡绿 11-淡浅绿  12-淡红 13-淡紫 14-淡黄 15-亮白
	 */
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}

/*** 设置游标位置 **/
void SetCurrsorPosition(int x, int y)
{
	//从零开始，输入(1,2),游标在第二行第三列
	COORD currsorPosition = { x,y };
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(std_output_handle, currsorPosition);
}

/*** 设置窗体大小 **/
void SetWindowSize(int width, int height)
{
	SMALL_RECT rectangle = { 0,0,width ,height };
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(std_output_handle, TRUE, &rectangle);

}

/*** 字符实时读取 **/
char ReadChar()
{
	char readCharacter = NO_OPERATION; // 返回的字符
	if (_kbhit())
	{
		readCharacter = _getch();
		//printf("%d ", readCharacter);
	}
	return readCharacter;
}

/*** 隐藏游标 **/
void disableCurrsor()
{
	HANDLE std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}
