#include "InOrderTraverse.h"

/** ���������Ҳ�����и��������������Ρ���-��-�� */
void InOrderTraverse(TreeNode * node) 
{
	if (node) 
	{
		InOrderTraverse(node->left);
		printf("[%d, %s] ", node->data.id, node->data.name);
		InOrderTraverse(node->right);
	}
}
