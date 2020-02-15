#ifndef BROTHERTREE_H_INCLUDED
#define BROTHERTREE_H_INCLUDED
#include "CBTreeElement.h"

/** 初始化空树 */
void InitCBTree(CBTree **cbTree);

/** 构造树 */
void CreateCBTree(CBNode **cbNode);

/** 先序遍历树 */
void PreOrderCBTree(CBNode *cbNode);

/** 销毁树 */
void DestroyCBTree(CBTree **cbTree);

/** 中序遍历树 */
void InOrderCBTree(CBNode *cbNode);

/** 后序遍历树 */
void PostOrderCBTree(CBNode *node);

#endif // BROTHERTREE_H_INCLUDED

