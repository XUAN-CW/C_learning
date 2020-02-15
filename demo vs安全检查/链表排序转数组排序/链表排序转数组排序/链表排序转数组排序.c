#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int num;
	struct Node* nextNode;
}Node;

typedef struct
{
	int length;
	struct Node* firstNode;
}LinkedList;

int main()
{
	/*** 初始化链表 **/
	LinkedList linkedList;
	memset(&linkedList, 0, sizeof(linkedList));

	/*** 数据采集 **/
	int nums;
	printf("数字的个数为：");
	scanf_s("%d", &nums);
	//输入的数据直接插入到链表中，成为第一个结点
	for (int i = 0; i < nums; i++)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		if (newNode)	//防止malloc失败
		{
			scanf_s("%d", &(newNode->num));
			newNode->nextNode = linkedList.firstNode;
			linkedList.firstNode = newNode;
			linkedList.length++;
		}
		else			//这里不是重点，不做过多讨论
		{
			printf("空间不足！");
			break;
		}
	}

	if (linkedList.length > 0)	//输入的结点数大于零才有意义
	{
		/*** 根据链表长度动态分配 [指向结点的指针] 数组 **/
		Node** nodeArray = (Node**)malloc(sizeof(Node*) * linkedList.length);
		if (nodeArray)
		{
			/*** 结点指针指向结点 **/
			Node* currentNode = linkedList.firstNode;
			for (int i = 0; i < linkedList.length; i++)
			{
				nodeArray[i] = currentNode;
				currentNode = currentNode->nextNode;
			}

			/*** 排序,使用冒泡排序 **/
			for (int i = 0; i < linkedList.length - 1; i++)
			{
				for (int j = 0; j < linkedList.length - 1 - i; j++)
				{
					Node* tempNode;
					if (nodeArray[j]->num > nodeArray[j + 1]->num)
					{
						 tempNode = nodeArray[j]; 
						 nodeArray[j] = nodeArray[j + 1];
						 nodeArray[j + 1] = tempNode;
					}
				}
			}

			/*** 输出 **/
			for (int i = 0; i < linkedList.length; i++)
			{
				printf("%d ", nodeArray[i]->num);
			}
		}
		else			//这里不是重点，不做过多讨论
		{
			printf("空间不足！");
		}
	}
	return 0;
}
