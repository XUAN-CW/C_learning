#include "LinkList.h"

void InitLinkList(LinkList * linkList, ElementType * dataArray, int length)
{
	linkList->length = 0;    //容易忽略的地方
	linkList->next = NULL;
    for(int i = 0; i < length; i++)
	{
        InsertLinkList(linkList, i + 1, dataArray[i]);
    }
}

 void InsertLinkList(LinkList * linkList, int position, ElementType insertElement)
 {
     //创建新结点并为数据域赋值
     Node * newNode = (Node *)malloc(sizeof(Node));
	 if (NULL != newNode)
	 {
		 newNode->data = insertElement;
		 
		 /* 插入 */
		 if (position == 1)
		 {
			 newNode->next = linkList->next;
			 linkList->next = newNode;
			 linkList->length++;
		 }
		 else
		 {
			 //找到要插入的结点位置
			 Node* currNode = linkList->next;
			 for (int i = 1; currNode && i < position - 1; i++)
			 {
				 currNode = currNode->next;
			 }
			 //将结点插入并对接前面的结点
			 if (currNode) //插入范围合法
			 {
				 newNode->next = currNode->next;
				 currNode->next = newNode;
				 linkList->length++;
			 }
			 else
			 {
				 printf("只能在1~linkList->length + 1间插入元素!");
			 }
		 }
		 return;
	 }
 }

void PrintLinkList(LinkList * linkList){
    Node * node = linkList->next;
    if(!node)
	{
        printf("链表为空！\n");
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
    ElementType deletedElement;    //被删除的元素
    deletedElement.id = -1;      //赋一个不可能的值，用来判断是否删除成功
	strcpy_s(deletedElement.name,sizeof(deletedElement.name),"删除失败！");
    if(position == 1)
	{
        tempNode = linkList->next;
        if(tempNode)
		{
            deletedElement = tempNode->data;
            linkList->next = tempNode->next;
            free(tempNode);//释放被删除结点的内存 - 容易遗漏
            linkList->length--;
        }
    }
	else
	{
		Node * preNode = NULL; //前缀结点
		tempNode = linkList->next;
		//找到被删除的结点
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
			nextNode = currentNode->next;  //先记录当前结点的下个结点，以便释放当前结点的内存
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







