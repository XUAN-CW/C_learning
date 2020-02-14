#include "PostOrderTraverse.h"

/** ���������Ҳ��������������������Ρ���-��-�� */
void PostOrderTraverse(TreeNode * node)
{
	if (node) 
	{
		PostOrderTraverse(node->left);
		PostOrderTraverse(node->right);
		printf("[%d, %s] ", node->data.id, node->data.name);
	}
}
