/*************************************************************
	date: July 2017
	copyright: Zhu En（祝恩）
	DO NOT distribute this code.
**************************************************************/
// 队列的链接存储头文件
// 采用循环链表，具有附加头节点，使用尾结点指针
// CLQ_   Circularly Linked Queue
////////////////////////////////////////
#if !defined(LINKED_QUEUE_H_983982)
#define LINKED_QUEUE_H_983982

typedef int T;

typedef struct LNode {
	T data;
	LNode* next;
}LNode;

LNode* CLQ_Create();
void CLQ_Free(LNode* rear);
void CLQ_MakeEmpty(LNode*& rear);
bool CLQ_IsEmpty(LNode* rear);
int CLQ_Length(LNode* rear);
void CLQ_In(LNode*& rear, T x);
bool CLQ_Out(LNode*& rear, T& item);
bool CLQ_Head(LNode* rear, T& item);
void CLQ_Print(LNode* rear);
#endif
//////////////////////////////////////////
