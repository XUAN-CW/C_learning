#include "PostOrderTraverse.h"

/** 后序遍历：也叫做后根遍历、后序周游。左-右-根 */
void PostOrderTraverse(TreeNode * node)
{
	if (node) 
	{
		PostOrderTraverse(node->left);
		PostOrderTraverse(node->right);
		printf("[%d, %s] ", node->data.id, node->data.name);
	}
}
