#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define M 45
#define N 45

//建立迷宫 
char maze[M][N] = {
	{"111111111111111111111111111111111111111111111"},
	{"100000001000100000000000001000000000001000001"},
	{"100010101010101000101001101010100111101010101"},
	{"100000000010100010100000001010000000100000001"},
	{"101110011110111110111111101010111110101110001"},
	{"100010000000100010000000001000001000000000101"},
	{"111010111011101011111111111010001011100010101"},
	{"100010000000001000000000001010001000100000001"},
	{"101111111001111110111111101010111110101110011"},
	{"101010000010000000000000101010000000000000001"},
	{"101010101010111010001010101010111110100010101"},
	{"100000000010000000100000101000000000000000001"},
	{"101000100111101000101001101010001010001010001"},
	{"100010000010001000100000101000101000100000001"},
	{"101011111010111010111110101010101111101000101"},
	{"100010001010100000001000100000001000001000001"},
	{"100010101010101110001011111001111010111011101"},
	{"101000101010001000101010000000001000001000001"},
	{"101110101011111010111011111111101010001110111"},
	{"101000001000100000000010000000101010100000001"},
	{"101010001010101110001110101110101011101010001"},
	{"100000000000001000100010000010000000000010001"},
	{"100111111001111010111010100110100110100011111"},
	{"100010001000000010100010100010000000101000001"},
	{"111110101110111110101110101011111111101111101"},
	{"100010000000000010101010001000101000100010001"},
	{"101010100110001010101010111110101010111010111"},
	{"101000000010101000101000000000000000000010001"},
	{"101010001010101011101010001110100010011011101"},
	{"101000001010000000101010100000000010000000001"},
	{"101111101011111001101010111010001110101000111"},
	{"101000000000000000100010001000101000100010101"},
	{"101010100111111110101111101110111011111010101"},
	{"100000001000000000000000001000100010001010001"},
	{"101001101011101111100011111010101111101010101"},
	{"100000100010000010000010000000001000101010001"},
	{"111110111110100110111110111010001010101011101"},
	{"100010001000000010100010000000001010000000001"},
	{"101011101010001011101111101001111010100111101"},
	{"101010001000101000000000100000000010001000001"},
	{"101010111010101010100010111111111111101011101"},
	{"101000000000000000001000000000100010001000001"},
	{"101110011001111000101110001010101010111011101"},
	{"100000000000000000000000000000001000100000001"},
	{"111111111111111111111111111111111111111111111"},
};




typedef struct Node {
	int x;//横坐标 
	int y;//纵坐标 
	int direction;//方向，0到7分别为东、东南、南、... ... 北、东北
	struct Node* next;//指向前一个位置
}Node;

typedef struct Node* pNode;

struct LinkStack {
	pNode top;
};
typedef struct LinkStack* pLinkStack;

//创建一个空栈 
pLinkStack createEmptyLinkStack() {
	pLinkStack linkstack = (pLinkStack)malloc(sizeof(struct LinkStack));
	if (linkstack) {
		linkstack->top = NULL;
	}
	else {
		printf("Out of space!\n");
	}
	return linkstack;
}

//判断一个栈是否为空
int isEmptyLinkStack(pLinkStack linkstack) {
	return (linkstack->top == NULL);
}

//进栈 
void push(pLinkStack linkstack, Node* node) {
	if (node) {
		node->next = linkstack->top;
		linkstack->top = node;
	}
}

//出栈
void pop(pLinkStack linkstack) {
	pNode temp;
	if (isEmptyLinkStack(linkstack)) {
		printf("Empty stack pop.\n");
	}
	else {
		temp = linkstack->top;
		linkstack->top = linkstack->top->next;
		free(temp);
	}
}

Node* CreateNode(int x, int y) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode) {
		memset(newNode, 0, sizeof(Node));//清空结构体
		newNode->direction = 0;//初始方向为东方
		newNode->x = x;
		newNode->y = y;
	}
	return newNode;
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;   //句柄，不会
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标的坐标
	SetConsoleCursorPosition(winHandle, pos);
}

void SetColor(int foreColor, int backColor)
{
	/**
	 * 设置文字颜色
	 * 0-黑 1-蓝 2-绿 3-浅绿 4-红 5-紫 6-黄 7-白 8-灰 9-淡蓝
	 * 10-淡绿 11-淡浅绿  12-淡红 13-淡紫 14-淡黄 15-亮白
	 */
	HANDLE winHandle;   //句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);//https://blog.csdn.net/qq_36771850/article/details/79187836
}

void disableCurrsor()
{
	HANDLE  std_win_handle = 0;
	std_win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	cursor_info.bVisible = FALSE;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(std_win_handle, &cursor_info);
}

Node* CreateNextStepNode(Node* currentNode) {
	Node* nextStep = NULL;
	switch (currentNode->direction)
	{
	case 0:
		nextStep = CreateNode(currentNode->x + 1, currentNode->y + 0);
		break;
	case 1:
		nextStep = CreateNode(currentNode->x + 1, currentNode->y + 1);
		break;
	case 2:
		nextStep = CreateNode(currentNode->x + 0, currentNode->y + 1);
		break;
	case 3:
		nextStep = CreateNode(currentNode->x - 1, currentNode->y + 1);
		break;
	case 4:
		nextStep = CreateNode(currentNode->x - 1, currentNode->y + 0);
		break;
	case 5:
		nextStep = CreateNode(currentNode->x - 1, currentNode->y - 1);
		break;
	case 6:
		nextStep = CreateNode(currentNode->x + 0, currentNode->y - 1);
		break;
	case 7:
		nextStep = CreateNode(currentNode->x + 1, currentNode->y - 1);
		break;
	default:
		break;
	}
	return currentNode ? nextStep : NULL;
}

void PrintStackTop(pLinkStack linkStack) {
	SetPosition(linkStack->top->x * 2, linkStack->top->y);
	switch (linkStack->top->direction)
	{
	case 0:
		printf("→");
		break;
	case 1:
		printf("↘");
		break;
	case 2:
		printf("↓");
		break;
	case 3:
		printf("↙");
		break;
	case 4:
		printf("←");
		break;
	case 5:
		printf("↖");
		break;
	case 6:
		printf("↑");
		break;
	case 7:
		printf("↗");
		break;
	default:
		break;
	}
}

void PrintMaze() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (maze[i][j] == '1') {
				//printf("%-2d",1);
				printf("█");
				//printf("%-3d", 1);
			}
			else if (maze[i][j] == '0')
			{
				//printf("%-2d", 0);
				printf("  ");
			}
			else if (maze[i][j] == '2')
			{
				printf("□");
			}
		}
		printf("\n");
	}
}

void RandomMaze() {
	srand(time(NULL));
	for (int i = 1; i < M - 2; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (rand() % 5 > 3) {
				maze[i][j] = '1';
			}
			else
			{
				maze[i][j] = '0';
			}
		}
	}
}

int main() {
	pLinkStack linkStack = createEmptyLinkStack();
	//RandomMaze();
	Sleep(2000);
	PrintMaze();
	Node* start = CreateNode(0, 1);//创建初始节点,即起点
	maze[start->y][start->x] = '0';
	Node* end = CreateNode(44, 43);//创建终点
	maze[end->y][end->x] = '0';
	SetPosition(start->x * 2, start->y);
	SetColor(4, 15);
	printf("始");
	SetColor(7, 0);
	SetPosition(end->x * 2, end->y);
	SetColor(4, 15);
	printf("终");
	SetColor(7, 0);
	push(linkStack, start);
	disableCurrsor();
	//链栈非空且未到终点
	while (!isEmptyLinkStack(linkStack) && (linkStack->top->x != end->x || linkStack->top->y != end->y))
	{
		SetPosition(start->x * 2, start->y);
		SetColor(4, 15);
		printf("始");
		SetColor(7, 0);
		Sleep(50);
		PrintStackTop(linkStack);
		Node* nextStep = CreateNextStepNode(linkStack->top);
		if (maze[nextStep->y][nextStep->x] == '0') {	//下一步不会碰到墙，行走成功
			maze[nextStep->y][nextStep->x] = '3';		//走过的地方设置为'3'
			push(linkStack, nextStep);	//下一步入栈，成为新的栈顶
		}
		else {		//下一步会碰到墙，行走失败
			linkStack->top->direction++;			//换下一个方向试试
			linkStack->top->direction++;			//有这一句就只能走四个方向，没有能走八个方向
			if (8 == linkStack->top->direction) {	//找遍了所有方向都找不到
				//设置为已经走过
				maze[nextStep->y + 1][nextStep->x - 1] = '2';	//已经走过的设置为'2'
				SetPosition(linkStack->top->x * 2, linkStack->top->y);
				printf("□");
				pop(linkStack);						//回退
			}
			free(nextStep);
		}
	}
	SetPosition(0, M);
	printf("%s", isEmptyLinkStack(linkStack) ? "寻路失败" : "寻路成功");
	return 0;
}

