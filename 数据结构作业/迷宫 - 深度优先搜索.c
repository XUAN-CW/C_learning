#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define ROW 45
#define COLUMN 45

char maze[ROW][COLUMN] = {
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
	int row;
	int column;
	struct Node* father;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

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

Node* CreateNode(int row, int column, Node* father) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode) {
		memset(newNode, 0, sizeof(Node));
		newNode->row = row;
		newNode->column = column;
		newNode->father = father;
	}
}

Queue* CreateQueue() 
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue)
	{
		memset(queue, 0, sizeof(Queue));
	}
}

bool isEmptyQueue(Queue*queue)
{
	return queue->rear == NULL ? true : false;
}

void Enqueue(Queue* queue, Node* node)
{
	if (isEmptyQueue(queue))
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
		
	}

	maze[queue->rear->row][queue->rear->column] = '2';
	//��ӣ������õ�
	SetPosition(queue->rear->column * 2,queue->rear->row );
	SetColor(7, 3);
	printf("  ");
	SetColor(7, 0);
}

Node* Dequeue(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		return NULL;
	}
	else
	{
		//��ӡ��ͷԪ�أ���ͷ
		SetPosition(queue->front->column * 2,queue->front->row);
		//SetColor(7, 0);
		//printf("��");
		printf("  ");
		//SetColor(4, 15);

		//����
		Node* dequeueNode = queue->front;
		queue->front = queue->front->next;
		if (NULL == queue->front)	//ֻ��һ��Ԫ�أ����Ӻ��βӦΪ NULL
		{
			queue->rear = NULL;
		}
		return dequeueNode;
	}
}

void PrintMaze() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
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
	for (int i = 1; i < ROW - 2; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
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

void printNode(Node* node,char str[]) 
{
	SetPosition(node->column * 2, node->row);
	SetColor(4, 15);
	printf("%s",str);
	SetColor(7, 0);
}



int main()
{
	//RandomMaze();
	PrintMaze();
	disableCurrsor();
	//Queue* queue = CreateQueue();
	//printf("%d", isEmptyQueue(queue));
	//Node *node1 = CreateNode(1, 1, NULL);
	//Node* node2 = CreateNode(2, 2, NULL);
	//Enqueue(queue, node1);
	//Enqueue(queue, node2);
	//Dequeue(queue);
	//Dequeue(queue);

	/** ��ʼ������������յ㡢������ */
	Node* start = CreateNode(1, 1, NULL);
	Node* end = CreateNode(43, 0, NULL);
	maze[start->row][start->column] = '0';
	maze[end->row][end->column] = '0';
	Queue* queue = CreateQueue();
	Enqueue(queue, start);
	Sleep(1000);
	while (!isEmptyQueue(queue))//���зǿ�
	{
		Sleep(2);
		disableCurrsor();
		Node* head = Dequeue(queue);
		if ('0' == maze[head->row + 0][head->column + 1])	//�����򶫷���һ��
		{
			maze[head->row + 0][head->column + 1] = '2';//����Ϊ'2'��ʾ�߹���
			Node* moveDirection = CreateNode(head->row + 0, head->column + 1, head);
			Enqueue(queue, moveDirection);
			//�����յ㣬����ѭ��		row	5	int

			if (moveDirection->row == end->row && moveDirection->column == end->column)
				break;
		}
		//if ('0' == maze[head->row + 1][head->column + 1])	//�������Ϸ���һ��
		//{
		//	maze[head->row + 1][head->column + 1] = '2';//����Ϊ'2'��ʾ�߹���
		//	Node* moveDirection = CreateNode(head->row + 1, head->column + 1, head);
		//	Enqueue(queue, moveDirection);
		//	//�����յ㣬����ѭ��
		//	if (moveDirection->row == end->row && moveDirection->column == end->column)
		//		break;
		//}
		if ('0' == maze[head->row + 1][head->column + 0])	//�������Ϸ���һ��
		{
			maze[head->row + 1][head->column + 0] = '2';//����Ϊ'2'��ʾ�߹���
			Node* moveDirection = CreateNode(head->row + 1, head->column + 0, head);
			Enqueue(queue, moveDirection);
			//�����յ㣬����ѭ��
			if (moveDirection->row == end->row && moveDirection->column == end->column)
				break;
		}
		//if ('0' == maze[head->row + 1][head->column  -1])	//���������Ϸ���һ��
		//{
		//	maze[head->row + 1][head->column  -1] = '2';//����Ϊ'2'��ʾ�߹���
		//	Node* moveDirection = CreateNode(head->row + 1, head->column - 1, head);
		//	Enqueue(queue, moveDirection);
		//	//�����յ㣬����ѭ��
		//	if (moveDirection->row == end->row && moveDirection->column == end->column)
		//		break;
		//}
		if ('0' == maze[head->row + 0][head->column - 1])	//������������һ��
		{
			maze[head->row + 0][head->column - 1] = '2';//����Ϊ'2'��ʾ�߹���
			Node* moveDirection = CreateNode(head->row + 0, head->column - 1, head);
			Enqueue(queue, moveDirection);
			//�����յ㣬����ѭ��
			if (moveDirection->row == end->row && moveDirection->column == end->column)
				break;
		}
		//if ('0' == maze[head->row - 1][head->column - 1])	//��������������һ��
		//{
		//	maze[head->row - 1][head->column - 1] = '2';//����Ϊ'2'��ʾ�߹���
		//	Node* moveDirection = CreateNode(head->row - 1, head->column - 1, head);
		//	Enqueue(queue, moveDirection);
		//	//�����յ㣬����ѭ��
		//	if (moveDirection->row == end->row && moveDirection->column == end->column)
		//		break;
		//}
		if ('0' == maze[head->row - 1][head->column + 0])	//�����򱱷���һ��
		{
			maze[head->row - 1][head->column + 0] = '2';//����Ϊ'2'��ʾ�߹���
			Node* moveDirection = CreateNode(head->row - 1, head->column + 0, head);
			Enqueue(queue, moveDirection);
			//�����յ㣬����ѭ��
			if (moveDirection->row == end->row && moveDirection->column == end->column)
				break;
		}
		//if ('0' == maze[head->row - 1][head->column + 1])	//�����򶫱�����һ��
		//{
		//	maze[head->row - 1][head->column + 1] = '2';//����Ϊ'2'��ʾ�߹���
		//	Node* moveDirection = CreateNode(head->row - 1, head->column + 1, head);
		//	Enqueue(queue, moveDirection);
		//	//�����յ㣬����ѭ��
		//	if (moveDirection->row == end->row && moveDirection->column == end->column)
		//		break;
		//}


		printNode(start, "ʼ");
		printNode(end, "��");
	}



	//���Ѱ·�Ĳ���
	for ( ; queue->front!=queue->rear; )
	{
		printNode(start, "ʼ");
		printNode(end, "��");
		Sleep(20);
		Dequeue(queue);
	}

	for (Node* temp = queue->rear; temp; temp = temp->father) {
		
		Sleep(50);
		SetPosition(temp->column * 2, temp->row);
		SetColor(15, 4);
		printf("·");
		printNode(start, "ʼ");
		printNode(end, "��");
	}

	

	SetPosition(0, ROW);
	SetColor(7, 0);
	printf("%s", isEmptyQueue(queue) ? "Ѱ·ʧ��" : "Ѱ·�ɹ�");
	return 0;
}