#include "foundation.h"

/*** ����ǰ��ɫ�뱳��ɫ **/
void SetColor(int color)
{
	/*** ����������ɫ **
	 * 0-�� 1-�� 2-�� 3-ǳ�� 4-�� 5-�� 6-�� 7-�� 8-�� 9-����
	 * 10-���� 11-��ǳ��  12-���� 13-���� 14-���� 15-����
	 */
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);
}

/*** �����α�λ�� **/
void SetCurrsorPosition(int x, int y)
{
	//���㿪ʼ������(1,2),�α��ڵڶ��е�����
	COORD currsorPosition = { x,y };
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(std_output_handle, currsorPosition);
}

/*** ���ô����С **/
void SetWindowSize(int width, int height)
{
	SMALL_RECT rectangle = { 0,0,width ,height };
	HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(std_output_handle, TRUE, &rectangle);

}

/*** �ַ�ʵʱ��ȡ **/
char ReadChar()
{
	char readCharacter = NO_OPERATION; // ���ص��ַ�
	if (_kbhit())
	{
		readCharacter = _getch();
		//printf("%d ", readCharacter);
	}
	return readCharacter;
}

/*** �����α� **/
void disableCurrsor()
{
	HANDLE std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}
