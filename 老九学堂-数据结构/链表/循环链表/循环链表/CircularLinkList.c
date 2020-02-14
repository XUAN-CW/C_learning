
#include "CircularLinkList.h"
#include <string.h>

/** ��ѭ�������ָ��λ�ò���Ԫ�� */
void InsertCircularLinkList(CircularLinkList * clList, int position, ElementType element)
{
    //����һ���ս��
    CircularNode * newNode = (CircularNode *)malloc(sizeof(CircularNode));
    newNode->data = element;
    newNode->next = NULL;
    if(position == 1)
	{
        newNode->next = clList->next;
        if(!newNode->next)	//��������������Ϊ0
		{
			
            newNode->next = newNode;
        }
		else				//������Ȳ�Ϊ0����Ҫ�ҵ���������һ����㲢�ı���ָ����
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
	else	//����Ĳ��ǵ�һ�����
	{
		CircularNode * currentNode = clList->next;
		//if(position > clList->length)����ɾ���˵� (position % clList->length) ��Ԫ�أ�
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
			////���Ӧ���Ƕ���ģ���Ч�� newNode->next = currentNode->next;
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
		printf("������Ϊ�գ�û�����ݿ��Դ�ӡ��");
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
	strcpy_s(deletedElement.name, sizeof(deletedElement.name), "ɾ��ʧ�ܣ�");
    if(position == 1)
	{
        CircularNode * currentNode = clList->next;
        if(currentNode)		//ɾ����һ������������н��
		{
			if (currentNode->next == currentNode)	//ɾ����һ�����������ֻ��һ�����
			{
				free(currentNode);
				clList->next = NULL;
				clList->length--;
			}
			else									//ɾ����һ�����������ֹһ�����
			{
				deletedElement = currentNode->data;
				//�ҵ����һ����㣬�ı���ָ�����ָ��
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
		else				//ɾ����һ�����������û�н�� 
		{
			strcpy_s(deletedElement.name, sizeof(deletedElement.name), "������Ϊ�գ�");
		}
	}
	else
	{
		CircularNode * preNode = NULL;
		CircularNode * deletedNode = clList->next;
		//if(position > clList->length)����ɾ���˵� (position % clList->length) ��Ԫ�أ�
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
    //��ʹ��ѭ������i������ѭ������ķ���
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
        printf("������Ϊ�գ�û�����ݿ��Դ�ӡ��");
        return;
    }
    //��¼�³�ʼ�Ľ��ָ��
    CircularNode * origNode = node;
    do{
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }while(node != origNode);
}







