#ifndef BROTHERTREE_H_INCLUDED
#define BROTHERTREE_H_INCLUDED
#include "CBTreeElement.h"

/** ��ʼ������ */
void InitCBTree(CBTree **cbTree);

/** ������ */
void CreateCBTree(CBNode **cbNode);

/** ��������� */
void PreOrderCBTree(CBNode *cbNode);

/** ������ */
void DestroyCBTree(CBTree **cbTree);

/** ��������� */
void InOrderCBTree(CBNode *cbNode);

/** ��������� */
void PostOrderCBTree(CBNode *node);

#endif // BROTHERTREE_H_INCLUDED

