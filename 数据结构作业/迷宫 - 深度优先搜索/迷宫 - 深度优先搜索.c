#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define M 45
#define N 45

//�����Թ� 
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
	int x;//������ 
	int y;//������ 
	int direction;//����0��7�ֱ�Ϊ�������ϡ��ϡ�... ... ��������
	struct Node* next;//ָ��ǰһ��λ��
}Node;

typedef struct Node* pNode;

struct LinkStack {
	pNode top;
};
typedef struct LinkStack* pLinkStack;

//����һ����ջ 
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

//�ж�һ��ջ�Ƿ�Ϊ��
int isEmptyLinkStack(pLinkStack linkstack) {
	return (linkstack->top == NULL);
}

//��ջ 
void push(pLinkStack linkstack, Node* node) {
	if (node) {
		node->next = linkstack->top;
		linkstack->top = node;
	}
}

//��ջ
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
		memset(newNode, 0, sizeof(Node));//��սṹ��
		newNode->direction = 0;//��ʼ����Ϊ����
		newNode->x = x;
		newNode->y = y;
	}
	return newNode;
}

void SetPosition(int x, int y)
{
	HANDLE winHandle;   //���������
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù�������
	SetConsoleCursorPosition(winHandle, pos);
}

void SetColor(int foreColor, int backColor)
{
	/**
	 * ����������ɫ
	 * 0-�� 1-�� 2-�� 3-ǳ�� 4-�� 5-�� 6-�� 7-�� 8-�� 9-����
	 * 10-���� 11-��ǳ��  12-���� 13-���� 14-���� 15-����
	 */
	HANDLE winHandle;   //���
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������ɫ
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
		printf("��");
		break;
	case 1:
		printf("�K");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("�L");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("�I");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("�J");
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
				printf("��");
				//printf("%-3d", 1);
			}
			else if (maze[i][j] == '0')
			{
				//printf("%-2d", 0);
				printf("  ");
			}
			else if (maze[i][j] == '2')
			{
				printf("��");
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
	Node* start = CreateNode(0, 1);//������ʼ�ڵ�,�����
	maze[start->y][start->x] = '0';
	Node* end = CreateNode(44, 43);//�����յ�
	maze[end->y][end->x] = '0';
	SetPosition(start->x * 2, start->y);
	SetColor(4, 15);
	printf("ʼ");
	SetColor(7, 0);
	SetPosition(end->x * 2, end->y);
	SetColor(4, 15);
	printf("��");
	SetColor(7, 0);
	push(linkStack, start);
	disableCurrsor();
	//��ջ�ǿ���δ���յ�
	while (!isEmptyLinkStack(linkStack) && (linkStack->top->x != end->x || linkStack->top->y != end->y))
	{
		SetPosition(start->x * 2, start->y);
		SetColor(4, 15);
		printf("ʼ");
		SetColor(7, 0);
		Sleep(50);
		PrintStackTop(linkStack);
		Node* nextStep = CreateNextStepNode(linkStack->top);
		if (maze[nextStep->y][nextStep->x] == '0') {	//��һ����������ǽ�����߳ɹ�
			maze[nextStep->y][nextStep->x] = '3';		//�߹��ĵط�����Ϊ'3'
			push(linkStack, nextStep);	//��һ����ջ����Ϊ�µ�ջ��
		}
		else {		//��һ��������ǽ������ʧ��
			linkStack->top->direction++;			//����һ����������
			linkStack->top->direction++;			//����һ���ֻ�����ĸ�����û�����߰˸�����
			if (8 == linkStack->top->direction) {	//�ұ������з����Ҳ���
				//����Ϊ�Ѿ��߹�
				maze[nextStep->y + 1][nextStep->x - 1] = '2';	//�Ѿ��߹�������Ϊ'2'
				SetPosition(linkStack->top->x * 2, linkStack->top->y);
				printf("��");
				pop(linkStack);						//����
			}
			free(nextStep);
		}
	}
	SetPosition(0, M);
	printf("%s", isEmptyLinkStack(linkStack) ? "Ѱ·ʧ��" : "Ѱ·�ɹ�");
	return 0;
}

