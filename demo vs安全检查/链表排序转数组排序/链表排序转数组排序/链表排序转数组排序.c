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
	/*** ��ʼ������ **/
	LinkedList linkedList;
	memset(&linkedList, 0, sizeof(linkedList));

	/*** ���ݲɼ� **/
	int nums;
	printf("���ֵĸ���Ϊ��");
	scanf_s("%d", &nums);
	//���������ֱ�Ӳ��뵽�����У���Ϊ��һ�����
	for (int i = 0; i < nums; i++)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		if (newNode)	//��ֹmallocʧ��
		{
			scanf_s("%d", &(newNode->num));
			newNode->nextNode = linkedList.firstNode;
			linkedList.firstNode = newNode;
			linkedList.length++;
		}
		else			//���ﲻ���ص㣬������������
		{
			printf("�ռ䲻�㣡");
			break;
		}
	}

	if (linkedList.length > 0)	//����Ľ�����������������
	{
		/*** ���������ȶ�̬���� [ָ�����ָ��] ���� **/
		Node** nodeArray = (Node**)malloc(sizeof(Node*) * linkedList.length);
		if (nodeArray)
		{
			/*** ���ָ��ָ���� **/
			Node* currentNode = linkedList.firstNode;
			for (int i = 0; i < linkedList.length; i++)
			{
				nodeArray[i] = currentNode;
				currentNode = currentNode->nextNode;
			}

			/*** ����,ʹ��ð������ **/
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

			/*** ��� **/
			for (int i = 0; i < linkedList.length; i++)
			{
				printf("%d ", nodeArray[i]->num);
			}
		}
		else			//���ﲻ���ص㣬������������
		{
			printf("�ռ䲻�㣡");
		}
	}
	return 0;
}
