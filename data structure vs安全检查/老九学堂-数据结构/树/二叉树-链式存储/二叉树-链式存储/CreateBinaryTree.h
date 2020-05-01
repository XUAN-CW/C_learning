#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include "ElementType.h"
#include <string.h>

/** 初始化空二叉树 */
void InitBinaryTree(BinaryTree * tree);

/** 构造二叉树 - 外部需要事先对结点分配内存
返回值为0时表示创建失败(不创建)*/
int CreateBinaryTree(TreeNode * root);




#endif // BINARYTREE_H_INCLUDED
