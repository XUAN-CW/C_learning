#include "LinkList.h"

void InitLinkList(LinkList * linkList, ElementType * dataArray, int length)
{
	linkList->length = 0;    //���׺��Եĵط�
	linkList->next = NULL;
    for(int i = 0; i < length; i++)
	{
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}

 void InsertLinkList(LinkList * linkList, int position, ElementType insertElement)
 {
     //�����½�㲢Ϊ������ֵ
     Node * newNode = (Node *)malloc(sizeof(Node));
	 if (NULL != newNode)
	 {
		 newNode->data = insertElement;
		 
		 /* ���� */
		 if (position == 1)
		 {
			 newNode->next = linkList->next;
			 linkList->next = newNode;
			 linkList->length++;
		 }
		 else
		 {
			 //�ҵ�Ҫ����Ľ��λ��
			 Node* currNode = linkList->next;
			 for (int i = 1; currNode && i < position - 1; i++)
			 {
				 currNode = currNode->next;
			 }
			 //�������벢�Խ�ǰ��Ľ��
			 if (currNode) //���뷶Χ�Ϸ�
			 {
				 newNode->next = currNode->next;
				 currNode->next = newNode;
				 linkList->length++;
			 }
			 else
			 {
				 printf("ֻ����1~linkList->length + 1�����Ԫ��!");
			 }
		 }
		 return;
	 }
 }

void PrintLinkList(LinkList * linkList){
    Node * node = linkList->next;
    if(!node)
	{
        printf("����Ϊ�գ�\n");
        linkList->length = 0;
        return;
    }
    for(int i = 0; i < linkList->length; i++)
	{
        printf("%d\t%s\n", node->data.id, node->data.name);
        node = node->next;
    }
}

ElementType DeleteLinkListElement(LinkList * linkList, int position)
{
	Node * tempNode = NULL;
    ElementType deletedElement;    //��ɾ����Ԫ��
    deletedElement.id = -1;      //��һ�������ܵ�ֵ�������ж��Ƿ�ɾ���ɹ�
	strcpy_s(deletedElement.name,sizeof(deletedElement.name),"ɾ��ʧ�ܣ�");
    if(position == 1)
	{
        tempNode = linkList->next;
        if(tempNode)
		{
            deletedElement = tempNode->data;
            linkList->next = tempNode->next;
            free(tempNode);//�ͷű�ɾ�������ڴ� - ������©
            linkList->length--;
        }
    }
	else
	{
		Node * preNode = NULL; //ǰ׺���
		tempNode = linkList->next;
		//�ҵ���ɾ���Ľ��
		for (int i = 1; tempNode && i < position; i++)
		{
			preNode = tempNode;
			tempNode = tempNode->next;
		}
		if (tempNode)
		{
			deletedElement = tempNode->data;
			preNode->next = tempNode->next;
			free(tempNode);
			linkList->length--;
		}
	}
    return deletedElement;
}

void ClearLinkList(LinkList * linkList){
	if (linkList->next)
	{
		Node* currentNode = linkList->next;
		Node* nextNode;
		while (currentNode)
		{
			nextNode = currentNode->next;  //�ȼ�¼��ǰ�����¸���㣬�Ա��ͷŵ�ǰ�����ڴ�
			free(currentNode);
			currentNode = nextNode;
		}
		linkList->next = NULL;
		linkList->length = 0;
	}
 
}

ElementType GetLinkListElement(LinkList * linkList, int position)
{
    Node * currentNode = linkList->next;
    for(int i = 1; currentNode && i < position; i++)
	{
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

int IsLinkListEmpty(LinkList * linkList)
{
    return linkList->length == 0 ? TRUE : FALSE;
}







