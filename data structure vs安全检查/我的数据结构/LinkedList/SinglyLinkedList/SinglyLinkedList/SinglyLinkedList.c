#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

/** ��ʼ������ */
void InitLinkedList(LinkedList *linkedList)
{
	linkedList->length = 0;
	linkedList->firstNode = NULL;
}

/** �������в���Ԫ��,����ʧ�ܷ��� false */
_Bool InserElementToLinkedList(LinkedList *linkedList, Element element, int position)
{
	/** �ж��ܷ���룬���뷶ΧΪ[ 0,linkedList->length + 1 ] */
	if (position >= 1 && position <= linkedList->length + 1)		//���Բ���
	{
		/** �����½�� */
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->data = element;
		newNode->next = NULL;
		/** �ҵ��� position - 1 ��Ԫ�أ���Ҫ����λ�õ�ǰһ��λ�õ�Ԫ�� */
		Node *currentNode = linkedList->firstNode;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		/** ���� */
		if (1 == position)							//��һ������Ҳ�������ǰ�ý�㣬����Դ�
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
		printf("ֻ����[ 1,%d]����룡", linkedList->length + 1);
		return 0;
	}
}

/** ɾ�������еĵ� position ��Ԫ��,ɾ��ʧ�ܷ��� false */
_Bool DeleteEelementOfLinkedList(LinkedList *linkedList, int position)
{
	/** �ж��ܷ�ɾ����ɾ����ΧΪ [ 1,linkedList->length ] */
	if (position >= 1 && position <= linkedList->length)		//����ɾ��
	{
		/** �ҵ��� position - 1 ��Ԫ�أ�����ɾ��Ԫ�ص�ǰһ��Ԫ�� */
		Node *currentNode = linkedList->firstNode;
		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}
		/** ɾ�� */
		if (1 == position)			//��һ������Ҳ�������ǰ�ý�㣬����Դ�
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
		printf("ɾ��ʧ�ܣ�");
		return 0;
	}

}

/** ��ȡ�� position ��Ԫ�ز�������ָ�� */
Element *GetLinkedListElement(LinkedList *linkedList, int position)
{
	/** �ж��Ƿ��ڲ��ҷ�Χ�ڣ����ҷ�ΧΪ[ 1,linkedList->length ] */
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
		//���ڷ�Χ�������������position < 1 , position > linkedList->length , ����Ϊ��
		return NULL;
	}
}

/** ������� */
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

/** �ж������Ƿ�Ϊ�� */
_Bool IsEmptyOfLinkedList(LinkedList *linkedList)
{
	return 0 == linkedList->length ? 1 : 0;
}

/** ��ȡ���ӳ��� */
int GetLinkedListLength(LinkedList *linkedList)
{
	/** ��ͷ��㣬ֱ�ӻ�ȡ */
	return linkedList->length;

	/** ��ͷ��㣬ѭ���������һ����� */
	//Node *currentNode = linkedList->firstNode;
	//int length = 0;
	//for ( ; currentNode ;length++)
	//{
	//	currentNode = currentNode->next;
	//}
	//return length;
}

/** ��ӡ�����е����� */
void PrintLinkedList(LinkedList *linkedList)
{
	Node *currentNode = linkedList->firstNode;
	if (NULL == currentNode)
	{
		printf("����Ϊ�գ�");
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