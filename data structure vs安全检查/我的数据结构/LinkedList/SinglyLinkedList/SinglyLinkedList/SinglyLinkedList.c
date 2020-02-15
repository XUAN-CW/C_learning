#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

/** 初始化链表 */
void InitLinkedList(LinkedList *linkedList)
{
	linkedList->length = 0;
	linkedList->firstNode = NULL;
}

/** 向链表中插入元素,插入失败返回 false */
_Bool InserElementToLinkedList(LinkedList *linkedList, Element element, int position)
{
	/** 判断能否插入，插入范围为[ 0,linkedList->length + 1 ] */
	if (position >= 1 && position <= linkedList->length + 1)		//可以插入
	{
		/** 创建新结点 */
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = element;
		newNode->next = NULL;
		/** 找到第 position - 1 个元素，即要插入位置的前一个位置的元素 */
		Node *currentNode = linkedList->firstNode;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		/** 插入 */
		if (1 == position)							//第一个结点找不到它的前置结点，特殊对待
		{
				newNode->next = linkedList->firstNode;
				linkedList->firstNode = newNode;
		}
		else
		{
			newNode->next = currentNode->next;
			currentNode->next = newNode;
		}
		linkedList->length++;
		return 1;
	}
	else
	{
		printf("只能在[ 1,%d]间插入！", linkedList->length + 1);
		return 0;
	}
}

/** 删除链表中的第 position 个元素,删除失败返回 false */
_Bool DeleteEelementOfLinkedList(LinkedList *linkedList, int position)
{
	/** 判断能否删除，删除范围为 [ 1,linkedList->length ] */
	if (position >= 1 && position <= linkedList->length)		//可以删除
	{
		/** 找到第 position - 1 个元素，即被删除元素的前一个元素 */
		Node *currentNode = linkedList->firstNode;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		/** 删除 */
		if (1 == position)			//第一个结点找不到它的前置结点，特殊对待
		{
			linkedList->firstNode = linkedList->firstNode->next;
			free(currentNode);
		}
		else
		{
			Node *deletedNode = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(deletedNode);
		}
		linkedList->length--;
		return 1;
	}
	else
	{
		printf("删除失败！");
		return 0;
	}

}

/** 获取第 position 个元素并返回其指针 */
Element *GetLinkedListElement(LinkedList *linkedList, int position)
{
	/** 判断是否在查找范围内，查找范围为[ 1,linkedList->length ] */
	if (position >= 1 && position <= linkedList->length)		
	{
		Node *currentNode = linkedList->firstNode;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
			
		}
		return currentNode;
	}
	else
	{
		//不在范围内有三种情况：position < 1 , position > linkedList->length , 链表为空
		return NULL;
	}
}

/** 清空链表 */
void ClearLinkedList(LinkedList *linkedList)
{
	Node *currentNode = linkedList->firstNode;
	Node *nextNodeOfCurrentNode = currentNode->next;
	while (currentNode)
	{
		nextNodeOfCurrentNode = currentNode->next;
		free(currentNode);
		currentNode = nextNodeOfCurrentNode;
	}
	linkedList->firstNode = NULL;
	linkedList->length = 0;
}

/** 判断链表是否为空 */
_Bool IsEmptyOfLinkedList(LinkedList *linkedList)
{
	return 0 == linkedList->length ? 1 : 0;
}

/** 获取链队长度 */
int GetLinkedListLength(LinkedList *linkedList)
{
	/** 有头结点，直接获取 */
	return linkedList->length;

	/** 无头结点，循环数到最后一个结点 */
	//Node *currentNode = linkedList->firstNode;
	//int length = 0;
	//for ( ; currentNode ;length++)
	//{
	//	currentNode = currentNode->next;
	//}
	//return length;
}

/** 打印链表中的内容 */
void PrintLinkedList(LinkedList *linkedList)
{
	Node *currentNode = linkedList->firstNode;
	if (NULL == currentNode)
	{
		printf("链表为空！");
	}
	else
	{
		while(NULL != currentNode)
		{
			printf("%d\t%s\n", currentNode->data.id, currentNode->data.name);
			currentNode = currentNode->next;
		}
	}
}