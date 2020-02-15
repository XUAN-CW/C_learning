#pragma once

#define NAME 30

/** 定义数据元素 */
typedef struct _element_
{
	int id;
	char name[NAME];
}Element;

/** 定义链表的结点 */
typedef struct Node				//_node_ 代替 Node 会出现类型不兼容
{
	Element data;				//数据域
	struct Node *next;			//指针域
}Node;

/** 定义头结点 */
typedef struct _linked_list_
{
	Node *firstNode;			//首元结点
	int length;					//链表长度
}LinkedList;



/** 初始化链表 */
void InitLinkedList(LinkedList *linkedList);

/** 向链表中插入元素,插入失败返回 false */
_Bool InserElementToLinkedList(LinkedList *linkedList, Element element, int position);

/** 删除链表中的第 position 个元素,删除失败返回 false */
_Bool DeleteEelementOfLinkedList(LinkedList *linkedList, int position);

/** 获取第 position 个元素并返回其指针 */
Element *GetLinkedListElement(LinkedList *linkedList, int position);

/** 清空链表 */
void ClearLinkedList(LinkedList *linkedList);

/** 判断链表是否为空 */
_Bool IsEmptyOfLinkedList(LinkedList *linkedList);

/** 获取链队长度 */
int GetLinkedListLength(LinkedList *linkedList);

/** 打印链表中的内容 */
void PrintLinkedList(LinkedList *linkedList);