#include "InOrderTraverse.h"

/** 中序遍历：也叫做中根遍历、中序周游。左-根-右 */
void InOrderTraverse(TreeNode * node) 
{
	if (node) 
	{
		InOrderTraverse(node->left);
		printf("[%d, %s] ", node->data.id, node->data.name);
		InOrderTraverse(node->right);
	}
}
