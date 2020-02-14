
#include "CircularLinkList.h"
#include <string.h>

/** 在循环链表的指定位置插入元素 */
void InsertCircularLinkList(CircularLinkList * clList, int position, ElementType element)
{
    //创建一个空结点
    CircularNode * newNode = (CircularNode *)malloc(sizeof(CircularNode));
    newNode->data = element;
    newNode->next = NULL;
    if(position == 1)
	{
        newNode->next = clList->next;
        if(!newNode->next)	//如果插入的链表长度为0
		{
			
            newNode->next = newNode;
        }
		else				//如果长度不为0，就要找到链表的最后一个结点并改变其指针域
		{
            CircularNode * lastNode = clList->next;
            for(int i = 1; i < clList->length; i++)
			{
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
        }
        clList->next = newNode;
        clList->length++;
	}
	else	//插入的不是第一个结点
	{
		CircularNode * currentNode = clList->next;
		//if(position > clList->length)，则删除了第 (position % clList->length) 个元素！
		for (int i = 1; currentNode && i < position - 1; i++)
		{
			currentNode = currentNode->next;
		}
		if (currentNode)
		{
			newNode->next = currentNode->next;
			currentNode->next = newNode;
			clList->length++;
			//if (position == clList->length)		
			//{
			////这句应该是多余的，等效于 newNode->next = currentNode->next;
			//	newNode->next = clList->next;	
			//}
		}
	}
    
}

void InitCircularLinkList(CircularLinkList * clList, ElementType * dataArray, int length)
{
    for(int i = 0; i < length; i++)
	{
        InsertCircularLinkList(clList, i + 1, dataArray[i]);
    }
}

void PrintCircularLinkList(CircularLinkList * clList) 
{
	if (clList->length == 0 || !clList->next) 
	{
		printf("链表长度为空，没有内容可以打印！");
		clList->length = 0;
		return;
	}
	CircularNode * node = clList->next;
	for (int i = 0; i < clList->length; i++) 
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
}

ElementType DeleteCircularLinkList(CircularLinkList * clList, int position)
{
    ElementType deletedElement;
    deletedElement.id = -1;
	strcpy_s(deletedElement.name, sizeof(deletedElement.name), "删除失败！");
    if(position == 1)
	{
        CircularNode * currentNode = clList->next;
        if(currentNode)		//删除第一个结点且链表有结点
		{
			if (currentNode->next == currentNode)	//删除第一个结点且链表只有一个结点
			{
				free(currentNode);
				clList->next = NULL;
				clList->length--;
			}
			else									//删除第一个结点且链表不止一个结点
			{
				deletedElement = currentNode->data;
				//找到最后一个结点，改变其指针域的指向
				CircularNode * lastNode = clList->next;
				for (int i = 1; i < clList->length; i++)
				{
					lastNode = lastNode->next;
				}
				clList->next = currentNode->next;
				lastNode->next = clList->next;
				free(currentNode);
				clList->length--;
			}
        }
		else				//删除第一个结点且链表没有结点 
		{
			strcpy_s(deletedElement.name, sizeof(deletedElement.name), "该链表为空！");
		}
	}
	else
	{
		CircularNode * preNode = NULL;
		CircularNode * deletedNode = clList->next;
		//if(position > clList->length)，则删除了第 (position % clList->length) 个元素！
		for (int i = 1; deletedNode && i < position; i++)
		{
			preNode = deletedNode;
			deletedNode = deletedNode->next;
		}
		if (deletedNode)
		{
			deletedElement = deletedNode->data;
			preNode->next = deletedNode->next;
			free(deletedNode);
			clList->length--;
		}
	}
    return deletedElement;
}

CircularNode * GetCircularLinkListNode(CircularLinkList * clList, ElementType element)
{
    CircularNode * node = clList->next;
	if (!node)
	{
		return NULL;
	}
    //不使用循环变量i来遍历循环链表的方法
    do{
        if(element.id == node->data.id && strcmp(element.name, node->data.name) == 0)
		{
            return node;
        }
        node = node->next;
    }while(node != clList->next);
    return NULL;
}

void PrintCircularLinkListByNode(CircularLinkList * clList, CircularNode * node)
{
    if(!node || !clList->next)
	{
        printf("链表长度为空，没有内容可以打印！");
        return;
    }
    //记录下初始的结点指针
    CircularNode * origNode = node;
    do{
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }while(node != origNode);
}







