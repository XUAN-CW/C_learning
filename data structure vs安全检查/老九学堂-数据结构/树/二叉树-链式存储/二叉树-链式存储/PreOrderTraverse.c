
#include "PreOrderTraverse.h"

/** ǰ�������Ҳ�����ȸ����������������ǰ�����Ρ����Լ�����-��-�� */
void PreOrderTraverse(TreeNode * node)
{
	//�ȷ��ʸ���㣬Ȼ�������������������������
	if (node)
	{
		printf("[%d, %s] ", node->data.id, node->data.name);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}

