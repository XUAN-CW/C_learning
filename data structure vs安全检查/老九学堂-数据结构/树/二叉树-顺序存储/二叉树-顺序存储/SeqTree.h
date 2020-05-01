#ifndef SEQTREE_H_INCLUDED
#define SEQTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ElementType.h"

/** 初始化空二叉树 */
void InitSeqTree(SeqTree tree);

/** 获取树的根结点元素 */
char GetSeqTreeRoot(SeqTree tree);

/** 获取树的结点总数 */
int GetSeqTreeLength(SeqTree tree);

/** 获取树的深度 */
int GetSeqTreeDepth(SeqTree tree);

/** 创建完全二叉树，i为数组中的下标 */
void CreateSeqTree(SeqTree tree, int i);


#endif // SEQTREE_H_INCLUDED
