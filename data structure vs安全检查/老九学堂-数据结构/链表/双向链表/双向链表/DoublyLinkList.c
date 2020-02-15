#include "DoublyLinkList.h"
#include <string.h>

void InsertDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element){
    //�����ս��
    DoublyNode * newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;
    //�ڵ�һ��λ�ò�����
    if(pos == 1)
	{
        //�����һ��λ�ò��Ҳ���ʱ����ĳ���Ϊ0
        if(dlList->length == 0)
		{
            dlList->next = newNode;
            dlList->length++;
            return;
        }
		else
		{
			newNode->next = dlList->next;
			dlList->next = newNode;
			newNode->next->prev = newNode;
			dlList->length++;
			return;
		}
    }
	else
	{
		DoublyNode * currentNode = dlList->next;
		//�����½�����½��Ϊ����λ���� currentNode Ϊ�ڶ�λ
		for (int i = 1; currentNode && i < pos - 1; i++)
		{
			currentNode = currentNode->next;
		}
		if (currentNode)
		{
			newNode->prev = currentNode;
			if (currentNode->next) //��� currentNode �к�̽��
			{
				//������λ�ô���ǰ׺���ָ���½��
				currentNode->next->prev = newNode;
			}
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				dlList->length++;
		}
	}
}

ElementType DeleteDoubyLinkList(DoublyLinkList * dlList, int pos)
{
	DoublyNode * currentNode = dlList->next;
    ElementType deletedElement;
    deletedElement.id = -1;
	strcpy_s(deletedElement.name, sizeof(deletedElement.name), "ɾ��ʧ�ܣ�");
    if(pos == 1)
	{
        if(currentNode)
		{
            deletedElement = currentNode->data;
            dlList->next = currentNode->next;
            if(currentNode->next)
			{
                //����еڶ�����㣬��ô���õڶ����ڵ��ǰ׺���Ϊnull
                currentNode->next->prev = NULL;
            }
            free(currentNode);
            dlList->length--;
        }
    }
	else
	{
		for (int i = 1; currentNode && i < pos; i++) 
		{
			currentNode = currentNode->next;
		}
		if (currentNode) 
		{
			deletedElement = currentNode->data;
			if (currentNode->next) 
			{
				currentNode->next->prev = currentNode->prev;
			}
			currentNode->prev->next = currentNode->next;
			free(currentNode);
			dlList->length--;
		}
	}
    return deletedElement;
}

ElementType GetDoublyLinkListElement(DoublyLinkList * dlList, int pos)
{
    DoublyNode * node = dlList->next;
    for(int i = 1; node && i < pos; i++)
	{
        node = node->next;
    }
    return node->data;
}

DoublyNode * GetDoublyPrveNode(DoublyNode * node)
{
    if(node)
        return node->prev;
    return NULL;
}

void PrintDoublyLinkList(DoublyLinkList * dlList)
{
    DoublyNode * node = dlList->next;
    if(!node || dlList->length == 0)
	{
        printf("����Ϊ�գ�û�����ݿ��Դ�ӡ��\n");
        dlList->length = 0;
        return;
    }
    for(int i = 0; i < dlList->length; i++)
	{
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}










