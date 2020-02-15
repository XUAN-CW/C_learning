#include "DoublyLinkList.h"
#include <string.h>

void InsertDoublyLinkList(DoublyLinkList * dlList, int pos, ElementType element){
    //创建空结点
    DoublyNode * newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;
    //在第一个位置插入结点
    if(pos == 1)
	{
        //插入第一个位置并且插入时链表的长度为0
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
		//插入新结点且新结点为第三位，则 currentNode 为第二位
		for (int i = 1; currentNode && i < pos - 1; i++)
		{
			currentNode = currentNode->next;
		}
		if (currentNode)
		{
			newNode->prev = currentNode;
			if (currentNode->next) //如果 currentNode 有后继结点
			{
				//将插入位置处的前缀结点指向新结点
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
	strcpy_s(deletedElement.name, sizeof(deletedElement.name), "删除失败！");
    if(pos == 1)
	{
        if(currentNode)
		{
            deletedElement = currentNode->data;
            dlList->next = currentNode->next;
            if(currentNode->next)
			{
                //如果有第二个结点，那么设置第二个节点的前缀结点为null
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
        printf("链表为空，没有内容可以打印！\n");
        dlList->length = 0;
        return;
    }
    for(int i = 0; i < dlList->length; i++)
	{
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}










