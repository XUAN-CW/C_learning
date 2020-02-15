/*************************************************************
	date: July 2017
	copyright: Zhu En��ף����
	DO NOT distribute this code.
**************************************************************/
// ���е����Ӵ洢ͷ�ļ�
// ����ѭ���������и���ͷ�ڵ㣬ʹ��β���ָ��
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
