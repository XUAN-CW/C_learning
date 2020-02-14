
#include "PreOrderTraverse.h"

/** 前序遍历：也叫做先根遍历、先序遍历、前序周游。可以记做根-左-右 */
void PreOrderTraverse(TreeNode * node)
{
	//先访问根结点，然后遍历左子树，最后遍历右子树
	if (node)
	{
		printf("[%d, %s] ", node->data.id, node->data.name);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}

